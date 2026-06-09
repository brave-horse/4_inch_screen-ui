#include "lvgl.h"
#include "gui_guider.h"
#include "HWDataAccess.h"
#include "hw_cloud_task.h"
#include "Sheers.h"

/* 闭合时各控件 x(取自 generated 布局) */
#define LEFT_X0     128
#define RIGHT_X0    359
#define PULL1_X0    267
#define PULL2_X0    367
#define PULL1_CX    289          /* 左拉手中心 */
#define PULL2_CX    389          /* 右拉手中心 */
#define SH_CENTER   360
#define TRAVEL_MAX  143          /* 最大行程: Pull1 不被 cont_2 盖住 */
#define ANIM_MS_PCT 22
#define APPLY_MIN_MS 50

static int32_t  s_pct;
static uint32_t s_post_tick;

static void sheers_apply(int32_t pct)
{
    int32_t d = pct * TRAVEL_MAX / 100;
    lv_obj_set_x(guider_ui.Sheers_FabCurtianLeft,  LEFT_X0  - d);
    lv_obj_set_x(guider_ui.Sheers_FabCurtianright, RIGHT_X0 + d);
    lv_obj_set_x(guider_ui.Sheers_FabCurtianPull1, PULL1_X0 - d);
    lv_obj_set_x(guider_ui.Sheers_FabCurtianPull2, PULL2_X0 + d);
}

static void sheers_post(int32_t pct)
{
    HWInterface.Curtain.SetPos(0, (uint16_t)pct);
    hw_cloud_post(&(HW_Msg){ .type = HW_MSG_CURTAIN_POS, .idx = 0, .val = (uint16_t)pct });
}

static void sheers_anim_cb(void *var, int32_t v)
{
    LV_UNUSED(var);
    s_pct = v;
    sheers_apply(v);
}

static void sheers_anim_to(int32_t target)
{
    lv_anim_del(&s_pct, sheers_anim_cb);
    int32_t diff = target - s_pct;
    if (diff < 0) diff = -diff;
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, &s_pct);
    lv_anim_set_exec_cb(&a, sheers_anim_cb);
    lv_anim_set_values(&a, s_pct, target);
    lv_anim_set_time(&a, (uint32_t)diff * ANIM_MS_PCT);
    lv_anim_start(&a);
}

/* ══════ 事件接口(GUI-Guider 一行调用) ══════ */

void sheers_on_screen_load(void)
{
    lv_obj_clear_flag(guider_ui.Sheers, LV_OBJ_FLAG_SCROLLABLE);
    sheers_apply(s_pct);
}

void sheers_on_open(void)  { sheers_anim_to(100); sheers_post(100); }
void sheers_on_close(void) { sheers_anim_to(0);   sheers_post(0);   }

void sheers_on_pause(void)
{
    lv_anim_del(&s_pct, sheers_anim_cb);
    sheers_post(s_pct);
}

void sheers_on_drag(lv_event_t *e)
{
    LV_UNUSED(e);
    lv_indev_t *indev = lv_indev_get_act();
    if (!indev) return;
    lv_point_t p;
    lv_indev_get_point(indev, &p);

    lv_anim_del(&s_pct, sheers_anim_cb);

    int32_t pct = (p.x < SH_CENTER) ? (PULL1_CX - p.x) * 100 / TRAVEL_MAX
                                    : (p.x - PULL2_CX) * 100 / TRAVEL_MAX;
    if (pct < 0)   pct = 0;
    if (pct > 100) pct = 100;

    s_pct = pct;
    sheers_apply(pct);
    if (lv_tick_elaps(s_post_tick) >= APPLY_MIN_MS) {
        s_post_tick = lv_tick_get();
        sheers_post(pct);
    }
}
