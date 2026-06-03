#include "img.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lvgl.h"

typedef struct {
    const char *name;
    const char *file;
    uint8_t *buf;
    lv_img_dsc_t dsc;
    bool loaded;
} preload_img_t;

static preload_img_t s_imgs[] = {
    { .name = "4.jpg" },
};

#define IMG_COUNT  (sizeof(s_imgs) / sizeof(s_imgs[0]))



/* 单片机上资源的真实文件路径前缀。
 * 注意：generated/setup_scr_screen.c 里 GUI-Guider 写的是 PC 端盘符路径
 *   "S:/sdfile/EXT_RESERVED/uipackres/ui//1.jpg"
 * 那是 GUI-Guider 工程约定，板子上读不到；单片机真正能读 SD 的是下面这个 mnt/ 路径。
 * 预解码(preload_one)和兜底慢路径(custom_img_set_src)都用它去真正读 SD。
 * 拦截解码器只按文件名匹配，所以 generated 设的 S:/ 路径也能命中 DDR，两边不冲突。 */
#define CUSTOM_IMG_PACK_PAHT "mnt/sdfile/EXT_RESERVED/uipackres/ui/"


/* ─────────────────────────────────────────────────────────────────────────
 * 预解码 + 自定义解码器策略 (开机全解码进 DDR, 之后纯 DMA blit)
 *
 *   1. 开机 preload_all_once(): 用系统真正的 SD/JLJPEG/PNG 解码器把每张图读一遍,
 *      像素拷到自己 malloc 的 DDR buffer, 关掉解码器. 之后 dsc.data 是稳定 DDR 地址.
 *
 *   2. register_ddr_decoder(): 注册一个"拦截解码器"挂到解码器链表头(最先被试).
 *      任何屏只要用 *文件路径* 引用这些图(generated 的 setup_scr_* 每次重建屏都会
 *      把 src 设回 SD 路径), info_cb / open_cb 直接按文件名匹配, 把 DDR buffer
 *      作为 img_data 返回 —— LVGL 拿到整帧真彩内存图, 走标准 DMA2D/GPU2P5D blit,
 *      *不再去 SD 解码*, 也*不需要事后轮询换 src*.
 *
 * 关键点: 这样换屏没有"先用文件路径解码一帧"的空窗, 主屏/子屏一视同仁, 以后新增
 * 图片只要加进 s_imgs[] 预解码表, 所有屏自动享受 DMA 搬运, 不用动 generated.
 * ───────────────────────────────────────────────────────────────────────── */

/*
 * preload_img_t 完整使用示例:
 *
 * static preload_img_t s_imgs[] = {
    { .name = "4.jpg" },
};
#define IMG_COUNT  (sizeof(s_imgs) / sizeof(s_imgs[0]))


/* 用 LVGL 已注册的解码器 (JLJPEG / PNG) 把文件读一遍, 像素拷到自己的 buffer,
 * 关掉解码器. 之后 dsc.data 就是稳定的 DDR 地址. */
static bool preload_one(preload_img_t *p)
{
    char path[256];
    const char *fname = p->file ? p->file : p->name;   /* 优先用实际磁盘文件名预解码 */
    snprintf(path, sizeof(path), "%s%s", CUSTOM_IMG_PACK_PAHT, fname);

    lv_img_decoder_dsc_t dec;
    lv_color_t           dummy = {0};
    if (lv_img_decoder_open(&dec, path, dummy, 32) != LV_RES_OK) {
        printf("[img] decoder_open fail: %s\n", path);
        return false;
    }

    /* 关键: 每像素字节数要按解码器实际给出的色彩格式来算.
     *   - 带透明的 png(lodepng): 报 TRUE_COLOR_ALPHA, 3B/px, 必须尊重否则花屏;
     *   - 硬件 jpeg(杰理 jljpeg): 是黑盒解码器, header.cf 报 RAW(px=0), 但
     *     img_data 实际已是整帧 RGB565 真彩, 按 TRUE_COLOR / 2B 处理.
     * 之前两版分别只照顾了其中一种, 才会出现"修好 png 又坏 jpg". */
    lv_img_cf_t cf  = dec.header.cf;
    int px     = lv_img_cf_get_px_size(cf) >> 3;   /* 每像素字节数 */
    if (px == 0) {                                 /* RAW/UNKNOWN: 硬解黑盒 */
        cf = LV_IMG_CF_TRUE_COLOR;
        px = sizeof(lv_color_t);
    }
    int w      = dec.header.w;
    int h      = dec.header.h;
    int stride = w * px;
    int size   = h * stride;

    uint8_t *buf = malloc(size);
    if (!buf) {
        printf("[img] malloc %d bytes fail (%s)\n", size, p->name);
        lv_img_decoder_close(&dec);
        return false;
    }

    if (dec.img_data) {
        /* 解码器一次性给完整像素 */
        memcpy(buf, dec.img_data, size);
    } else {
        /* 逐行回调读 */
        for (int y = 0; y < h; y++) {
            lv_img_decoder_read_line(&dec, 0, y, w, buf + y * stride);
        }
    }
    lv_img_decoder_close(&dec);

    p->buf                    = buf;
    p->dsc.header.cf          = cf;
    p->dsc.header.always_zero = 0;
    p->dsc.header.reserved    = 0;
    p->dsc.header.w           = w;
    p->dsc.header.h           = h;
    p->dsc.data_size          = size;
    p->dsc.data               = buf;
    p->loaded                 = true;

    printf("[img] preload %s ok, %dx%d, %d bytes @ %p\n",
           p->name, w, h, size, buf);
    return true;
}


static void preload_all_once(void)
{
    static bool done = false;
    if (done) {
        return;
    }
    for (size_t i = 0; i < IMG_COUNT; i++) {
        preload_one(&s_imgs[i]);
    }
    done = true;
}


