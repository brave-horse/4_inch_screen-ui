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
#include "screen.h"
#include "HWDataAccess.h"
#include "screen.h"
static uint32_t s_ct_apply_tick2;
#include "HWDataAccess.h"
#include "screen.h"
static uint32_t s_ct_apply_tick;

#include "HWDataAccess.h"
#include "screen.h"

static void ui_home_screen_event_handler (lv_event_t *e)
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
            ui_load_scr_animation(&guider_ui, &guider_ui.device_management_screen, guider_ui.device_management_screen_del, &guider_ui.ui_home_screen_del, setup_scr_device_management_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
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

static void ui_home_screen_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.setting_screen, guider_ui.setting_screen_del, &guider_ui.ui_home_screen_del, setup_scr_setting_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_ui_home_screen (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->ui_home_screen, ui_home_screen_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_home_screen_btn_1, ui_home_screen_btn_1_event_handler, LV_EVENT_ALL, ui);
}

static void device_management_screen_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        /* 进屏初始化: 从中间层读色温灯开关真值, 摆正开关 CHECKED + small_dev_off 透明度。 */
        bool light_on = HWInterface.LightCT.switch_status;   /* true=开, false=关 */

        /* 开关图标 CHECKED 摆到当前状态 */
        if (light_on) lv_obj_add_state(guider_ui.device_management_screen_Light_CT_on_off_1_img, LV_STATE_CHECKED);
        else          lv_obj_clear_state(guider_ui.device_management_screen_Light_CT_on_off_1_img, LV_STATE_CHECKED);

        /* small_dev_off: 开→LV_OPA_TRANSP(0%, 隐藏), 关→LV_OPA_COVER(100%, 显示) */
        lv_obj_set_style_img_opa(guider_ui.device_management_screen_small_dev_off_img,
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
            ui_load_scr_animation(&guider_ui, &guider_ui.light_scence_screen, guider_ui.light_scence_screen_del, &guider_ui.device_management_screen_del, setup_scr_light_scence_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.ui_home_screen, guider_ui.ui_home_screen_del, &guider_ui.device_management_screen_del, setup_scr_ui_home_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
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

static void device_management_screen_cont_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.light_CT_screen, guider_ui.light_CT_screen_del, &guider_ui.device_management_screen_del, setup_scr_light_CT_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_Light_CT_on_off_1_img_event_handler (lv_event_t *e)
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
        lv_obj_set_style_img_opa(guider_ui.device_management_screen_small_dev_off_img,
                                 light_on ? LV_OPA_TRANSP : LV_OPA_COVER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_small_dev_off_img_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.light_CT_screen, guider_ui.light_CT_screen_del, &guider_ui.device_management_screen_del, setup_scr_light_CT_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_label_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.light_CT_screen, guider_ui.light_CT_screen_del, &guider_ui.device_management_screen_del, setup_scr_light_CT_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_device_management_screen (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->device_management_screen, device_management_screen_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_cont_1, device_management_screen_cont_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_Light_CT_on_off_1_img, device_management_screen_Light_CT_on_off_1_img_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_small_dev_off_img, device_management_screen_small_dev_off_img_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_label_2, device_management_screen_label_2_event_handler, LV_EVENT_ALL, ui);
}

static void light_scence_screen_event_handler (lv_event_t *e)
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
            ui_load_scr_animation(&guider_ui, &guider_ui.curtain_scene_screen, guider_ui.curtain_scene_screen_del, &guider_ui.light_scence_screen_del, setup_scr_curtain_scene_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.device_management_screen, guider_ui.device_management_screen_del, &guider_ui.light_scence_screen_del, setup_scr_device_management_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
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

void events_init_light_scence_screen (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->light_scence_screen, light_scence_screen_event_handler, LV_EVENT_ALL, ui);
}

static void curtain_scene_screen_event_handler (lv_event_t *e)
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
            ui_load_scr_animation(&guider_ui, &guider_ui.light_scence_screen, guider_ui.light_scence_screen_del, &guider_ui.curtain_scene_screen_del, setup_scr_light_scence_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
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

void events_init_curtain_scene_screen (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->curtain_scene_screen, curtain_scene_screen_event_handler, LV_EVENT_ALL, ui);
}

static void setting_screen_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.ui_home_screen, guider_ui.ui_home_screen_del, &guider_ui.setting_screen_del, setup_scr_ui_home_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_setting_screen (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->setting_screen_btn_1, setting_screen_btn_1_event_handler, LV_EVENT_ALL, ui);
}

static void light_CT_screen_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.light_CT_screen_label_2, 600, 0, lv_obj_get_x(guider_ui.light_CT_screen_label_2), 70, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        ui_animation(guider_ui.light_CT_screen_slider_1, 600, 0, lv_obj_get_x(guider_ui.light_CT_screen_slider_1), 70, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        ui_animation(guider_ui.light_CT_screen_slider_2, 600, 0, lv_obj_get_x(guider_ui.light_CT_screen_slider_2), 70, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        ui_animation(guider_ui.light_CT_screen_label_1, 600, 0, lv_obj_get_x(guider_ui.light_CT_screen_label_1), 70, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        bool light_on = HWInterface.LightCT.switch_status;
        lv_slider_set_value(guider_ui.light_CT_screen_slider_1, HWInterface.LightCT.brightness, LV_ANIM_OFF);
        lv_slider_set_value(guider_ui.light_CT_screen_slider_2, HWInterface.LightCT.color_temp, LV_ANIM_OFF);
        light_CT_screen_apply_light();   /* 灯光图(关→0/开→算) + 标签 */

        if (light_on) lv_obj_add_state(guider_ui.light_CT_screen_on_off_2_img, LV_STATE_CHECKED);
        else          lv_obj_clear_state(guider_ui.light_CT_screen_on_off_2_img, LV_STATE_CHECKED);

        if (light_on) {
            lv_obj_set_style_bg_opa(guider_ui.light_CT_screen_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_move_background(guider_ui.light_CT_screen_cont_1);
        } else {
            lv_obj_set_style_bg_opa(guider_ui.light_CT_screen_cont_1, 162, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_move_foreground(guider_ui.light_CT_screen_cont_1);
            lv_obj_move_foreground(guider_ui.light_CT_screen_on_off_2_img);
        }
        break;
    }
    default:
        break;
    }
}

static void light_CT_screen_slider_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        HWInterface.LightCT.SetColorTemp((uint16_t)lv_slider_get_value(guider_ui.light_CT_screen_slider_2));
        const uint32_t APPLY_MIN_MS = 50;
        if (lv_tick_elaps(s_ct_apply_tick2) >= APPLY_MIN_MS) {
            s_ct_apply_tick2 = lv_tick_get();
            light_CT_screen_apply_light();
        }
        break;
    }
    default:
        break;
    }
}

