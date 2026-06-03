/*********************
 *      INCLUDES
 *********************/
#include <stddef.h>
#include "lvgl.h"
#include "pulldown.h"

/*********************
 *      DEFINES
 *********************/

/* 安卓式顶部下拉面板(单面板版, 参考 dem3333 的 pulldown 简化而来)。
 *
 * 用 GUI-Guider 在主屏画好的 screen_cont_1 当下拉页(它已被摆在屏外 (0,-600)):
 *   1. 开机 pulldown_init 把它从 screen 挪到 lv_layer_top, 藏在屏幕正上方并隐藏;
 *   2. 定时(20ms)扫触摸点, 从屏幕顶部 90px 内向下滑 -> 面板跟手滑下露出;
 *   3. 松手时按"露出是否超过一半"决定展开(贴顶)或收起(缩回屏外);
 *   4. 展开后任意位置上滑可收起。
 *
 * 注: 面板挪到 lv_layer_top 后不再随主屏 auto_del 销毁, s_panel 一直有效;
 *     主屏每次重建虽会再造一个屏内 cont_1 "幽灵", 但它在屏外(0,-600)不可见、且随旧屏删除,
 *     不累积也不挡事, 这里不用管它。 */

#define PULLDOWN_START_EDGE   90    /* 只有从屏幕顶部 90px 内开始下滑才触发下拉 */
#define PULLDOWN_DRAG_START   8     /* 移动超过 8px 才认定为拖拽(防误触) */
#define PULLDOWN_ANIM_TIME    220   /* 展开/收起动画时间, ms */

/**********************
 *  STATIC VARIABLES
 **********************/

static lv_obj_t   *s_panel    = NULL;  /* 下拉面板(screen_cont_1, 已挪到 layer_top) */
static lv_timer_t *s_timer    = NULL;
static lv_coord_t  s_panel_h  = 0;     /* 面板高度 = 下拉完全露出的高度 */
static bool        s_open      = false; /* 当前是否已展开 */
static bool        s_tracking  = false; /* 本次按下是否在跟踪 */
static bool        s_dragging  = false; /* 是否已进入拖拽 */
static lv_point_t  s_start;             /* 按下起点 */
static lv_coord_t  s_start_y   = 0;     /* 拖拽开始时面板的 y */
static lv_indev_t *s_indev     = NULL;
static bool        s_locked     = false; /* 是否已锁住本次输入(防下层控件抢) */

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void pulldown_set_y(void *obj, int32_t y);
static void pulldown_hide_ready_cb(lv_anim_t *a);
static void pulldown_anim_to(lv_coord_t end_y, lv_anim_ready_cb_t ready_cb);
static void pulldown_show(void);
static void pulldown_hide(void);
static void pulldown_prepare(lv_obj_t *p);
static void pulldown_timer_cb(lv_timer_t *t);

/**********************
 *  GLOBAL FUNCTIONS
 **********************/

void pulldown_init(lv_ui *ui)
{
    if (s_timer != NULL) {
        return;                         /* 已初始化, 防重复 */
    }
    if (ui == NULL || ui->screen_cont_1 == NULL) {
        return;                         /* GUI-Guider 里没画 cont_1 就不启用 */
    }
    s_panel = ui->screen_cont_1;
    pulldown_prepare(s_panel);
    s_timer = lv_timer_create(pulldown_timer_cb, 20, NULL);
}

/**********************
 *  STATIC FUNCTIONS
 **********************/

static void pulldown_set_y(void *obj, int32_t y)
{
    lv_obj_set_y((lv_obj_t *)obj, (lv_coord_t)y);
}

static void pulldown_hide_ready_cb(lv_anim_t *a)
{
    LV_UNUSED(a);
    lv_obj_add_flag(s_panel, LV_OBJ_FLAG_HIDDEN);   /* 收起动画结束后彻底隐藏 */
}

static void pulldown_anim_to(lv_coord_t end_y, lv_anim_ready_cb_t ready_cb)
{
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, s_panel);
    lv_anim_set_exec_cb(&a, pulldown_set_y);
    lv_anim_set_values(&a, lv_obj_get_y(s_panel), end_y);
    lv_anim_set_time(&a, PULLDOWN_ANIM_TIME);
    lv_anim_set_path_cb(&a, lv_anim_path_ease_out);
    if (ready_cb) {
        lv_anim_set_ready_cb(&a, ready_cb);
    }
    lv_anim_start(&a);
}

