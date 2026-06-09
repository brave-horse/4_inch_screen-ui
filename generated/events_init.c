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

#include "device_management.h"


#include "light_CT_screen.h"
#include "LEDStrip.h"
#include "MagLight.h"

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
        dev_mgmt_on_load();
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
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
        dev_mgmt_ct_on_toggle();
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

static void device_management_screen_cont_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.LedStrip, guider_ui.LedStrip_del, &guider_ui.device_management_screen_del, setup_scr_LedStrip, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_sLEDStripOn_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.LedStrip, guider_ui.LedStrip_del, &guider_ui.device_management_screen_del, setup_scr_LedStrip, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_sLEDStripOff_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.LedStrip, guider_ui.LedStrip_del, &guider_ui.device_management_screen_del, setup_scr_LedStrip, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_label_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.LedStrip, guider_ui.LedStrip_del, &guider_ui.device_management_screen_del, setup_scr_LedStrip, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_cont_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.MagLight, guider_ui.MagLight_del, &guider_ui.device_management_screen_del, setup_scr_MagLight, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_sMagLightOff_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.MagLight, guider_ui.MagLight_del, &guider_ui.device_management_screen_del, setup_scr_MagLight, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_label_4_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.MagLight, guider_ui.MagLight_del, &guider_ui.device_management_screen_del, setup_scr_MagLight, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_cont_4_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.RGBLight, guider_ui.RGBLight_del, &guider_ui.device_management_screen_del, setup_scr_RGBLight, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_sRGBLightOn_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.RGBLight, guider_ui.RGBLight_del, &guider_ui.device_management_screen_del, setup_scr_RGBLight, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_sRGBLightOff_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.RGBLight, guider_ui.RGBLight_del, &guider_ui.device_management_screen_del, setup_scr_RGBLight, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_label_5_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.RGBLight, guider_ui.RGBLight_del, &guider_ui.device_management_screen_del, setup_scr_RGBLight, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_cont_5_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.FabricCurtian, guider_ui.FabricCurtian_del, &guider_ui.device_management_screen_del, setup_scr_FabricCurtian, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_sFabricCurtainOn_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.FabricCurtian, guider_ui.FabricCurtian_del, &guider_ui.device_management_screen_del, setup_scr_FabricCurtian, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_sFabricCurtianOff_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.FabricCurtian, guider_ui.FabricCurtian_del, &guider_ui.device_management_screen_del, setup_scr_FabricCurtian, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_label_6_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.FabricCurtian, guider_ui.FabricCurtian_del, &guider_ui.device_management_screen_del, setup_scr_FabricCurtian, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_cont_6_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.Sheers, guider_ui.Sheers_del, &guider_ui.device_management_screen_del, setup_scr_Sheers, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_sSheersOn_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.Sheers, guider_ui.Sheers_del, &guider_ui.device_management_screen_del, setup_scr_Sheers, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_sSheersOff_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.Sheers, guider_ui.Sheers_del, &guider_ui.device_management_screen_del, setup_scr_Sheers, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_label_7_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.Sheers, guider_ui.Sheers_del, &guider_ui.device_management_screen_del, setup_scr_Sheers, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_cont_7_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.RollBlind, guider_ui.RollBlind_del, &guider_ui.device_management_screen_del, setup_scr_RollBlind, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_sRollBlindOn_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.RollBlind, guider_ui.RollBlind_del, &guider_ui.device_management_screen_del, setup_scr_RollBlind, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_sRollBlindOff_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.RollBlind, guider_ui.RollBlind_del, &guider_ui.device_management_screen_del, setup_scr_RollBlind, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_label_8_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.RollBlind, guider_ui.RollBlind_del, &guider_ui.device_management_screen_del, setup_scr_RollBlind, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_cont_8_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.Dream, guider_ui.Dream_del, &guider_ui.device_management_screen_del, setup_scr_Dream, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_sDreamOn_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.Dream, guider_ui.Dream_del, &guider_ui.device_management_screen_del, setup_scr_Dream, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_sDreamOff_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.Dream, guider_ui.Dream_del, &guider_ui.device_management_screen_del, setup_scr_Dream, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_label_10_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.Dream, guider_ui.Dream_del, &guider_ui.device_management_screen_del, setup_scr_Dream, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_cont_9_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.AirCondition, guider_ui.AirCondition_del, &guider_ui.device_management_screen_del, setup_scr_AirCondition, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_img_12_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.AirCondition, guider_ui.AirCondition_del, &guider_ui.device_management_screen_del, setup_scr_AirCondition, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_label_9_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.AirCondition, guider_ui.AirCondition_del, &guider_ui.device_management_screen_del, setup_scr_AirCondition, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_cont_11_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.DryRack, guider_ui.DryRack_del, &guider_ui.device_management_screen_del, setup_scr_DryRack, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_sDryRackdown_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.DryRack, guider_ui.DryRack_del, &guider_ui.device_management_screen_del, setup_scr_DryRack, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_sDryRackup_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.Music, guider_ui.Music_del, &guider_ui.device_management_screen_del, setup_scr_Music, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_label_11_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.DryRack, guider_ui.DryRack_del, &guider_ui.device_management_screen_del, setup_scr_DryRack, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_label_15_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.AirCondition, guider_ui.AirCondition_del, &guider_ui.device_management_screen_del, setup_scr_AirCondition, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void device_management_screen_label_16_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.AirCondition, guider_ui.AirCondition_del, &guider_ui.device_management_screen_del, setup_scr_AirCondition, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
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
    lv_obj_add_event_cb(ui->device_management_screen_cont_2, device_management_screen_cont_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_sLEDStripOn, device_management_screen_sLEDStripOn_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_sLEDStripOff, device_management_screen_sLEDStripOff_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_label_3, device_management_screen_label_3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_cont_3, device_management_screen_cont_3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_sMagLightOff, device_management_screen_sMagLightOff_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_label_4, device_management_screen_label_4_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_cont_4, device_management_screen_cont_4_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_sRGBLightOn, device_management_screen_sRGBLightOn_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_sRGBLightOff, device_management_screen_sRGBLightOff_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_label_5, device_management_screen_label_5_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_cont_5, device_management_screen_cont_5_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_sFabricCurtainOn, device_management_screen_sFabricCurtainOn_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_sFabricCurtianOff, device_management_screen_sFabricCurtianOff_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_label_6, device_management_screen_label_6_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_cont_6, device_management_screen_cont_6_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_sSheersOn, device_management_screen_sSheersOn_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_sSheersOff, device_management_screen_sSheersOff_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_label_7, device_management_screen_label_7_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_cont_7, device_management_screen_cont_7_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_sRollBlindOn, device_management_screen_sRollBlindOn_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_sRollBlindOff, device_management_screen_sRollBlindOff_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_label_8, device_management_screen_label_8_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_cont_8, device_management_screen_cont_8_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_sDreamOn, device_management_screen_sDreamOn_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_sDreamOff, device_management_screen_sDreamOff_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_label_10, device_management_screen_label_10_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_cont_9, device_management_screen_cont_9_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_img_12, device_management_screen_img_12_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_label_9, device_management_screen_label_9_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_cont_11, device_management_screen_cont_11_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_sDryRackdown, device_management_screen_sDryRackdown_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_sDryRackup, device_management_screen_sDryRackup_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_label_11, device_management_screen_label_11_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_label_15, device_management_screen_label_15_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->device_management_screen_label_16, device_management_screen_label_16_event_handler, LV_EVENT_ALL, ui);
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
        ui_animation(guider_ui.light_CT_screen_label_2, 600, 0, lv_obj_get_x(guider_ui.light_CT_screen_label_2), 20, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        ui_animation(guider_ui.light_CT_screen_slider_1, 600, 0, lv_obj_get_x(guider_ui.light_CT_screen_slider_1), 33, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        ui_animation(guider_ui.light_CT_screen_slider_2, 600, 0, lv_obj_get_x(guider_ui.light_CT_screen_slider_2), 20, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        ui_animation(guider_ui.light_CT_screen_label_1, 600, 0, lv_obj_get_x(guider_ui.light_CT_screen_label_1), 33, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        light_ct_on_screen_load();
        ui_animation(guider_ui.light_CT_screen_ct_bar, 600, 0, lv_obj_get_x(guider_ui.light_CT_screen_ct_bar), 33, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
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
        light_ct_on_ct_slider_change();
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
        light_ct_on_bri_slider_change();
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
        light_ct_on_switch_toggle(e);
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

static void LedStrip_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.LedStrip_label_1, 600, 0, lv_obj_get_x(guider_ui.LedStrip_label_1), 20, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        ui_animation(guider_ui.LedStrip_slider_1, 600, 0, lv_obj_get_x(guider_ui.LedStrip_slider_1), 33, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        ui_animation(guider_ui.LedStrip_slider_2, 600, 0, lv_obj_get_x(guider_ui.LedStrip_slider_2), 33, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        ui_animation(guider_ui.LedStrip_label_2, 600, 0, lv_obj_get_x(guider_ui.LedStrip_label_2), 20, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        ui_animation(guider_ui.LedStrip_ct_bar, 600, 0, lv_obj_get_x(guider_ui.LedStrip_ct_bar), 33, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        led_strip_on_screen_load();
        break;
    }
    default:
        break;
    }
}

static void LedStrip_slider_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        led_strip_on_ct_slider_change();
        break;
    }
    default:
        break;
    }
}

static void LedStrip_slider_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        led_strip_on_bri_slider_change();
        break;
    }
    default:
        break;
    }
}