/* ───────────────────────── 自定义"拦截"解码器 ─────────────────────────
 * 让任何用 SD 文件路径引用预解码图的控件, 直接拿到 DDR buffer, 不走 SD 解码.
 * ───────────────────────────────────────────────────────────────────────── */

/* 取路径里最后一个 '/' 或 '\' 之后的文件名部分 */
static const char *path_basename(const char *path)
{
    const char *base = path;
    for (const char *c = path; *c; c++) {
        if (*c == '/' || *c == '\\') {
            base = c + 1;
        }
    }
    return base;
}

/* 把图片源(必须是文件路径)按文件名在预解码表里查; 命中且已加载返回该项, 否则 NULL.
 * 用 basename 匹配, 这样 generated 给的 S:/ 全路径和我们的 mnt/ 前缀路径都能对上. */
static preload_img_t *find_preloaded(const void *src)
{
    if (lv_img_src_get_type(src) != LV_IMG_SRC_FILE) {
        return NULL;                       /* 变量/符号源交给内置解码器, 它已经是内存图 */
    }
    const char *base = path_basename((const char *)src);
    for (size_t i = 0; i < IMG_COUNT; i++) {
        if (s_imgs[i].loaded && strcmp(s_imgs[i].name, base) == 0) {
            return &s_imgs[i];
        }
    }
    return NULL;                           /* 没预解码的图 -> 返回 INV, 落到 SD 解码器 */
}

/* decoder: LVGL 传入的当前解码器对象, 本函数不用。
 * src: 图片源, 这里要求是文件路径, 并按文件名匹配 s_imgs[]。
 * header: 输出图片头信息, 命中预解码表后填入宽高和色彩格式。 */
static lv_res_t ddr_decoder_info(lv_img_decoder_t *decoder, const void *src, lv_img_header_t *header)
{
    LV_UNUSED(decoder);
    preload_img_t *p = find_preloaded(src);
    if (!p) {
        return LV_RES_INV;
    }
    *header = p->dsc.header;
    return LV_RES_OK;
}

/* decoder: LVGL 传入的当前解码器对象, 本函数不用。
 * dsc: 本次解码会话, dsc->src 是图片源, dsc->img_data 输出 DDR 像素地址。 */
static lv_res_t ddr_decoder_open(lv_img_decoder_t *decoder, lv_img_decoder_dsc_t *dsc)
{
    LV_UNUSED(decoder);
    preload_img_t *p = find_preloaded(dsc->src);
    if (!p) {
        return LV_RES_INV;
    }
    dsc->header   = p->dsc.header;
    dsc->img_data = p->buf;                /* 直接指向 DDR 像素, 后续渲染纯 blit */
    return LV_RES_OK;
}

/* decoder: LVGL 传入的当前解码器对象, 本函数不用。
 * dsc: 本次解码会话, 这里只收尾, 不释放常驻 DDR buffer。 */
static void ddr_decoder_close(lv_img_decoder_t *decoder, lv_img_decoder_dsc_t *dsc)
{
    LV_UNUSED(decoder);
    LV_UNUSED(dsc);
    /* buffer 是开机常驻的, 不在这里释放 */
}

static void register_ddr_decoder(void)
{
    static bool done = false;
    if (done) {
        return;
    }
    lv_img_decoder_t *d = lv_img_decoder_create();
    if (!d) {
        printf("[img] create ddr decoder fail\n");
        return;
    }
    lv_img_decoder_set_info_cb(d, ddr_decoder_info);
    lv_img_decoder_set_open_cb(d, ddr_decoder_open);
    lv_img_decoder_set_close_cb(d, ddr_decoder_close);
    done = true;
    printf("[img] ddr decoder registered\n");
}


/* 把 widget src 设成预解码的 dsc 指针 (而不是文件路径).
 * 找不到对应预解码项就回退到老路径方式 (慢路径, 兜底兼容). */
void custom_img_set_src(lv_obj_t *img, const char *name)
{
    for (size_t i = 0; i < IMG_COUNT; i++) {
        if (s_imgs[i].loaded && strcmp(s_imgs[i].name, name) == 0) {
            lv_img_set_src(img, &s_imgs[i].dsc);
            return;
        }
    }
    static char path[256] = {0};
    snprintf(path, sizeof(path), "%s%s", CUSTOM_IMG_PACK_PAHT, name);
    lv_img_set_src(img, path);
}


/* 给当前活动屏上的图片控件挂预解码 dsc (开机给首屏用).
 *
 * 注: 有了拦截解码器后, 子屏即使保持 generated 给的文件路径 src 也会命中 DDR buffer,
 * 不再需要轮询去事后换 src. 这里只为"开机首屏立即用 DDR"做一次挂载. */
static void apply_imgs_for(lv_obj_t *scr, lv_ui *ui)
{
    if (!ui || scr == NULL) {
        return;
    }

    /* 主屏 screen 的 screen_img_1：只换 src，不动尺寸/角度。
     * generated 已把它设成 720x720 + pivot/clip_corner，这里保持原布局，
     * 仅把"每次从 SD 解码"换成"直接用 DDR buffer"。 */
    if (scr == ui->screen) {
        custom_img_set_src(ui->screen_img_1, "4.jpg");
    }
}


void custom_img_init(lv_ui *ui)
{
    preload_all_once();                /* 1. 开机把所有图解码进 DDR (用系统 SD 解码器) */
    register_ddr_decoder();            /* 2. 注册拦截解码器: 文件路径引用 -> 直接拿 DDR buffer */
    apply_imgs_for(lv_scr_act(), ui);  /* 3. 主屏立即挂内存图 (子屏靠解码器, 不再轮询) */
}
