#include "lvgl.h"
#include "gui_guider.h"
#include "HWDataAccess.h"
#include "hw_cloud_task.h"
#include "RGBLight.h"

static uint32_t s_bri_tick;
static uint32_t s_color_tick;
static uint16_t s_color_pos;            /* 颜色滑条位置, 切屏后回填 */
#define APPLY_MIN_MS  50
#define RGB_SEG_LEN   256
#define RGB_POS_MAX   (RGB_SEG_LEN * 3 - 1)   /* 767: 红→绿→蓝→红 三段 */

/* 滑条位置 → RGB(至多两原色交叉叠加) */
static void rgb_pos_to_color(uint32_t pos, uint8_t *r, uint8_t *g, uint8_t *b)
{
    uint32_t seg  = pos / RGB_SEG_LEN;
    if (seg > 2) seg = 2;
    uint32_t frac = pos - seg * RGB_SEG_LEN;
    switch (seg) {
    case 0:  *r = 255 - frac; *g = frac;       *b = 0;          break;  /* 红→绿 */
    case 1:  *r = 0;          *g = 255 - frac; *b = frac;       break;  /* 绿→蓝 */
    default: *r = frac;       *g = 0;          *b = 255 - frac; break;  /* 蓝→红 */
    }
}

static void rgb_light_apply_light(void)
{
    lv_obj_t *slider1 = guider_ui.RGBLight_slider_1;
    lv_obj_t *slider2 = guider_ui.RGBLight_slider_2;
    if (!lv_obj_is_valid(slider1) || !lv_obj_is_valid(slider2))
        return;

    int32_t bri = lv_slider_get_value(slider1);
    uint8_t r, g, b;
    rgb_pos_to_color((uint32_t)lv_slider_get_value(slider2), &r, &g, &b);

    uint8_t opa_r = (uint8_t)((uint32_t)r * bri / LIGHTCT_BRIGHTNESS_MAX);
    uint8_t opa_g = (uint8_t)((uint32_t)g * bri / LIGHTCT_BRIGHTNESS_MAX);
    uint8_t opa_b = (uint8_t)((uint32_t)b * bri / LIGHTCT_BRIGHTNESS_MAX);
    if (!HWInterface.LightCT.switch_status)
        opa_r = opa_g = opa_b = 0;

    lv_obj_set_style_img_opa(guider_ui.RGBLight_Red,   opa_r, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(guider_ui.RGBLight_Green, opa_g, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(guider_ui.RGBLight_Blue,  opa_b, LV_PART_MAIN | LV_STATE_DEFAULT);

    char buf[32];
    lv_snprintf(buf, sizeof(buf), "亮 度 | %d%%", (int)bri);
    lv_label_set_text(guider_ui.RGBLight_label_1, buf);
    lv_snprintf(buf, sizeof(buf), "颜 色 | #%02X%02X%02X", r, g, b);
    lv_label_set_text(guider_ui.RGBLight_label_2, buf);
}

/* 共用: 刷灯光图+标签+开关UI */
static void rgb_light_refresh(bool btn_status)
{
    rgb_light_apply_light();

    if (btn_status) lv_obj_add_state(guider_ui.RGBLight_on_off_2_img, LV_STATE_CHECKED);
    else            lv_obj_clear_state(guider_ui.RGBLight_on_off_2_img, LV_STATE_CHECKED);

    if (btn_status) {
        lv_obj_set_style_bg_opa(guider_ui.RGBLight_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_move_background(guider_ui.RGBLight_cont_1);
    } else {
        lv_obj_set_style_bg_opa(guider_ui.RGBLight_cont_1, 162, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_move_foreground(guider_ui.RGBLight_cont_1);
        lv_obj_move_foreground(guider_ui.RGBLight_on_off_2_img);
    }
}

/* ══════ 4 个事件接口(供 GUI-Guider 事件一行调用) ══════ */

void rgb_light_on_screen_load(void)
{
    lv_slider_set_range(guider_ui.RGBLight_slider_2, 0, RGB_POS_MAX);
    lv_slider_set_value(guider_ui.RGBLight_slider_1, HWInterface.LightCT.brightness, LV_ANIM_OFF);
    lv_slider_set_value(guider_ui.RGBLight_slider_2, s_color_pos, LV_ANIM_OFF);
    rgb_light_refresh(HWInterface.LightCT.switch_status);
}

void rgb_light_on_switch_toggle(lv_event_t *e)
{
    lv_obj_t *btn = lv_event_get_target(e);
    bool btn_status = lv_obj_has_state(btn, LV_STATE_CHECKED);

    HWInterface.LightCT.SetOnOff(btn_status);
    hw_cloud_post(&(HW_Msg){ .type = HW_MSG_LIGHT_RGB_SWITCH, .on = btn_status });
    rgb_light_refresh(btn_status);
}

void rgb_light_on_bri_slider_change(void)
{
    HWInterface.LightCT.SetBrightness((uint16_t)lv_slider_get_value(guider_ui.RGBLight_slider_1));
    rgb_light_apply_light();
    if (lv_tick_elaps(s_bri_tick) >= APPLY_MIN_MS) {
        s_bri_tick = lv_tick_get();
        hw_cloud_post(&(HW_Msg){ .type = HW_MSG_LIGHT_CT_BRI, .val = HWInterface.LightCT.brightness });
    }
}

void rgb_light_on_color_slider_change(void)
{
    s_color_pos = (uint16_t)lv_slider_get_value(guider_ui.RGBLight_slider_2);
    rgb_light_apply_light();
    if (lv_tick_elaps(s_color_tick) >= APPLY_MIN_MS) {
        s_color_tick = lv_tick_get();
        uint8_t r, g, b;
        rgb_pos_to_color(s_color_pos, &r, &g, &b);
        uint16_t rgb565 = (uint16_t)(((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3));
        hw_cloud_post(&(HW_Msg){ .type = HW_MSG_LIGHT_RGB_COLOR, .val = rgb565 });
    }
}