static void LedStrip_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.device_management_screen, guider_ui.device_management_screen_del, &guider_ui.LedStrip_del, setup_scr_device_management_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void LedStrip_on_off_2_img_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        led_strip_on_switch_toggle(e);
        break;
    }
    default:
        break;
    }
}

void events_init_LedStrip (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->LedStrip, LedStrip_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->LedStrip_slider_2, LedStrip_slider_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->LedStrip_slider_1, LedStrip_slider_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->LedStrip_btn_1, LedStrip_btn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->LedStrip_on_off_2_img, LedStrip_on_off_2_img_event_handler, LV_EVENT_ALL, ui);
}

static void MagLight_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.MagLight_label_1, 600, 0, lv_obj_get_x(guider_ui.MagLight_label_1), 20, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        ui_animation(guider_ui.MagLight_slider_1, 600, 0, lv_obj_get_x(guider_ui.MagLight_slider_1), 33, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        ui_animation(guider_ui.MagLight_slider_2, 600, 0, lv_obj_get_x(guider_ui.MagLight_slider_2), 33, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        ui_animation(guider_ui.MagLight_ct_bar, 600, 0, lv_obj_get_x(guider_ui.MagLight_ct_bar), 33, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        ui_animation(guider_ui.MagLight_label_2, 600, 0, lv_obj_get_x(guider_ui.MagLight_label_2), 20, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        mag_light_on_screen_load();
        break;
    }
    default:
        break;
    }
}

static void MagLight_slider_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        mag_light_on_ct_slider_change();
        break;
    }
    default:
        break;
    }
}

