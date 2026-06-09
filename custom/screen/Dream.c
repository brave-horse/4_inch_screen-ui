#include "lvgl.h"
#include "gui_guider.h"
#include "HWDataAccess.h"
#include "hw_cloud_task.h"
#include "Dream.h"

/* 取自 generated 布局(无 cont_2/3 遮罩, 两帘直接滑出屏幕边缘) */
#define LEFT_X0     128
#define RIGHT_X0    359
#define PULL1_X0    307
#define PULL2_X0    367
#define PULL1_CX    329
#define PULL2_CX    389
#define DR_CENTER   360
#define TRAVEL_MAX  181
#define ANIM_MS_PCT 22
#define APPLY_MIN_MS 50
#define ANGLE_MAX   180          /* 旋转角范围 0..180° */
#define SLIDER_MAX  100          /* slider_1 量程 */

static int32_t  s_pct;
static int32_t  s_angle_pos = SLIDER_MAX / 2;   /* 初始 90° */
static uint32_t s_post_tick;
static uint32_t s_ang_tick;

static void dream_apply(int32_t pct)
{
    int32_t d = pct * TRAVEL_MAX / 100;
    lv_obj_set_x(guider_ui.Dream_FabCurtianLeft,  LEFT_X0  - d);
    lv_obj_set_x(guider_ui.Dream_FabCurtianright, RIGHT_X0 + d);
    lv_obj_set_x(guider_ui.Dream_FabCurtianPull1, PULL1_X0 - d);
    lv_obj_set_x(guider_ui.Dream_FabCurtianPull2, PULL2_X0 + d);
    lv_label_set_text_fmt(guider_ui.Dream_label_1, "%d%%", (int)pct);
}

static void dream_post(int32_t pct)
{
    HWInterface.Curtain.SetPos(0, (uint16_t)pct);
    hw_cloud_post(&(HW_Msg){ .type = HW_MSG_CURTAIN_POS, .idx = 0, .val = (uint16_t)pct });
}

/* 旋转角只入队下发, UI 不转 */
static void dream_post_angle(int32_t angle)
{
    hw_cloud_post(&(HW_Msg){ .type = HW_MSG_CURTAIN_ANGLE, .idx = 0, .val = (uint16_t)angle });
}

static void dream_anim_cb(void *var, int32_t v)
{
    LV_UNUSED(var);
    s_pct = v;
    dream_apply(v);
}

static void dream_anim_to(int32_t target)
{
    lv_anim_del(&s_pct, dream_anim_cb);
    int32_t diff = target - s_pct;
    if (diff < 0) diff = -diff;
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, &s_pct);
    lv_anim_set_exec_cb(&a, dream_anim_cb);
    lv_anim_set_values(&a, s_pct, target);
    lv_anim_set_time(&a, (uint32_t)diff * ANIM_MS_PCT);
    lv_anim_start(&a);
}

/* ══════ 事件接口(GUI-Guider 一行调用) ══════ */

void dream_on_screen_load(void)
{
    lv_obj_clear_flag(guider_ui.Dream, LV_OBJ_FLAG_SCROLLABLE);
    lv_slider_set_value(guider_ui.Dream_slider_1, s_angle_pos, LV_ANIM_OFF);
    dream_apply(s_pct);
    dream_post_angle(s_angle_pos * ANGLE_MAX / SLIDER_MAX);
}

void dream_on_open(void)  { dream_anim_to(100); dream_post(100); }
void dream_on_close(void) { dream_anim_to(0);   dream_post(0);   }

void dream_on_pause(void)
{
    lv_anim_del(&s_pct, dream_anim_cb);
    dream_post(s_pct);
}

void dream_on_drag(lv_event_t *e)
{
    LV_UNUSED(e);
    lv_indev_t *indev = lv_indev_get_act();
    if (!indev) return;
    lv_point_t p;
    lv_indev_get_point(indev, &p);

    lv_anim_del(&s_pct, dream_anim_cb);

    int32_t pct = (p.x < DR_CENTER) ? (PULL1_CX - p.x) * 100 / TRAVEL_MAX
                                    : (p.x - PULL2_CX) * 100 / TRAVEL_MAX;
    if (pct < 0)   pct = 0;
    if (pct > 100) pct = 100;

    s_pct = pct;
    dream_apply(pct);
    if (lv_tick_elaps(s_post_tick) >= APPLY_MIN_MS) {
        s_post_tick = lv_tick_get();
        dream_post(pct);
    }
}

void dream_on_angle_slider_change(void)
{
    s_angle_pos = lv_slider_get_value(guider_ui.Dream_slider_1);
    if (lv_tick_elaps(s_ang_tick) >= APPLY_MIN_MS) {
        s_ang_tick = lv_tick_get();
        dream_post_angle(s_angle_pos * ANGLE_MAX / SLIDER_MAX);
    }
}
