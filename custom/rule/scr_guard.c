/*********************
 *      INCLUDES
 *********************/
#include <stddef.h>
#include "lvgl.h"
#include "scr_guard.h"
#include "gui_guider.h"

/*********************
 *      DEFINES
 *********************/

/* 轮询周期：用来发现"当前活动屏换了"并给新屏补挂删除回调。
 * 只在切屏时才真正做事，平时就是一次指针比较，开销可忽略。 */
#define SCR_GUARD_POLL_PERIOD_MS  30

/**********************
 *  STATIC VARIABLES
 **********************/

/* 需要"删除即置 NULL"保护的全局屏指针槽位。
 * —— 原则：凡是 custom/ 里有代码会去读的屏，就把它的槽位地址列进来。
 * 本工程 6 个屏在 events_init.c 里互相 auto_del 切换，img/scr_noscroll 等又会读
 * guider_ui.screen*，所以这里把全部 6 个屏都列上，最稳。
 * 新增屏时在这里加一行 &guider_ui.screen_xxx 即可。 */
static lv_obj_t **const s_slots[] = {
    &guider_ui.screen,
    &guider_ui.screen_1,
    &guider_ui.screen_2,
    &guider_ui.screen_3,
    &guider_ui.screen_4,
    &guider_ui.screen_5,
};
#define SLOT_CNT  (sizeof(s_slots) / sizeof(s_slots[0]))

/* 需要随宿主屏一起"删除即置 NULL"的【子控件】指针槽位。
 *
 * 背景(本工程卡死的真凶)：generated/widgets_init.c 的 screen_digital_clock_1_timer 是
 * 常驻定时器(每秒一次)，里面 lv_obj_is_valid(guider_ui.screen_digital_clock_1) 通过后就写它。
 * 主屏被 auto_del 删除后这个指针变野却没人清，lv_obj_is_valid 只比地址不解引用，于是
 * 来回切几次、旧地址被新屏对象复用后 is_valid 误判为真 → 把别的控件当数字时钟写 → 崩。
 * 删除即置 NULL 后 is_valid(NULL)=false，timer 老实跳过，问题根除。
 *
 * 屏槽位靠"给活动屏挂回调"覆盖，但子控件不是活动屏，需要单独给它本身挂删除回调，
 * 所以单列一张表。新增"被 generated 常驻代码引用的子控件"时，在这里加一行即可。 */
static lv_obj_t **const s_child_slots[] = {
    &guider_ui.screen_digital_clock_1,
};
#define CHILD_CNT  (sizeof(s_child_slots) / sizeof(s_child_slots[0]))

/* 已经挂过删除回调的当前活动屏。仅用作指针相等比较，从不解引用，野了也安全。 */
static lv_obj_t *s_guarded = NULL;

/* 与 s_child_slots 一一对应，记录上次已挂删除回调的子控件对象(仅做指针比较)。 */
static lv_obj_t *s_child_guarded[CHILD_CNT];

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void scr_guard_del_cb(lv_event_t *e);
static void scr_guard_child_del_cb(lv_event_t *e);
static void scr_guard_poll_cb(lv_timer_t *timer);

/**********************
 *  GLOBAL FUNCTIONS
 **********************/

void scr_guard_init(void)
{
    lv_timer_create(scr_guard_poll_cb, SCR_GUARD_POLL_PERIOD_MS, NULL);
}

/**********************
 *  STATIC FUNCTIONS
 **********************/

/* 屏被 lv_obj_del 销毁前会收到 LV_EVENT_DELETE。此刻把所有指向它的槽位清成 NULL，
 * 是在"对象还活着、地址尚未被复用"的时间点完成的，因此能彻底切断后续的地址别名。 */
static void scr_guard_del_cb(lv_event_t *e)
{
    lv_obj_t *dying = lv_event_get_target(e);
    size_t i;

    for (i = 0; i < SLOT_CNT; i++) {
        if (*s_slots[i] == dying) {
            *s_slots[i] = NULL;
        }
    }

    /* 允许新屏（哪怕复用了同一地址）重新被识别为“未挂过回调”。 */
    if (dying == s_guarded) {
        s_guarded = NULL;
    }
}

/* 被守护的子控件(如数字时钟)随宿主屏销毁时收到 LV_EVENT_DELETE。
 * 把它对应的全局槽位清 NULL，并允许新对象重新被识别为“未挂过回调”。 */
static void scr_guard_child_del_cb(lv_event_t *e)
{
    lv_obj_t *dying = lv_event_get_target(e);
    size_t i;

    for (i = 0; i < CHILD_CNT; i++) {
        if (*s_child_slots[i] == dying) {
            *s_child_slots[i] = NULL;
        }
        if (s_child_guarded[i] == dying) {
            s_child_guarded[i] = NULL;
        }
    }
}

/* 给每个新成为当前活动屏的屏挂上删除回调，并给当前有效的被守护子控件补挂删除回调。
 * 关键：注册对象取自 lv_scr_act()/有效子控件，绝不会是野指针；而“成为活动屏/刚建好”
 * 必然早于“被切走删除”，所以删除回调一定在对象被删前就位。 */
static void scr_guard_poll_cb(lv_timer_t *timer)
{
    lv_obj_t *act = lv_scr_act();
    size_t i;

    LV_UNUSED(timer);

    if (act == NULL) {
        return;
    }

    /* 给被守护的子控件挂"删除即置 NULL"回调。每次宿主屏重建都是新对象，需重挂；
     * 静止时这里只是几次指针比较，零开销。
     * lv_obj_is_valid 只比地址：正常流程下 *slot 要么是有效新对象、要么已被置 NULL，
     * 即便偶发野指针也只是最坏多挂一个无害回调，不会崩。 */
    for (i = 0; i < CHILD_CNT; i++) {
        lv_obj_t *ch = *s_child_slots[i];
        if (ch != NULL && ch != s_child_guarded[i] && lv_obj_is_valid(ch)) {
            lv_obj_add_event_cb(ch, scr_guard_child_del_cb, LV_EVENT_DELETE, NULL);
            s_child_guarded[i] = ch;
        }
    }

    if (act == s_guarded) {
        return;
    }

    lv_obj_add_event_cb(act, scr_guard_del_cb, LV_EVENT_DELETE, NULL);
    s_guarded = act;
}