static void MagLight_slider_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        mag_light_on_bri_slider_change();
        break;
    }
    default:
        break;
    }
}

static void MagLight_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.device_management_screen, guider_ui.device_management_screen_del, &guider_ui.MagLight_del, setup_scr_device_management_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void MagLight_on_off_2_img_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        mag_light_on_switch_toggle(e);
        break;
    }
    default:
        break;
    }
}

void events_init_MagLight (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->MagLight, MagLight_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->MagLight_slider_2, MagLight_slider_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->MagLight_slider_1, MagLight_slider_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->MagLight_btn_1, MagLight_btn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->MagLight_on_off_2_img, MagLight_on_off_2_img_event_handler, LV_EVENT_ALL, ui);
}

static void RGBLight_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.RGBLight_label_1, 600, 0, lv_obj_get_x(guider_ui.RGBLight_label_1), 20, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        ui_animation(guider_ui.RGBLight_slider_2, 600, 0, lv_obj_get_x(guider_ui.RGBLight_slider_2), 33, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        ui_animation(guider_ui.RGBLight_ct_bar, 600, 0, lv_obj_get_x(guider_ui.RGBLight_ct_bar), 33, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        ui_animation(guider_ui.RGBLight_label_2, 600, 0, lv_obj_get_x(guider_ui.RGBLight_label_2), 20, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        ui_animation(guider_ui.RGBLight_slider_1, 600, 0, lv_obj_get_x(guider_ui.RGBLight_slider_1), 33, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        break;
    }
    default:
        break;
    }
}

static void RGBLight_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.device_management_screen, guider_ui.device_management_screen_del, &guider_ui.RGBLight_del, setup_scr_device_management_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_RGBLight (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->RGBLight, RGBLight_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->RGBLight_btn_1, RGBLight_btn_1_event_handler, LV_EVENT_ALL, ui);
}

