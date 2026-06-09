/*********************
 *      INCLUDES
 *********************/
#include "lvgl.h"
#include "gui_guider.h"
#include "HWDataAccess.h"
#include "hw_cloud_task.h"
#include "light_CT_screen.h"
#include "LEDStrip.h"

/**********************
 *  STATIC VARIABLES
 **********************/
static uint32_t s_bri_tick;
static uint32_t s_ct_tick;
#define APPLY_MIN_MS  50

/**********************
 *  GLOBAL FUNCTIONS
 **********************/

static void led_strip_apply_light(void)
{
    lv_obj_t *slider1 = guider_ui.LedStrip_slider_1;
    lv_obj_t *slider2 = guider_ui.LedStrip_slider_2;
    if (!lv_obj_is_valid(slider1) || !lv_obj_is_valid(slider2))
        return;

    int32_t  bri = lv_slider_get_value(slider1);
    int32_t  ct  = lv_slider_get_value(slider2);
    uint32_t ct_span  = LIGHTCT_COLOR_TEMP_MAX - LIGHTCT_COLOR_TEMP_MIN;
    uint32_t tnum     = (uint32_t)(ct - LIGHTCT_COLOR_TEMP_MIN);
    uint32_t o_white  = (uint32_t)bri * tnum             * LV_OPA_COVER / ((uint32_t)LIGHTCT_BRIGHTNESS_MAX * ct_span);
    uint32_t o_orange = (uint32_t)bri * (ct_span - tnum) * LV_OPA_COVER / ((uint32_t)LIGHTCT_BRIGHTNESS_MAX * ct_span);

    lv_obj_set_style_img_opa(guider_ui.LedStrip_LSOff, (lv_opa_t)o_white,  LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(guider_ui.LedStrip_LSOn,  (lv_opa_t)o_orange, LV_PART_MAIN | LV_STATE_DEFAULT);

    char buf[32];
    lv_snprintf(buf, sizeof(buf), "亮 度 | %d%%", (int)bri);
    lv_label_set_text(guider_ui.LedStrip_label_1, buf);
    lv_snprintf(buf, sizeof(buf), "色 温 | %dK", (int)ct);
    lv_label_set_text(guider_ui.LedStrip_label_2, buf);
}

static void led_strip_refresh(bool btn_status)
{
    led_strip_apply_light();

    if (btn_status) lv_obj_add_state(guider_ui.LedStrip_on_off_2_img, LV_STATE_CHECKED);
    else            lv_obj_clear_state(guider_ui.LedStrip_on_off_2_img, LV_STATE_CHECKED);

    if (btn_status) {
        lv_obj_set_style_bg_opa(guider_ui.LedStrip_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_move_background(guider_ui.LedStrip_cont_1);
    } else {
        lv_obj_set_style_bg_opa(guider_ui.LedStrip_cont_1, 162, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_move_foreground(guider_ui.LedStrip_cont_1);
        lv_obj_move_foreground(guider_ui.LedStrip_on_off_2_img);
    }
}

/* ══════ 4 个事件接口(供 GUI-Guider 事件一行调用) ══════ */

void led_strip_on_screen_load(void)
{
    bool btn_status = HWInterface.LightCT.switch_status;
    lv_slider_set_value(guider_ui.LedStrip_slider_1, HWInterface.LightCT.brightness, LV_ANIM_OFF);
    lv_slider_set_value(guider_ui.LedStrip_slider_2, HWInterface.LightCT.color_temp, LV_ANIM_OFF);
    led_strip_refresh(btn_status);
}

void led_strip_on_switch_toggle(lv_event_t *e)
{
    lv_obj_t *btn = lv_event_get_target(e);
    bool btn_status = lv_obj_has_state(btn, LV_STATE_CHECKED);

    HWInterface.LightCT.SetOnOff(btn_status);
    hw_cloud_post(&(HW_Msg){
        .type = HW_MSG_LIGHT_CT_SWITCH,
        .on   = btn_status
    });
    led_strip_refresh(btn_status);
}

void led_strip_on_bri_slider_change(void)
{
    HWInterface.LightCT.SetBrightness((uint16_t)lv_slider_get_value(guider_ui.LedStrip_slider_1));
    if (lv_tick_elaps(s_bri_tick) >= APPLY_MIN_MS) {
        s_bri_tick = lv_tick_get();
        hw_cloud_post(&(HW_Msg){
            .type = HW_MSG_LIGHT_CT_BRI,
            .val  = HWInterface.LightCT.brightness
        });
        led_strip_apply_light();
    }
}

void led_strip_on_ct_slider_change(void)
{
    HWInterface.LightCT.SetColorTemp((uint16_t)lv_slider_get_value(guider_ui.LedStrip_slider_2));
    if (lv_tick_elaps(s_ct_tick) >= APPLY_MIN_MS) {
        s_ct_tick = lv_tick_get();
        hw_cloud_post(&(HW_Msg){
            .type = HW_MSG_LIGHT_CT_CT,
            .val  = HWInterface.LightCT.color_temp
        });
        led_strip_apply_light();
    }
}