static void pulldown_show(void)
{
    lv_anim_del(s_panel, pulldown_set_y);
    lv_obj_clear_flag(s_panel, LV_OBJ_FLAG_HIDDEN);
    pulldown_anim_to(0, NULL);           /* 贴顶展开 */
    s_open = true;
}

static void pulldown_hide(void)
{
    lv_anim_del(s_panel, pulldown_set_y);
    pulldown_anim_to(-s_panel_h, pulldown_hide_ready_cb);   /* 缩回屏外 */
    s_open = false;
}

/* 面板初始化: 挪到顶层、藏在屏幕正上方、隐藏。保留 GUI-Guider 给的尺寸/样式不动。 */
static void pulldown_prepare(lv_obj_t *p)
{
    lv_obj_update_layout(p);
    s_panel_h = lv_obj_get_height(p);
    if (s_panel_h <= 0) {
        s_panel_h = 320;                 /* 兜底 */
    }
    lv_obj_set_parent(p, lv_layer_top());
    lv_obj_set_pos(p, 0, -s_panel_h);    /* 藏在屏幕正上方(底边贴屏顶) */
    lv_obj_set_scrollbar_mode(p, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(p, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(p, LV_OBJ_FLAG_SCROLLABLE);
}

static void pulldown_timer_cb(lv_timer_t *t)
{
    lv_indev_t *indev;
    lv_indev_t *pressed = NULL;
    lv_point_t  pt;
    lv_coord_t  dy;
    lv_coord_t  y;

    LV_UNUSED(t);

    if (s_panel == NULL || !lv_obj_is_valid(s_panel)) {
        return;
    }

    /* 找一个"正按下"的指针(触摸)设备 */
    for (indev = lv_indev_get_next(NULL); indev; indev = lv_indev_get_next(indev)) {
        if (lv_indev_get_type(indev) == LV_INDEV_TYPE_POINTER &&
            indev->proc.state == LV_INDEV_STATE_PRESSED) {
            pressed = indev;
            break;
        }
    }

    /* 松手: 结束本次拖拽, 按露出比例决定展开/收起 */
    if (pressed == NULL) {
        if (s_dragging) {
            lv_coord_t reveal = s_panel_h + lv_obj_get_y(s_panel);   /* 已露出高度(0~panel_h) */
            if (reveal >= s_panel_h / 2) {
                pulldown_show();
            } else {
                pulldown_hide();
            }
        }
        s_tracking = false;
        s_dragging = false;
        s_indev    = NULL;
        s_locked   = false;
        return;
    }

    s_indev = pressed;
    lv_indev_get_point(pressed, &pt);

    if (!s_tracking) {
        s_start    = pt;
        s_tracking = true;
        s_dragging = false;
        if (s_open) {
            s_start_y = 0;                  /* 已展开: 任意位置都能上拉收起 */
        } else if (pt.y <= PULLDOWN_START_EDGE) {
            s_start_y = -s_panel_h;         /* 收起态: 只有顶部边缘下滑才拉得出 */
        } else {
            s_tracking = false;             /* 起点不在顶部, 本次不管 */
            return;
        }
    }

    dy = pt.y - s_start.y;

    if (!s_dragging) {
        if (LV_ABS(dy) < PULLDOWN_DRAG_START) {
            return;                         /* 移动太小, 还不算拖拽 */
        }
        s_dragging = true;
        lv_anim_del(s_panel, pulldown_set_y);
        lv_obj_clear_flag(s_panel, LV_OBJ_FLAG_HIDDEN);
    }

    /* 跟手移动面板 y, 限制在 [-panel_h, 0] */
    y = s_start_y + dy;
    if (y > 0) {
        y = 0;
    }
    if (y < -s_panel_h) {
        y = -s_panel_h;
    }
    lv_obj_set_y(s_panel, y);

    /* 一旦进入拖拽, 锁住本次按压, 防止下面的按钮/控件误响应 */
    if (s_dragging && !s_locked && s_indev != NULL) {
        lv_indev_wait_release(s_indev);
        s_locked = true;
    }
}
