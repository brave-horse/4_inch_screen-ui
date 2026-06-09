#include "lvgl.h"
#include "gui_guider.h"
#include "HWDataAccess.h"
#include "device_management.h"

/* ── 单槽位: 开关 imgbtn + 开指示灯 + 关遮罩 ── */
typedef struct {
    lv_obj_t *sw;     /* 开关 imgbtn (CHECKABLE) */
    lv_obj_t *on;     /* 开指示灯(开=COVER, 关=TRANSP) */
    lv_obj_t *off;    /* 关遮罩  (开=TRANSP, 关=COVER) */
    uint8_t (*is_on)(void);
    void    (*set_on)(bool on);
} DevSlot;

/* ═══════════ CT灯回调 ═══════════ */
static uint8_t ct_is_on(void)        { return HWInterface.LightCT.switch_status; }
static void    ct_set_on(bool on)    { HWInterface.LightCT.SetOnOff(on); }

/* ═══════════ 槽位表: 添加新设备只需加一行 ═══════════ */
static DevSlot g_slots[DEV_SLOT_COUNT] = {
    [DEV_SLOT_CT_LIGHT] = {
        .sw     = NULL,  /* guider_ui 在 custom_init 之后才有, load 时再填 */
        .on     = NULL,
        .off    = NULL,
        .is_on  = ct_is_on,
        .set_on = ct_set_on,
    },
};

//绑定控件
static void slot_bind(DevSlot *slot,
                      lv_obj_t *sw, lv_obj_t *on, lv_obj_t *off)
{
    slot->sw  = sw;
    slot->on  = on;
    slot->off = off;
}

//访问中间层同步ui控件
static void slot_refresh(DevSlot *slot)
{
    if (!slot || !slot->sw) return;
    bool on = slot->is_on();

    if (on) lv_obj_add_state(slot->sw, LV_STATE_CHECKED);
    else    lv_obj_clear_state(slot->sw, LV_STATE_CHECKED);

    if (slot->on)  lv_obj_set_style_img_opa(slot->on,
                    on ? LV_OPA_COVER : LV_OPA_TRANSP,
                    LV_PART_MAIN | LV_STATE_DEFAULT);
    if (slot->off) lv_obj_set_style_img_opa(slot->off,
                    on ? LV_OPA_TRANSP : LV_OPA_COVER,
                    LV_PART_MAIN | LV_STATE_DEFAULT);
}

/* ═══════════ 对外接口(供 GUI-Guider 事件调用) ═══════════ */

void dev_mgmt_on_load(void)
{
    /* 绑定控控件到槽位 */
    slot_bind(&g_slots[DEV_SLOT_CT_LIGHT],
              guider_ui.device_management_screen_Light_CT_on_off_1_img,
              guider_ui.device_management_screen_sdev_on,
              guider_ui.device_management_screen_small_dev_off_img);

    

    /* 刷新全部槽位 */
    for (int i = 0; i < DEV_SLOT_COUNT; i++) {
        slot_refresh(&g_slots[i]);
    }
}

void dev_mgmt_ct_on_toggle(void)
{
    DevSlot *slot = &g_slots[DEV_SLOT_CT_LIGHT];
    if (!slot->sw) return;
    bool on = lv_obj_has_state(slot->sw, LV_STATE_CHECKED);
    slot->set_on(on);
    slot_refresh(slot);
}
