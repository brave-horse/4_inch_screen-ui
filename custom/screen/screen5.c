/*********************
 *      INCLUDES
 *********************/
#include <stddef.h>
#include <stdio.h>
#include "lvgl.h"
#include "screen.h"
#include "gui_guider.h"

/*********************
 *      DEFINES
 *********************/

/* 轮询周期: 用来发现 screen_5 被 auto_del 重建(slider 指针变新)后, 给新 slider 补挂
 * VALUE_CHANGED 回调并按当前值刷新一次。静止时只是几次指针比较, 开销可忽略(同 scr_noscroll)。 */
#define SCREEN_5_POLL_PERIOD_MS  30

/* 亮度条 slider_1 量程(见 generated/setup_scr_screen_5.c): 0~100, 直接当百分比用。 */
#define BRI_MIN   0
#define BRI_MAX   100

/* 色温条 slider_2 量程: 2700K(最左, 橙) ~ 6500K(最右, 白)。 */
#define CT_MIN    2700
#define CT_MAX    6500
#define CT_SPAN   (CT_MAX - CT_MIN)   /* 3800 */

/**********************
 *  STATIC VARIABLES
 **********************/

/* 已挂过 VALUE_CHANGED 回调的 slider_1 实例。屏每次重建都是新对象, 指针变化即触发重挂。
 * 仅作指针相等比较, 从不解引用, 旧屏删除后变野也安全。 */
static lv_obj_t *s_bound_slider1;

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void screen_5_apply_light(void);
static void screen_5_slider_event_cb(lv_event_t *e);
static void screen_5_poll_cb(lv_timer_t *timer);

/**********************
 *  GLOBAL FUNCTIONS
 **********************/

void screen_custom_init(void)
{
    lv_timer_create(screen_5_poll_cb, SCREEN_5_POLL_PERIOD_MS, NULL);
}

/**********************
 *  STATIC FUNCTIONS
 **********************/

/* 按需求公式落地"白光图 / 橙光图"的透明度, 并同步两个标签的数字。
 *   B = 亮度(slider_1)        归一化到 0..1
 *   T = 色温位置(slider_2)     归一化到 0..1 (最左 0=橙, 最右 1=白)
 *   白图透明度 O_white  = B * T          * 255
 *   橙图透明度 O_orange = B * (1.0 - T)  * 255
 * 白图叠在橙图上: T 往右白图越实、橙图越虚 → 暖端=橙, 冷端=白; B 同时整体调暗/亮。
 *
 * 闸门(关键, 反复踩坑): 不能用 guider_ui.screen_5 判活动屏(切屏/重建时序下会 stale,
 * 一旦对不上整段被 return 挡掉 → 拖 slider 灯和 label 全无反应)。改用控件自身:
 * 先 is_valid 再 lv_obj_get_screen(控件)==lv_scr_act()。 */
