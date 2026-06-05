/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

#include "HWDataAccess.h"
#include "HWDataAccess.h"
#include "HWDataAccess.h"
#include "HWDataAccess.h"
static uint32_t s_ct_apply_tick2;
#include "HWDataAccess.h"
static uint32_t s_ct_apply_tick;
#include "HWDataAccess.h"

static void screen_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSING:
    {

        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_1, guider_ui.screen_1_del, &guider_ui.screen_del, setup_scr_screen_1, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void screen_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_4, guider_ui.screen_4_del, &guider_ui.screen_del, setup_scr_screen_4, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen, screen_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_btn_1, screen_btn_1_event_handler, LV_EVENT_ALL, ui);
}

static void screen_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        /* 进屏初始化: 从中间层读色温灯开关真值, 摆正开关 CHECKED + small_dev_off 透明度。 */
        bool light_on = HWInterface.LightCT.switch_status;   /* true=开, false=关 */

        /* 开关图标 CHECKED 摆到当前状态 */
        if (light_on) lv_obj_add_state(guider_ui.screen_1_Light_CT_on_off_1_img, LV_STATE_CHECKED);
        else          lv_obj_clear_state(guider_ui.screen_1_Light_CT_on_off_1_img, LV_STATE_CHECKED);

        /* small_dev_off: 开→LV_OPA_TRANSP(0%, 隐藏), 关→LV_OPA_COVER(100%, 显示) */
        lv_obj_set_style_img_opa(guider_ui.screen_1_small_dev_off_img,
                                 light_on ? LV_OPA_TRANSP : LV_OPA_COVER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);

        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_2, guider_ui.screen_2_del, &guider_ui.screen_1_del, setup_scr_screen_2, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen, guider_ui.screen_del, &guider_ui.screen_1_del, setup_scr_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void screen_1_cont_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_5, guider_ui.screen_5_del, &guider_ui.screen_1_del, setup_scr_screen_5, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void screen_1_Light_CT_on_off_1_img_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        /* 点开关 → 读它点击后的新状态 → 写回中间层 → 刷 small_dev_off 透明度。 */
        lv_obj_t *btn = lv_event_get_target(e);                    /* 触发事件的开关本身 */
        bool light_on = lv_obj_has_state(btn, LV_STATE_CHECKED);   /* 有CHECKED=开, 没有=关 */

        HWInterface.LightCT.SetOnOff(light_on);   /* 写回中间层: 开→true, 关→false; 与 screen_5 共享同一份 */

        /* small_dev_off: 开→LV_OPA_TRANSP(0%, 隐藏), 关→LV_OPA_COVER(100%, 显示) */
        lv_obj_set_style_img_opa(guider_ui.screen_1_small_dev_off_img,
                                 light_on ? LV_OPA_TRANSP : LV_OPA_COVER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
        break;
    }
    default:
        break;
    }
}

static void screen_1_small_dev_off_img_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_5, guider_ui.screen_5_del, &guider_ui.screen_1_del, setup_scr_screen_5, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void screen_1_label_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_5, guider_ui.screen_5_del, &guider_ui.screen_1_del, setup_scr_screen_5, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_1 (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_1, screen_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_1_cont_1, screen_1_cont_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_1_Light_CT_on_off_1_img, screen_1_Light_CT_on_off_1_img_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_1_small_dev_off_img, screen_1_small_dev_off_img_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_1_label_2, screen_1_label_2_event_handler, LV_EVENT_ALL, ui);
}

static void screen_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_3, guider_ui.screen_3_del, &guider_ui.screen_2_del, setup_scr_screen_3, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_1, guider_ui.screen_1_del, &guider_ui.screen_2_del, setup_scr_screen_1, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_screen_2 (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_2, screen_2_event_handler, LV_EVENT_ALL, ui);
}

static void screen_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_2, guider_ui.screen_2_del, &guider_ui.screen_3_del, setup_scr_screen_2, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_screen_3 (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_3, screen_3_event_handler, LV_EVENT_ALL, ui);
}

static void screen_4_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen, guider_ui.screen_del, &guider_ui.screen_4_del, setup_scr_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_4 (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_4_btn_1, screen_4_btn_1_event_handler, LV_EVENT_ALL, ui);
}

