#include "lvgl.h"
#include "gui_guider.h"
#include "HWDataAccess.h"
#include "hw_cloud_task.h"
#include "FabricCurtian.h"

/* 闭合时各控件 x(取自 generated 布局) */
#define LEFT_X0     130
#define RIGHT_X0    359
#define PULL1_X0    307
#define PULL2_X0    367
#define PULL1_CX    329          /* 左拉手中心 */
#define PULL2_CX    389          /* 右拉手中心 */
#define FAB_CENTER  360          /* 两帘闭合处 */
#define TRAVEL_MAX  181          /* 最大行程: 拉手不被 cont_2/3 盖住 */
#define ANIM_MS_PCT 22           /* 每 1% 的开合耗时 */
#define APPLY_MIN_MS 50

static int32_t  s_pct;           /* 当前开合度 0..100 */
static uint32_t s_post_tick;

static void fab_apply(int32_t pct)
{
    int32_t d = pct * TRAVEL_MAX / 100;
    lv_obj_set_x(guider_ui.FabricCurtian_FabCurtianLeft,  LEFT_X0  - d);
    lv_obj_set_x(guider_ui.FabricCurtian_FabCurtianright, RIGHT_X0 + d);
    lv_obj_set_x(guider_ui.FabricCurtian_FabCurtianPull1, PULL1_X0 - d);
    lv_obj_set_x(guider_ui.FabricCurtian_FabCurtianPull2, PULL2_X0 + d);
    lv_label_set_text_fmt(guider_ui.FabricCurtian_label_1, "%d%%", (int)pct);
}

static void fab_post(int32_t pct)
{
    HWInterface.Curtain.SetPos(0, (uint16_t)pct);
    hw_cloud_post(&(HW_Msg){ .type = HW_MSG_CURTAIN_POS, .idx = 0, .val = (uint16_t)pct });
}

static void fab_anim_cb(void *var, int32_t v)
{
    LV_UNUSED(var);
    s_pct = v;
    fab_apply(v);
}

static void fab_anim_to(int32_t target)
{
    lv_anim_del(&s_pct, fab_anim_cb);
    int32_t diff = target - s_pct;
    if (diff < 0) diff = -diff;
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, &s_pct);
    lv_anim_set_exec_cb(&a, fab_anim_cb);
    lv_anim_set_values(&a, s_pct, target);
    lv_anim_set_time(&a, (uint32_t)diff * ANIM_MS_PCT);
    lv_anim_start(&a);
}

/* ══════ 事件接口(GUI-Guider 一行调用) ══════ */

void fab_curtain_on_screen_load(void)
{
    lv_obj_clear_flag(guider_ui.FabricCurtian, LV_OBJ_FLAG_SCROLLABLE);
    fab_apply(s_pct);
}

void fab_curtain_on_open(void)  { fab_anim_to(100); fab_post(100); }
void fab_curtain_on_close(void) { fab_anim_to(0);   fab_post(0);   }

void fab_curtain_on_pause(void)
{
    lv_anim_del(&s_pct, fab_anim_cb);
    fab_post(s_pct);
}

/* 拖拉手/点窗帘 → 开到手指处(两帘对称) */
void fab_curtain_on_drag(lv_event_t *e)
{
    LV_UNUSED(e);
    lv_indev_t *indev = lv_indev_get_act();
    if (!indev) return;
    lv_point_t p;
    lv_indev_get_point(indev, &p);

    lv_anim_del(&s_pct, fab_anim_cb);

    int32_t pct = (p.x < FAB_CENTER) ? (PULL1_CX - p.x) * 100 / TRAVEL_MAX
                                     : (p.x - PULL2_CX) * 100 / TRAVEL_MAX;
    if (pct < 0)   pct = 0;
    if (pct > 100) pct = 100;

    s_pct = pct;
    fab_apply(pct);
    if (lv_tick_elaps(s_post_tick) >= APPLY_MIN_MS) {
        s_post_tick = lv_tick_get();
        fab_post(pct);
    }
}
