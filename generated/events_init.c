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

#include <stdio.h>
static uint32_t s_ct_apply_tick2;
static uint32_t s_ct_apply_tick;

static void screen_event_handler (lv_event_t *e)
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

static void screen_1_dev_lightCT_button_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_5, guider_ui.screen_5_del, &guider_ui.screen_1_del, setup_scr_screen_5, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        void dev_lightCT_click_evt()
        {
            printf("123");
        }
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

void events_init_screen_1 (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_1, screen_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_1_dev_lightCT_button, screen_1_dev_lightCT_button_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_1_label_2, screen_1_label_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_1_small_dev_off_img, screen_1_small_dev_off_img_event_handler, LV_EVENT_ALL, ui);
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
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
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

static void screen_5_slider_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        const uint32_t APPLY_MIN_MS = 50;   /* 拖动节流: 两张旋转灯光图重绘很重, 最多每 50ms 刷一次防卡 */
        s_ct_apply_tick2 = lv_tick_get();
        lv_obj_t *slider1 = guider_ui.screen_5_slider_1;   /* 亮度 0..100 */
        lv_obj_t *slider2 = guider_ui.screen_5_slider_2;   /* 色温 2700..6500 */
        lv_obj_t *white   = guider_ui.screen_5_dev_white_img;
        lv_obj_t *orange  = guider_ui.screen_5_dev_orange_img;

        if (lv_obj_is_valid(slider1) && lv_obj_is_valid(slider2)) {
            const int32_t CT_MIN  = 2700;   /* 色温最左(K) */
            const int32_t CT_SPAN = 3800;   /* 6500-2700 */
            const int32_t BRI_MAX = 100;
            int32_t  bri  = lv_slider_get_value(slider1);
            int32_t  ct   = lv_slider_get_value(slider2);
            uint32_t tnum = (uint32_t)(ct - CT_MIN);                                 /* = T*CT_SPAN */
            uint32_t o_white  = (uint32_t)bri * tnum            * LV_OPA_COVER / ((uint32_t)BRI_MAX * CT_SPAN);
            uint32_t o_orange = (uint32_t)bri * (CT_SPAN - tnum) * LV_OPA_COVER / ((uint32_t)BRI_MAX * CT_SPAN);
            if (lv_obj_is_valid(white))  lv_obj_set_style_img_opa(white,  (lv_opa_t)o_white,  LV_PART_MAIN | LV_STATE_DEFAULT);
            if (lv_obj_is_valid(orange)) lv_obj_set_style_img_opa(orange, (lv_opa_t)o_orange, LV_PART_MAIN | LV_STATE_DEFAULT);
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
        const uint32_t APPLY_MIN_MS = 50;   /* 拖动节流: 两张旋转灯光图重绘很重, 最多每 50ms 刷一次防卡 */
        if (lv_tick_elaps(s_ct_apply_tick) >= APPLY_MIN_MS) {
            s_ct_apply_tick = lv_tick_get();

            lv_obj_t *slider1 = guider_ui.screen_5_slider_1;   /* 亮度 0..100 */
            lv_obj_t *slider2 = guider_ui.screen_5_slider_2;   /* 色温 2700..6500 */
            lv_obj_t *white   = guider_ui.screen_5_dev_white_img;
            lv_obj_t *orange  = guider_ui.screen_5_dev_orange_img;

            if (lv_obj_is_valid(slider1) && lv_obj_is_valid(slider2)) {
                const int32_t CT_MIN  = 2700;   /* 色温最左(K) */
                const int32_t CT_SPAN = 3800;   /* 6500-2700 */
                const int32_t BRI_MAX = 100;
                int32_t  bri  = lv_slider_get_value(slider1);
                int32_t  ct   = lv_slider_get_value(slider2);
                uint32_t tnum = (uint32_t)(ct - CT_MIN);                                 /* = T*CT_SPAN */
                uint32_t o_white  = (uint32_t)bri * tnum            * LV_OPA_COVER / ((uint32_t)BRI_MAX * CT_SPAN);
                uint32_t o_orange = (uint32_t)bri * (CT_SPAN - tnum) * LV_OPA_COVER / ((uint32_t)BRI_MAX * CT_SPAN);
                if (lv_obj_is_valid(white))  lv_obj_set_style_img_opa(white,  (lv_opa_t)o_white,  LV_PART_MAIN | LV_STATE_DEFAULT);
                if (lv_obj_is_valid(orange)) lv_obj_set_style_img_opa(orange, (lv_opa_t)o_orange, LV_PART_MAIN | LV_STATE_DEFAULT);
            }
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

static void screen_5_CT_on_off_2_img_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {

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
    lv_obj_add_event_cb(ui->screen_5_CT_on_off_2_img, screen_5_CT_on_off_2_img_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