static void screen_5_apply_light(void)
{
    lv_obj_t *slider1 = guider_ui.screen_5_slider_1;   /* 亮度 */
    lv_obj_t *slider2 = guider_ui.screen_5_slider_2;   /* 色温 */
    lv_obj_t *white   = guider_ui.screen_5_dev_white_img;
    lv_obj_t *orange  = guider_ui.screen_5_dev_orange_img;
    lv_obj_t *label1  = guider_ui.screen_5_label_1;    /* 亮 度 | XX% */
    lv_obj_t *label2  = guider_ui.screen_5_label_2;    /* 色 温 | XXXXK */

    int32_t bri, ct;
    uint32_t tnum, o_white, o_orange;
    char buf[32];

    /* 用 slider_1 自身做闸门, 绕开会失效的全局屏指针。 */
    if (slider1 == NULL || !lv_obj_is_valid(slider1)) {
        return;
    }
    if (lv_obj_get_screen(slider1) != lv_scr_act()) {
        return;
    }
    if (slider2 == NULL || !lv_obj_is_valid(slider2)) {
        return;
    }

    bri = lv_slider_get_value(slider1);   /* 0..100 */
    ct  = lv_slider_get_value(slider2);   /* 2700..6500 */

    /* 全整数运算避免浮点: tnum = (ct-CT_MIN) 即 T*CT_SPAN。
     *   o_white  = bri * tnum             * 255 / (BRI_MAX * CT_SPAN)
     *   o_orange = bri * (CT_SPAN - tnum) * 255 / (BRI_MAX * CT_SPAN)
     * 最大中间值 100*3800*255 ≈ 9.7e7, 不溢出 uint32。 */
    tnum     = (uint32_t)(ct - CT_MIN);
    o_white  = (uint32_t)bri * tnum * 255u / ((uint32_t)BRI_MAX * CT_SPAN);
    o_orange = (uint32_t)bri * (CT_SPAN - tnum) * 255u / ((uint32_t)BRI_MAX * CT_SPAN);

    if (lv_obj_is_valid(white)) {
        lv_obj_set_style_img_opa(white, (lv_opa_t)o_white, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    if (lv_obj_is_valid(orange)) {
        lv_obj_set_style_img_opa(orange, (lv_opa_t)o_orange, LV_PART_MAIN | LV_STATE_DEFAULT);
    }

    /* 标签数字随进度条同步。用栈上 snprintf + lv_label_set_text:
     * 不用 lv_label_set_text_fmt(它要额外 lv_mem_alloc 临时缓冲, 内存吃紧时静默失败
     * → 灯变了文字却不变)。 */
    if (lv_obj_is_valid(label1)) {
        snprintf(buf, sizeof(buf), "亮 度 | %d%%", (int)bri);
        lv_label_set_text(label1, buf);
    }
    if (lv_obj_is_valid(label2)) {
        snprintf(buf, sizeof(buf), "色 温 | %dK", (int)ct);
        lv_label_set_text(label2, buf);
    }
}

/* 拖动任一进度条 → 重算灯光与标签。apply 内部自带闸门, 这里直接转发即可。 */
static void screen_5_slider_event_cb(lv_event_t *e)
{
    LV_UNUSED(e);
    screen_5_apply_light();
}

/* 发现 screen_5 的 slider_1 换了新对象(首次建屏 / auto_del 重建)就给两条 slider
 * 补挂 VALUE_CHANGED, 并按当前值刷新一次(让灯光/标签开屏即与 slider 位置一致)。 */
static void screen_5_poll_cb(lv_timer_t *timer)
{
    lv_obj_t *act = lv_scr_act();
    lv_obj_t *slider1, *slider2;

    LV_UNUSED(timer);

    if (act == NULL) {
        return;
    }

    slider1 = guider_ui.screen_5_slider_1;

    /* 多重防护(防屏删除后指针变野 + 地址复用误判):
     *   1) 非空且 is_valid;
     *   2) 确实是 slider 类型;
     *   3) 它所在的屏就是当前活动屏。
     * 三者都过, 才认为 screen_5 处于活动态且 slider 是有效新对象。 */
    if (slider1 == NULL || !lv_obj_is_valid(slider1)) {
        return;
    }
    if (!lv_obj_check_type(slider1, &lv_slider_class)) {
        return;
    }
    if (lv_obj_get_screen(slider1) != act) {
        return;
    }
    if (slider1 == s_bound_slider1) {
        return;   /* 本实例已挂过, 不重复挂 */
    }

    slider2 = guider_ui.screen_5_slider_2;

    lv_obj_add_event_cb(slider1, screen_5_slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
    if (slider2 != NULL && lv_obj_is_valid(slider2)) {
        lv_obj_add_event_cb(slider2, screen_5_slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
    }
    s_bound_slider1 = slider1;

    /* 建屏/重建后立即按 slider 初值刷新一次。 */
    screen_5_apply_light();
}