static void FabricCurtian_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.FabricCurtian_FabCurtianPause, 300, 0, lv_obj_get_y(guider_ui.FabricCurtian_FabCurtianPause), 588, &lv_anim_path_linear, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.FabricCurtian_FabCurtianClose, 300, 0, lv_obj_get_y(guider_ui.FabricCurtian_FabCurtianClose), 588, &lv_anim_path_linear, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.FabricCurtian_FabCurtianOpen, 300, 0, lv_obj_get_y(guider_ui.FabricCurtian_FabCurtianOpen), 588, &lv_anim_path_linear, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        break;
    }
    default:
        break;
    }
}

static void FabricCurtian_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.device_management_screen, guider_ui.device_management_screen_del, &guider_ui.FabricCurtian_del, setup_scr_device_management_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_FabricCurtian (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->FabricCurtian, FabricCurtian_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->FabricCurtian_btn_1, FabricCurtian_btn_1_event_handler, LV_EVENT_ALL, ui);
}

static void Sheers_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.Sheers_FabCurtianPause, 300, 0, lv_obj_get_y(guider_ui.Sheers_FabCurtianPause), 588, &lv_anim_path_linear, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.Sheers_FabCurtianClose, 300, 0, lv_obj_get_y(guider_ui.Sheers_FabCurtianClose), 588, &lv_anim_path_linear, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.Sheers_FabCurtianOpen, 300, 0, lv_obj_get_y(guider_ui.Sheers_FabCurtianOpen), 588, &lv_anim_path_linear, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        break;
    }
    default:
        break;
    }
}

static void Sheers_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.device_management_screen, guider_ui.device_management_screen_del, &guider_ui.Sheers_del, setup_scr_device_management_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_Sheers (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Sheers, Sheers_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Sheers_btn_1, Sheers_btn_1_event_handler, LV_EVENT_ALL, ui);
}

static void RollBlind_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.RollBlind_FabCurtianPause, 300, 0, lv_obj_get_y(guider_ui.RollBlind_FabCurtianPause), 588, &lv_anim_path_linear, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.RollBlind_FabCurtianClose, 300, 0, lv_obj_get_y(guider_ui.RollBlind_FabCurtianClose), 588, &lv_anim_path_linear, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.RollBlind_FabCurtianOpen, 300, 0, lv_obj_get_y(guider_ui.RollBlind_FabCurtianOpen), 588, &lv_anim_path_linear, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        break;
    }
    default:
        break;
    }
}

static void RollBlind_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.device_management_screen, guider_ui.device_management_screen_del, &guider_ui.RollBlind_del, setup_scr_device_management_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_RollBlind (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->RollBlind, RollBlind_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->RollBlind_btn_1, RollBlind_btn_1_event_handler, LV_EVENT_ALL, ui);
}

static void Dream_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.Dream_FabCurtianPause, 300, 0, lv_obj_get_y(guider_ui.Dream_FabCurtianPause), 588, &lv_anim_path_linear, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.Dream_FabCurtianClose, 300, 0, lv_obj_get_y(guider_ui.Dream_FabCurtianClose), 588, &lv_anim_path_linear, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.Dream_FabCurtianOpen, 300, 0, lv_obj_get_y(guider_ui.Dream_FabCurtianOpen), 588, &lv_anim_path_linear, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        break;
    }
    default:
        break;
    }
}

static void Dream_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.device_management_screen, guider_ui.device_management_screen_del, &guider_ui.Dream_del, setup_scr_device_management_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_Dream (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Dream, Dream_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Dream_btn_1, Dream_btn_1_event_handler, LV_EVENT_ALL, ui);
}

static void AirCondition_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.device_management_screen, guider_ui.device_management_screen_del, &guider_ui.AirCondition_del, setup_scr_device_management_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_AirCondition (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->AirCondition_btn_1, AirCondition_btn_1_event_handler, LV_EVENT_ALL, ui);
}

static void DryRack_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.DryRack_FabCurtianPause, 300, 0, lv_obj_get_y(guider_ui.DryRack_FabCurtianPause), 588, &lv_anim_path_linear, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.DryRack_FabCurtianClose, 300, 0, lv_obj_get_y(guider_ui.DryRack_FabCurtianClose), 588, &lv_anim_path_linear, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.DryRack_FabCurtianOpen, 300, 0, lv_obj_get_y(guider_ui.DryRack_FabCurtianOpen), 588, &lv_anim_path_linear, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        break;
    }
    default:
        break;
    }
}

static void DryRack_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.device_management_screen, guider_ui.device_management_screen_del, &guider_ui.DryRack_del, setup_scr_device_management_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_DryRack (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->DryRack, DryRack_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->DryRack_btn_1, DryRack_btn_1_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