static void light_CT_screen_slider_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        HWInterface.LightCT.SetBrightness((uint16_t)lv_slider_get_value(guider_ui.light_CT_screen_slider_1));  /* 写回中间层(不节流) */
        const uint32_t APPLY_MIN_MS = 50;
        if (lv_tick_elaps(s_ct_apply_tick) >= APPLY_MIN_MS) {   /* 重绘节流 */
            s_ct_apply_tick = lv_tick_get();
            light_CT_screen_apply_light();
        }

        break;
    }
    default:
        break;
    }
}

static void light_CT_screen_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.device_management_screen, guider_ui.device_management_screen_del, &guider_ui.light_CT_screen_del, setup_scr_device_management_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void light_CT_screen_on_off_2_img_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        lv_obj_t *btn = lv_event_get_target(e);
        bool light_on = lv_obj_has_state(btn, LV_STATE_CHECKED);
        HWInterface.LightCT.SetOnOff(light_on);   /* 写回中间层 */
        light_CT_screen_apply_light();                    /* 灯光图: 关→0, 开→按亮度/色温恢复 + 标签 */

        if (light_on) {
            lv_obj_set_style_bg_opa(guider_ui.light_CT_screen_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_move_background(guider_ui.light_CT_screen_cont_1);
        } else {
            lv_obj_set_style_bg_opa(guider_ui.light_CT_screen_cont_1, 162, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_move_foreground(guider_ui.light_CT_screen_cont_1);
            lv_obj_move_foreground(btn);
        }
        break;
    }
    default:
        break;
    }
}

void events_init_light_CT_screen (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->light_CT_screen, light_CT_screen_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->light_CT_screen_slider_2, light_CT_screen_slider_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->light_CT_screen_slider_1, light_CT_screen_slider_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->light_CT_screen_btn_1, light_CT_screen_btn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->light_CT_screen_on_off_2_img, light_CT_screen_on_off_2_img_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
