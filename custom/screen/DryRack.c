#include "lvgl.h"
#include "gui_guider.h"
#include "hw_cloud_task.h"
#include "DryRack.h"

#define DOWN_Y       160      /* img_1 最大下降 y(初始 -110) */
#define ANIM_MS_PX   8        /* 每像素开合耗时 */
#define APPLY_MIN_MS 50

static int32_t    s_d;         /* 当前下降位移 0..s_travel */
static int32_t    s_travel;    /* = DOWN_Y - 初始 y */
static lv_coord_t s_img_y0;    /* img_1 初始 y(运行时捕获) */
static lv_coord_t s_label_y0;  /* label_1 初始 y */
static bool       s_light;     /* 照明开关 */
static uint32_t   s_post_tick;

/* img_1 + label_1 同步移动(间距不变), label 显示百分比 */
static void dryrack_apply(int32_t d)
{
    if (!lv_obj_is_valid(guider_ui.DryRack_img_1)) return;
    lv_obj_set_y(guider_ui.DryRack_img_1,   s_img_y0   + d);
    lv_obj_set_y(guider_ui.DryRack_label_1, s_label_y0 + d);
    int pct = s_travel ? (int)(d * 100 / s_travel) : 0;
    lv_label_set_text_fmt(guider_ui.DryRack_label_1, "%d%%", pct);
}

static void dryrack_post(int32_t d)
{
    int pct = s_travel ? (int)(d * 100 / s_travel) : 0;
    hw_cloud_post(&(HW_Msg){ .type = HW_MSG_DRYRACK_POS, .val = (uint16_t)pct });
}

/* 照明: imgbtn 勾选态 + img_2 发光图透明度 */
static void dryrack_apply_light(void)
{
    if (s_light) lv_obj_add_state  (guider_ui.DryRack_imgbtn_1, LV_STATE_CHECKED);
    else         lv_obj_clear_state(guider_ui.DryRack_imgbtn_1, LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(guider_ui.DryRack_img_2,
                             s_light ? LV_OPA_COVER : LV_OPA_TRANSP,
                             LV_PART_MAIN | LV_STATE_DEFAULT);
}

static void d_anim_cb(void *var, int32_t v)
{
    LV_UNUSED(var);
    s_d = v;
    dryrack_apply(v);
}

static void anim_to(int32_t target)
{
    lv_anim_del(&s_d, d_anim_cb);
    int32_t diff = target - s_d; if (diff < 0) diff = -diff;
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, &s_d);
    lv_anim_set_exec_cb(&a, d_anim_cb);
    lv_anim_set_values(&a, s_d, target);
    lv_anim_set_time(&a, (uint32_t)diff * ANIM_MS_PX);
    lv_anim_start(&a);
}

/* 本屏不在 scr_guard 列表, 自挂删除回调: 屏一删停动画, 防野指针 */
static void scr_del_cb(lv_event_t *e)
{
    LV_UNUSED(e);
    lv_anim_del(&s_d, d_anim_cb);
}

/* ══════ 事件接口(GUI-Guider 一行调用) ══════ */

void dryrack_on_screen_load(void)
{
    lv_obj_clear_flag(guider_ui.DryRack, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_event_cb(guider_ui.DryRack, scr_del_cb, LV_EVENT_DELETE, NULL);

    s_img_y0   = lv_obj_get_y(guider_ui.DryRack_img_1);
    s_label_y0 = lv_obj_get_y(guider_ui.DryRack_label_1);
    s_travel   = DOWN_Y - s_img_y0;
    if (s_travel <= 0) s_travel = 270;

    dryrack_apply(s_d);
    dryrack_apply_light();
}

/* 灯按钮: 开→img_2 显示, 关→img_2 透明度 0 */
void dryrack_on_light_toggle(lv_event_t *e)
{
    s_light = lv_obj_has_state(lv_event_get_target(e), LV_STATE_CHECKED);
    dryrack_apply_light();
    hw_cloud_post(&(HW_Msg){ .type = HW_MSG_DRYRACK_LIGHT, .on = s_light });
}

/* 触摸 label_1/img_1 拖动: 跟手累加位移, 两者同步移动 */
void dryrack_on_drag(lv_event_t *e)
{
    LV_UNUSED(e);
    lv_indev_t *indev = lv_indev_get_act();
    if (!indev) return;
    lv_anim_del(&s_d, d_anim_cb);

    lv_point_t v;
    lv_indev_get_vect(indev, &v);
    s_d += v.y;
    if (s_d < 0)        s_d = 0;
    if (s_d > s_travel) s_d = s_travel;

    dryrack_apply(s_d);
    if (lv_tick_elaps(s_post_tick) >= APPLY_MIN_MS) {
        s_post_tick = lv_tick_get();
        dryrack_post(s_d);
    }
}

void dryrack_on_open(void)  { anim_to(0);        dryrack_post(0);        }  /* 上升 */
void dryrack_on_close(void) { anim_to(s_travel); dryrack_post(s_travel); }  /* 下降 */

void dryrack_on_pause(void)
{
    lv_anim_del(&s_d, d_anim_cb);
    dryrack_post(s_d);
}
