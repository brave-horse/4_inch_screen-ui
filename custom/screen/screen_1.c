/*********************
 *      INCLUDES
 *********************/
#include <stdbool.h>
#include "lvgl.h"
#include "screen.h"
#include "gui_guider.h"
/* 注: lvgl.h / gui_guider.h 在 make 构建里有 -I 路径(同 screen5.c), 能正常编;
 *     IDE 若报"无法打开"是 c_cpp_properties 的 includePath 没配, 非编译错误。 */

/*===========================================================================
 *  screen_1 自定义逻辑
 *
 *  结构: 一个"基础设施区"(轮询发现 screen_1 被 auto_del 重建) + 若干"设备区块"。
 *  每个设备区块自成一体(状态 / apply / 事件回调 / bind, 含自去重), 方便整块复制。
 *
 *  ── 新增一个设备的步骤 ──
 *   1) 复制下面任意一个 "===== 设备 =====" 区块, 整块改名(如 lightct → xxx);
 *   2) 改成该设备的控件名与刷新逻辑;
 *   3) 在 screen_1_poll_cb() 的派发处加一行 screen_1_xxx_bind();
 *===========================================================================*/

/*===========================================================================
 *  基础设施: 轮询 + 派发
 *===========================================================================*/

/* 轮询周期: 用来发现 screen_1 被 auto_del 重建(控件指针变新)后, 给新控件初始化+挂回调。
 * 静止时只是几次指针比较, 开销可忽略(同 screen5 / scr_noscroll)。 */
#define SCREEN_1_POLL_PERIOD_MS  30

/* 各设备区块的"建屏后绑定"入口(定义见各自区块)。新增设备在这里加一行声明。 */
static void screen_1_lightct_bind(void);

/* 只要 screen_1 是当前活动屏, 就逐个设备尝试绑定; 每个 *_bind() 内部自去重——
 * 控件没换新就只是几次指针比较直接返回, 换了新对象(重建)才真正初始化+挂回调。 */
static void screen_1_poll_cb(lv_timer_t *timer)
{
    LV_UNUSED(timer);

    if (lv_scr_act() != guider_ui.screen_1) {
        return;                         /* 当前活动屏不是 screen_1 */
    }

    screen_1_lightct_bind();
    /* 新增设备: screen_1_xxx_bind(); */
}

void screen_1_custom_init(void)
{
    lv_timer_create(screen_1_poll_cb, SCREEN_1_POLL_PERIOD_MS, NULL);
}

/*===========================================================================
 *  LightCT(色温灯)
 *    开关: CT_on_off_1_img(CHECKABLE imgbtn)
 *    关态视觉: small_dev_off_img  —— 关→100%显示, 开→0%隐藏
 *    状态变量: s_lightct_on (后续并入两屏共享的 HWInterface.LightCT.switch_status)
 *===========================================================================*/

/* 开/关取值——不用裸 0/1, 用宏一眼看懂。 */
#define LIGHTCT_OFF   false   /* 关 */
#define LIGHTCT_ON    true    /* 开 */

/* 色温灯开/关状态。默认 LIGHTCT_OFF(关), 与开关控件默认未 checked 一致。
 * 后续要统一成两屏共享的 HWInterface.LightCT.switch_status(共享模块还没放进来): screen_1 与
 * screen_5 的开关读写同一份, 实现两屏一致。届时把这里对接/替换为那一份。 */
static bool s_lightct_on = LIGHTCT_OFF;

/* 本设备已绑定过的开关实例(自去重)。仅指针比较, 从不解引用, 屏删除后变野也安全。 */
static lv_obj_t *s_lightct_bound_sw;

/* 按开关状态刷新 small_dev_off_img(关态小图) 的透明度:
 *   关(LIGHTCT_OFF) → LV_OPA_COVER (100%, 显示)
 *   开(LIGHTCT_ON)  → LV_OPA_TRANSP(0%,  隐藏) */
static void screen_1_apply_lightct(void)
{
    lv_opa_t  opa     = (s_lightct_on == LIGHTCT_OFF) ? LV_OPA_COVER : LV_OPA_TRANSP;
    lv_obj_t *dev_off = guider_ui.screen_1_small_dev_off_img;

    if (lv_obj_is_valid(dev_off)) {
        lv_obj_set_style_img_opa(dev_off, opa, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
}

/* 按下开关(CHECKABLE imgbtn toggle 发 VALUE_CHANGED): 同步开关变量 + 刷新关态小图。 */
static void screen_1_lightct_switch_cb(lv_event_t *e)
{
    lv_obj_t *sw = lv_event_get_target(e);

    s_lightct_on = lv_obj_has_state(sw, LV_STATE_CHECKED) ? LIGHTCT_ON : LIGHTCT_OFF;
    screen_1_apply_lightct();
}



















/* 建屏/重建后(由 poll 调): 把开关初始化为关 + 挂回调 + 按初值刷新一次。
 * 自去重: 开关控件没换新就直接返回, 不重复做。 */
static void screen_1_lightct_bind(void)
{
    lv_obj_t *sw = guider_ui.screen_1_CT_on_off_1_img;

    if (sw == NULL || !lv_obj_is_valid(sw)) {
        return;
    }
    if (!lv_obj_check_type(sw, &lv_imgbtn_class)) {
        return;                         /* 防地址复用误判成别的控件 */
    }
    if (sw == s_lightct_bound_sw) {
        return;                         /* 本实例已绑定过 */
    }

    /* 初始化为关(清 checked), 并把初值同步给开关变量。
     * (programmatic 清 state 不触发 VALUE_CHANGED, 且此时还没挂回调, 不会误更新。) */
    lv_obj_clear_state(sw, LV_STATE_CHECKED);
    s_lightct_on = LIGHTCT_OFF;

    /* 挂回调 + 记下本实例(去重) + 按初值刷新一次。 */
    lv_obj_add_event_cb(sw, screen_1_lightct_switch_cb, LV_EVENT_VALUE_CHANGED, NULL);
    s_lightct_bound_sw = sw;
    screen_1_apply_lightct();
}
