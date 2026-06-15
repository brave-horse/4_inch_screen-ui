#include "lvgl.h"
#include "gui_guider.h"
#include "HWDataAccess.h"
#include "hw_cloud_task.h"
#include "RollBlind.h"

/* 竖向卷帘: 取自 generated 布局 */
#define CLOTH_Y0    181
#define PULL_Y0     481
#define PULL_CY     500          /* 拉手中心(放到最长时) */
#define TRAVEL_MAX  280          /* 行程: 拉手上移到 cont_3 底缘(201)为止 */
#define APPLY_MIN_MS 50

static int32_t  s_pct;           /* 0=放到最长(下), 100=收到最短(上) */
static uint32_t s_post_tick;

static void roll_apply(int32_t pct)
{
    int32_t d = pct * TRAVEL_MAX / 100;
    lv_obj_set_y(guider_ui.RollBlind_FabCurtianLeft,  CLOTH_Y0 - d);
    lv_obj_set_y(guider_ui.RollBlind_FabCurtianPull1, PULL_Y0  - d);
}

static void roll_post(int32_t pct)
{
    HWInterface.Curtain.SetPos(CURTAIN_IDX_ROLLBLIND, (uint16_t)pct);
    hw_cloud_post(&(HW_Msg){ .type = HW_MSG_CURTAIN_POS, .idx = CURTAIN_IDX_ROLLBLIND, .val = (uint16_t)pct });
}

static void roll_anim_cb(void *var, int32_t v)
{
    LV_UNUSED(var);
    s_pct = v;
    roll_apply(v);
}

/* 在指定时间内动画到 target(%); ms=0 直接到位 */
static void roll_anim_to_ms(int32_t target, uint32_t ms)
{
    lv_anim_del(&s_pct, roll_anim_cb);
    if (ms == 0) { s_pct = target; roll_apply(target); return; }
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, &s_pct);
    lv_anim_set_exec_cb(&a, roll_anim_cb);
    lv_anim_set_values(&a, s_pct, target);
    lv_anim_set_time(&a, ms);
    lv_anim_start(&a);
}

/* 本屏不在 scr_guard, 自挂删除回调停动画防野指针 */
static void roll_del_cb(lv_event_t *e)
{
    LV_UNUSED(e);
    lv_anim_del(&s_pct, roll_anim_cb);
}

/* ══════ 事件接口(GUI-Guider 一行调用) ══════ */

void roll_blind_on_screen_load(void)
{
    lv_obj_clear_flag(guider_ui.RollBlind, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_event_cb(guider_ui.RollBlind, roll_del_cb, LV_EVENT_DELETE, NULL);

    /* 按时间算当前位置, 若仍在移动则续播到目标 */
    uint16_t cur_pct = curtain_motion_current(CURTAIN_IDX_ROLLBLIND);
    uint16_t tgt_pct = curtain_motion_target(CURTAIN_IDX_ROLLBLIND);
    s_pct = cur_pct;
    roll_apply(s_pct);
    if (cur_pct != tgt_pct)
        roll_anim_to_ms(tgt_pct, curtain_motion_remaining_ms(CURTAIN_IDX_ROLLBLIND));
}

void roll_blind_on_open(void)
{
    curtain_motion_start(CURTAIN_IDX_ROLLBLIND, 100);
    roll_anim_to_ms(100, curtain_motion_remaining_ms(CURTAIN_IDX_ROLLBLIND));
    roll_post(100);
}

void roll_blind_on_close(void)
{
    curtain_motion_start(CURTAIN_IDX_ROLLBLIND, 0);
    roll_anim_to_ms(0, curtain_motion_remaining_ms(CURTAIN_IDX_ROLLBLIND));
    roll_post(0);
}

void roll_blind_on_pause(void)
{
    lv_anim_del(&s_pct, roll_anim_cb);
    curtain_motion_set(CURTAIN_IDX_ROLLBLIND, (uint16_t)s_pct);
    roll_post(s_pct);
}

void roll_blind_on_drag(lv_event_t *e)
{
    LV_UNUSED(e);
    lv_indev_t *indev = lv_indev_get_act();
    if (!indev) return;
    lv_point_t p;
    lv_indev_get_point(indev, &p);

    lv_anim_del(&s_pct, roll_anim_cb);

    int32_t pct = (PULL_CY - p.y) * 100 / TRAVEL_MAX;
    if (pct < 0)   pct = 0;
    if (pct > 100) pct = 100;

    s_pct = pct;
    roll_apply(pct);
    curtain_motion_set(CURTAIN_IDX_ROLLBLIND, (uint16_t)pct);   /* 手动定位, 停在此处 */
    if (lv_tick_elaps(s_post_tick) >= APPLY_MIN_MS) {
        s_post_tick = lv_tick_get();
        roll_post(pct);
    }
}