static void screen_5_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.screen_5_label_2, 600, 0, lv_obj_get_x(guider_ui.screen_5_label_2), 70, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        ui_animation(guider_ui.screen_5_slider_1, 600, 0, lv_obj_get_x(guider_ui.screen_5_slider_1), 70, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        ui_animation(guider_ui.screen_5_slider_2, 600, 0, lv_obj_get_x(guider_ui.screen_5_slider_2), 70, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        ui_animation(guider_ui.screen_5_label_1, 600, 0, lv_obj_get_x(guider_ui.screen_5_label_1), 70, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        /* 进屏初始化: 从中间层 HWInterface.LightCT 读全部状态(开关/亮度/色温), 把整屏画对, 不信 GUI Guider 默认态。 */
        bool     light_on   = HWInterface.LightCT.switch_status;   /* 开/关 */
        uint16_t brightness = HWInterface.LightCT.brightness;      /* 亮度 0..100 */
        uint16_t color_temp = HWInterface.LightCT.color_temp;      /* 色温 2700..6500 */

        /* 1. 两条 slider 摆到中间层的值(set_value 是程序设值, 不触发 value_changed, 不会回写中间层) */
        lv_slider_set_value(guider_ui.screen_5_slider_1, brightness, LV_ANIM_OFF);
        lv_slider_set_value(guider_ui.screen_5_slider_2, color_temp, LV_ANIM_OFF);

        /* 2. 按亮度+色温刷白/橙灯光图透明度 + 两个标签数字(公式同 slider 事件; 量程用 HWDataAccess.h 的宏) */
        uint32_t ct_span  = LIGHTCT_COLOR_TEMP_MAX - LIGHTCT_COLOR_TEMP_MIN;                 /* 3800 */
        uint32_t tnum     = (uint32_t)(color_temp - LIGHTCT_COLOR_TEMP_MIN);                 /* = T*ct_span */
        uint32_t o_white  = (uint32_t)brightness * tnum             * LV_OPA_COVER / ((uint32_t)LIGHTCT_BRIGHTNESS_MAX * ct_span);
        uint32_t o_orange = (uint32_t)brightness * (ct_span - tnum) * LV_OPA_COVER / ((uint32_t)LIGHTCT_BRIGHTNESS_MAX * ct_span);
        lv_obj_set_style_img_opa(guider_ui.screen_5_dev_white_img,  (lv_opa_t)o_white,  LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_img_opa(guider_ui.screen_5_dev_orange_img, (lv_opa_t)o_orange, LV_PART_MAIN | LV_STATE_DEFAULT);

        char buf[32];
        lv_snprintf(buf, sizeof(buf), "亮 度 | %d%%", (int)brightness);
        lv_label_set_text(guider_ui.screen_5_label_1, buf);
        lv_snprintf(buf, sizeof(buf), "色 温 | %dK", (int)color_temp);
        lv_label_set_text(guider_ui.screen_5_label_2, buf);

        /* 3. 开关 CHECKED + 遮罩 cont_1 按开关态摆正 */
        if (light_on) lv_obj_add_state(guider_ui.screen_5_Light_CT_on_off_2_img, LV_STATE_CHECKED);
        else          lv_obj_clear_state(guider_ui.screen_5_Light_CT_on_off_2_img, LV_STATE_CHECKED);

        if (light_on) {
            lv_obj_set_style_bg_opa(guider_ui.screen_5_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_move_background(guider_ui.screen_5_cont_1);
        } else {
            lv_obj_set_style_bg_opa(guider_ui.screen_5_cont_1, 162, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_move_foreground(guider_ui.screen_5_cont_1);
            lv_obj_move_foreground(guider_ui.screen_5_Light_CT_on_off_2_img);
        }
        break;
    }
    default:
        break;
    }
}

static void screen_5_slider_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        int32_t bri = lv_slider_get_value(guider_ui.screen_5_slider_1);   /* 亮度 0..100 */
        int32_t ct  = lv_slider_get_value(guider_ui.screen_5_slider_2);   /* 色温 2700..6500 */

        HWInterface.LightCT.SetColorTemp((uint16_t)ct);   /* 每次都写回中间层(很轻, 不节流), 数据始终最新 */

        /* 只对"重绘两张旋转灯光图"节流(重绘很重), 最多每 50ms 一次 */
        const uint32_t APPLY_MIN_MS = 50;
        if (lv_tick_elaps(s_ct_apply_tick2) >= APPLY_MIN_MS) {
            s_ct_apply_tick2 = lv_tick_get();

            const int32_t CT_MIN  = 2700;
            const int32_t CT_SPAN = 3800;
            const int32_t BRI_MAX = 100;
            uint32_t tnum     = (uint32_t)(ct - CT_MIN);
            uint32_t o_white  = (uint32_t)bri * tnum            * LV_OPA_COVER / ((uint32_t)BRI_MAX * CT_SPAN);
            uint32_t o_orange = (uint32_t)bri * (CT_SPAN - tnum) * LV_OPA_COVER / ((uint32_t)BRI_MAX * CT_SPAN);
            lv_obj_set_style_img_opa(guider_ui.screen_5_dev_white_img,  (lv_opa_t)o_white,  LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(guider_ui.screen_5_dev_orange_img, (lv_opa_t)o_orange, LV_PART_MAIN | LV_STATE_DEFAULT);
        }

        break;
    }
    default:
        break;
    }
}

static void screen_5_slider_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        int32_t bri = lv_slider_get_value(guider_ui.screen_5_slider_1);   /* 亮度 0..100 */
        int32_t ct  = lv_slider_get_value(guider_ui.screen_5_slider_2);   /* 色温 2700..6500 */

        HWInterface.LightCT.SetBrightness((uint16_t)bri);   /* 每次都写回中间层(很轻, 不节流), 数据始终最新 */

        /* 只对"重绘两张旋转灯光图"节流(重绘很重), 最多每 50ms 一次 */
        const uint32_t APPLY_MIN_MS = 50;
        if (lv_tick_elaps(s_ct_apply_tick) >= APPLY_MIN_MS) {
            s_ct_apply_tick = lv_tick_get();

            const int32_t CT_MIN  = 2700;   /* 色温最左(K) */
            const int32_t CT_SPAN = 3800;   /* 6500-2700 */
            const int32_t BRI_MAX = 100;
            uint32_t tnum     = (uint32_t)(ct - CT_MIN);
            uint32_t o_white  = (uint32_t)bri * tnum            * LV_OPA_COVER / ((uint32_t)BRI_MAX * CT_SPAN);
            uint32_t o_orange = (uint32_t)bri * (CT_SPAN - tnum) * LV_OPA_COVER / ((uint32_t)BRI_MAX * CT_SPAN);
            lv_obj_set_style_img_opa(guider_ui.screen_5_dev_white_img,  (lv_opa_t)o_white,  LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(guider_ui.screen_5_dev_orange_img, (lv_opa_t)o_orange, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        break;
    }
    default:
        break;
    }
}

static void screen_5_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_1, guider_ui.screen_1_del, &guider_ui.screen_5_del, setup_scr_screen_1, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void screen_5_Light_CT_on_off_2_img_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        /* 点开关 → 读它点击后的新状态 → 写回中间层 → 按新态刷遮罩。 */
        lv_obj_t *btn = lv_event_get_target(e);                    /* 触发事件的开关本身 */
        bool light_on = lv_obj_has_state(btn, LV_STATE_CHECKED);   /* 点击后: 有CHECKED=开, 没有=关 */

        HWInterface.LightCT.SetOnOff(light_on);                    /* 写回中间层(内部有变化才置 changed) */

        /* 遮罩 cont_1 按新状态显示(与进屏初始化里同一套逻辑) */
        if (light_on) {
            lv_obj_set_style_bg_opa(guider_ui.screen_5_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_move_background(guider_ui.screen_5_cont_1);
        } else {
            lv_obj_set_style_bg_opa(guider_ui.screen_5_cont_1, 162, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_move_foreground(guider_ui.screen_5_cont_1);
            lv_obj_move_foreground(btn);
        }
        break;
    }
    default:
        break;
    }
}

void events_init_screen_5 (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_5, screen_5_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_5_slider_2, screen_5_slider_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_5_slider_1, screen_5_slider_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_5_btn_1, screen_5_btn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_5_Light_CT_on_off_2_img, screen_5_Light_CT_on_off_2_img_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
