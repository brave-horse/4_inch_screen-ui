/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_device_management_screen(lv_ui *ui)
{
    //Write codes device_management_screen
    ui->device_management_screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->device_management_screen, 720, 720);
    lv_obj_set_scrollbar_mode(ui->device_management_screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for device_management_screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->device_management_screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->device_management_screen, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->device_management_screen, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_tabview_1
    ui->device_management_screen_tabview_1 = lv_tabview_create(ui->device_management_screen, LV_DIR_TOP, 85);
    lv_obj_set_pos(ui->device_management_screen_tabview_1, -1, -1);
    lv_obj_set_size(ui->device_management_screen_tabview_1, 720, 720);
    lv_obj_set_scrollbar_mode(ui->device_management_screen_tabview_1, LV_SCROLLBAR_MODE_ON);

    //Write style for device_management_screen_tabview_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->device_management_screen_tabview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->device_management_screen_tabview_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->device_management_screen_tabview_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_management_screen_tabview_1, lv_color_hex(0x4d4d4d), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_tabview_1, &lv_font_ZiTiQuanWeiJunHeiW22_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_tabview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_management_screen_tabview_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_management_screen_tabview_1, 16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->device_management_screen_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_device_management_screen_tabview_1_extra_btnm_main_default
    static lv_style_t style_device_management_screen_tabview_1_extra_btnm_main_default;
    ui_init_style(&style_device_management_screen_tabview_1_extra_btnm_main_default);

    lv_style_set_bg_opa(&style_device_management_screen_tabview_1_extra_btnm_main_default, 255);
    lv_style_set_bg_color(&style_device_management_screen_tabview_1_extra_btnm_main_default, lv_color_hex(0x201b1b));
    lv_style_set_bg_grad_dir(&style_device_management_screen_tabview_1_extra_btnm_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_device_management_screen_tabview_1_extra_btnm_main_default, 0);
    lv_style_set_radius(&style_device_management_screen_tabview_1_extra_btnm_main_default, 0);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->device_management_screen_tabview_1), &style_device_management_screen_tabview_1_extra_btnm_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_device_management_screen_tabview_1_extra_btnm_items_default
    static lv_style_t style_device_management_screen_tabview_1_extra_btnm_items_default;
    ui_init_style(&style_device_management_screen_tabview_1_extra_btnm_items_default);

    lv_style_set_text_color(&style_device_management_screen_tabview_1_extra_btnm_items_default, lv_color_hex(0x4d4d4d));
    lv_style_set_text_font(&style_device_management_screen_tabview_1_extra_btnm_items_default, &lv_font_ZiTiQuanWeiJunHeiW22_12);
    lv_style_set_text_opa(&style_device_management_screen_tabview_1_extra_btnm_items_default, 255);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->device_management_screen_tabview_1), &style_device_management_screen_tabview_1_extra_btnm_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_device_management_screen_tabview_1_extra_btnm_items_checked
    static lv_style_t style_device_management_screen_tabview_1_extra_btnm_items_checked;
    ui_init_style(&style_device_management_screen_tabview_1_extra_btnm_items_checked);

    lv_style_set_text_color(&style_device_management_screen_tabview_1_extra_btnm_items_checked, lv_color_hex(0x2195f6));
    lv_style_set_text_font(&style_device_management_screen_tabview_1_extra_btnm_items_checked, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_device_management_screen_tabview_1_extra_btnm_items_checked, 255);
    lv_style_set_border_width(&style_device_management_screen_tabview_1_extra_btnm_items_checked, 0);
    lv_style_set_radius(&style_device_management_screen_tabview_1_extra_btnm_items_checked, 0);
    lv_style_set_bg_opa(&style_device_management_screen_tabview_1_extra_btnm_items_checked, 255);
    lv_style_set_bg_color(&style_device_management_screen_tabview_1_extra_btnm_items_checked, lv_color_hex(0x201b1b));
    lv_style_set_bg_grad_dir(&style_device_management_screen_tabview_1_extra_btnm_items_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->device_management_screen_tabview_1), &style_device_management_screen_tabview_1_extra_btnm_items_checked, LV_PART_ITEMS|LV_STATE_CHECKED);

    //Write codes
    ui->device_management_screen_tabview_1_tab_1 = lv_tabview_add_tab(ui->device_management_screen_tabview_1,"");
    lv_obj_t * device_management_screen_tabview_1_tab_1_label = lv_label_create(ui->device_management_screen_tabview_1_tab_1);
    lv_label_set_text(device_management_screen_tabview_1_tab_1_label, "");

    //Write codes device_management_screen_cont_1
    ui->device_management_screen_cont_1 = lv_obj_create(ui->device_management_screen_tabview_1_tab_1);
    lv_obj_set_pos(ui->device_management_screen_cont_1, 21, 0);
    lv_obj_set_size(ui->device_management_screen_cont_1, 300, 150);
    lv_obj_set_scrollbar_mode(ui->device_management_screen_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for device_management_screen_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_management_screen_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->device_management_screen_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->device_management_screen_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->device_management_screen_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_cont_1, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_management_screen_cont_1, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->device_management_screen_cont_1, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->device_management_screen_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_management_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_management_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_management_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_management_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_Light_CT_on_off_1_img
    ui->device_management_screen_Light_CT_on_off_1_img = lv_imgbtn_create(ui->device_management_screen_cont_1);
    lv_obj_add_flag(ui->device_management_screen_Light_CT_on_off_1_img, LV_OBJ_FLAG_CHECKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_imgbtn_set_src(ui->device_management_screen_Light_CT_on_off_1_img, LV_IMGBTN_STATE_RELEASED, NULL, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\onoff_off.png", NULL);
    lv_imgbtn_set_src(ui->device_management_screen_Light_CT_on_off_1_img, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\onoff_on.png", NULL);
#else
    lv_imgbtn_set_src(ui->device_management_screen_Light_CT_on_off_1_img, LV_IMGBTN_STATE_RELEASED, NULL, "S:/sdfile/EXT_RESERVED/uipackres/ui/onoff_off.png", NULL);
    lv_imgbtn_set_src(ui->device_management_screen_Light_CT_on_off_1_img, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, "S:/sdfile/EXT_RESERVED/uipackres/ui/onoff_on.png", NULL);
#endif
    ui->device_management_screen_Light_CT_on_off_1_img_label = lv_label_create(ui->device_management_screen_Light_CT_on_off_1_img);
    lv_label_set_text(ui->device_management_screen_Light_CT_on_off_1_img_label, "");
    lv_label_set_long_mode(ui->device_management_screen_Light_CT_on_off_1_img_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->device_management_screen_Light_CT_on_off_1_img_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->device_management_screen_Light_CT_on_off_1_img, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->device_management_screen_Light_CT_on_off_1_img, 212, 23);
    lv_obj_set_size(ui->device_management_screen_Light_CT_on_off_1_img, 48, 48);

    //Write style for device_management_screen_Light_CT_on_off_1_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->device_management_screen_Light_CT_on_off_1_img, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_Light_CT_on_off_1_img, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_Light_CT_on_off_1_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_Light_CT_on_off_1_img, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_Light_CT_on_off_1_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_Light_CT_on_off_1_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_Light_CT_on_off_1_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for device_management_screen_Light_CT_on_off_1_img, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_Light_CT_on_off_1_img, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->device_management_screen_Light_CT_on_off_1_img, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->device_management_screen_Light_CT_on_off_1_img, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->device_management_screen_Light_CT_on_off_1_img, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->device_management_screen_Light_CT_on_off_1_img, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->device_management_screen_Light_CT_on_off_1_img, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for device_management_screen_Light_CT_on_off_1_img, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_Light_CT_on_off_1_img, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->device_management_screen_Light_CT_on_off_1_img, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->device_management_screen_Light_CT_on_off_1_img, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->device_management_screen_Light_CT_on_off_1_img, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->device_management_screen_Light_CT_on_off_1_img, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->device_management_screen_Light_CT_on_off_1_img, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for device_management_screen_Light_CT_on_off_1_img, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_Light_CT_on_off_1_img, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->device_management_screen_Light_CT_on_off_1_img, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes device_management_screen_sdev_on
    ui->device_management_screen_sdev_on = lv_img_create(ui->device_management_screen_cont_1);
    lv_obj_add_flag(ui->device_management_screen_sdev_on, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->device_management_screen_sdev_on, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\sdev_on.png");
#else
    lv_img_set_src(ui->device_management_screen_sdev_on, "S:/sdfile/EXT_RESERVED/uipackres/ui/sdev_on.png");
#endif
    lv_img_set_pivot(ui->device_management_screen_sdev_on, 50,50);
    lv_img_set_angle(ui->device_management_screen_sdev_on, 0);
    lv_obj_set_pos(ui->device_management_screen_sdev_on, 40, 13);
    lv_obj_set_size(ui->device_management_screen_sdev_on, 50, 57);

    //Write style for device_management_screen_sdev_on, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sdev_on, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sdev_on, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sdev_on, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sdev_on, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_small_dev_off_img
    ui->device_management_screen_small_dev_off_img = lv_img_create(ui->device_management_screen_cont_1);
    lv_obj_add_flag(ui->device_management_screen_small_dev_off_img, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->device_management_screen_small_dev_off_img, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\sdev_off.png");
#else
    lv_img_set_src(ui->device_management_screen_small_dev_off_img, "S:/sdfile/EXT_RESERVED/uipackres/ui/sdev_off.png");
#endif
    lv_img_set_pivot(ui->device_management_screen_small_dev_off_img, 50,50);
    lv_img_set_angle(ui->device_management_screen_small_dev_off_img, 0);
    lv_obj_set_pos(ui->device_management_screen_small_dev_off_img, 40, 13);
    lv_obj_set_size(ui->device_management_screen_small_dev_off_img, 50, 57);

    //Write style for device_management_screen_small_dev_off_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_small_dev_off_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_small_dev_off_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_small_dev_off_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_small_dev_off_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_label_2
    ui->device_management_screen_label_2 = lv_label_create(ui->device_management_screen_cont_1);
    lv_label_set_text(ui->device_management_screen_label_2, "色温灯");
    lv_label_set_long_mode(ui->device_management_screen_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->device_management_screen_label_2, 18, 94);
    lv_obj_set_size(ui->device_management_screen_label_2, 100, 32);

    //Write style for device_management_screen_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_management_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_management_screen_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_label_2, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_management_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_management_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_management_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_management_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_management_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_management_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_management_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_cont_2
    ui->device_management_screen_cont_2 = lv_obj_create(ui->device_management_screen_tabview_1_tab_1);
    lv_obj_set_pos(ui->device_management_screen_cont_2, 372, 0);
    lv_obj_set_size(ui->device_management_screen_cont_2, 300, 150);
    lv_obj_set_scrollbar_mode(ui->device_management_screen_cont_2, LV_SCROLLBAR_MODE_OFF);

    //Write style for device_management_screen_cont_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_management_screen_cont_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->device_management_screen_cont_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->device_management_screen_cont_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->device_management_screen_cont_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_cont_2, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_management_screen_cont_2, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->device_management_screen_cont_2, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->device_management_screen_cont_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_management_screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_management_screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_management_screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_management_screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sLEDStripOn
    ui->device_management_screen_sLEDStripOn = lv_img_create(ui->device_management_screen_cont_2);
    lv_obj_add_flag(ui->device_management_screen_sLEDStripOn, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->device_management_screen_sLEDStripOn, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\sLSOn.png");
#else
    lv_img_set_src(ui->device_management_screen_sLEDStripOn, "S:/sdfile/EXT_RESERVED/uipackres/ui/sLSOn.png");
#endif
    lv_img_set_pivot(ui->device_management_screen_sLEDStripOn, 50,50);
    lv_img_set_angle(ui->device_management_screen_sLEDStripOn, 0);
    lv_obj_set_pos(ui->device_management_screen_sLEDStripOn, 25, 21);
    lv_obj_set_size(ui->device_management_screen_sLEDStripOn, 65, 43);

    //Write style for device_management_screen_sLEDStripOn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sLEDStripOn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sLEDStripOn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sLEDStripOn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sLEDStripOn, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sLEDStripOff
    ui->device_management_screen_sLEDStripOff = lv_img_create(ui->device_management_screen_cont_2);
    lv_obj_add_flag(ui->device_management_screen_sLEDStripOff, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->device_management_screen_sLEDStripOff, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\sLSOff.png");
#else
    lv_img_set_src(ui->device_management_screen_sLEDStripOff, "S:/sdfile/EXT_RESERVED/uipackres/ui/sLSOff.png");
#endif
    lv_img_set_pivot(ui->device_management_screen_sLEDStripOff, 50,50);
    lv_img_set_angle(ui->device_management_screen_sLEDStripOff, 0);
    lv_obj_set_pos(ui->device_management_screen_sLEDStripOff, 25, 21);
    lv_obj_set_size(ui->device_management_screen_sLEDStripOff, 65, 43);

    //Write style for device_management_screen_sLEDStripOff, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sLEDStripOff, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sLEDStripOff, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sLEDStripOff, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sLEDStripOff, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sLSimgbtn
    ui->device_management_screen_sLSimgbtn = lv_imgbtn_create(ui->device_management_screen_cont_2);
    lv_obj_add_flag(ui->device_management_screen_sLSimgbtn, LV_OBJ_FLAG_CHECKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_imgbtn_set_src(ui->device_management_screen_sLSimgbtn, LV_IMGBTN_STATE_RELEASED, NULL, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\onoff_off.png", NULL);
    lv_imgbtn_set_src(ui->device_management_screen_sLSimgbtn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\onoff_on.png", NULL);
#else
    lv_imgbtn_set_src(ui->device_management_screen_sLSimgbtn, LV_IMGBTN_STATE_RELEASED, NULL, "S:/sdfile/EXT_RESERVED/uipackres/ui/onoff_off.png", NULL);
    lv_imgbtn_set_src(ui->device_management_screen_sLSimgbtn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, "S:/sdfile/EXT_RESERVED/uipackres/ui/onoff_on.png", NULL);
#endif
    ui->device_management_screen_sLSimgbtn_label = lv_label_create(ui->device_management_screen_sLSimgbtn);
    lv_label_set_text(ui->device_management_screen_sLSimgbtn_label, "");
    lv_label_set_long_mode(ui->device_management_screen_sLSimgbtn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->device_management_screen_sLSimgbtn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->device_management_screen_sLSimgbtn, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->device_management_screen_sLSimgbtn, 224, 16);
    lv_obj_set_size(ui->device_management_screen_sLSimgbtn, 48, 48);

    //Write style for device_management_screen_sLSimgbtn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->device_management_screen_sLSimgbtn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_sLSimgbtn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_sLSimgbtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_sLSimgbtn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sLSimgbtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sLSimgbtn, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_sLSimgbtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for device_management_screen_sLSimgbtn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sLSimgbtn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->device_management_screen_sLSimgbtn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->device_management_screen_sLSimgbtn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->device_management_screen_sLSimgbtn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->device_management_screen_sLSimgbtn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->device_management_screen_sLSimgbtn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for device_management_screen_sLSimgbtn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sLSimgbtn, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->device_management_screen_sLSimgbtn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->device_management_screen_sLSimgbtn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->device_management_screen_sLSimgbtn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->device_management_screen_sLSimgbtn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->device_management_screen_sLSimgbtn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for device_management_screen_sLSimgbtn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sLSimgbtn, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->device_management_screen_sLSimgbtn, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes device_management_screen_label_3
    ui->device_management_screen_label_3 = lv_label_create(ui->device_management_screen_cont_2);
    lv_label_set_text(ui->device_management_screen_label_3, "灯带");
    lv_label_set_long_mode(ui->device_management_screen_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->device_management_screen_label_3, 19, 88);
    lv_obj_set_size(ui->device_management_screen_label_3, 100, 32);

    //Write style for device_management_screen_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_management_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_management_screen_label_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_label_3, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_management_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_management_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_management_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_management_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_management_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_management_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_management_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_cont_3
    ui->device_management_screen_cont_3 = lv_obj_create(ui->device_management_screen_tabview_1_tab_1);
    lv_obj_set_pos(ui->device_management_screen_cont_3, 21, 181);
    lv_obj_set_size(ui->device_management_screen_cont_3, 300, 150);
    lv_obj_set_scrollbar_mode(ui->device_management_screen_cont_3, LV_SCROLLBAR_MODE_OFF);

    //Write style for device_management_screen_cont_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_management_screen_cont_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->device_management_screen_cont_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->device_management_screen_cont_3, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->device_management_screen_cont_3, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_cont_3, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_management_screen_cont_3, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->device_management_screen_cont_3, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->device_management_screen_cont_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_management_screen_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_management_screen_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_management_screen_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_management_screen_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sMagLightOn
    ui->device_management_screen_sMagLightOn = lv_img_create(ui->device_management_screen_cont_3);
    lv_obj_add_flag(ui->device_management_screen_sMagLightOn, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->device_management_screen_sMagLightOn, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\sMLOn.png");
#else
    lv_img_set_src(ui->device_management_screen_sMagLightOn, "S:/sdfile/EXT_RESERVED/uipackres/ui/sMLOn.png");
#endif
    lv_img_set_pivot(ui->device_management_screen_sMagLightOn, 50,50);
    lv_img_set_angle(ui->device_management_screen_sMagLightOn, 0);
    lv_obj_set_pos(ui->device_management_screen_sMagLightOn, 27, 23);
    lv_obj_set_size(ui->device_management_screen_sMagLightOn, 70, 4);

    //Write style for device_management_screen_sMagLightOn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sMagLightOn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sMagLightOn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sMagLightOn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sMagLightOn, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sMagLightOff
    ui->device_management_screen_sMagLightOff = lv_img_create(ui->device_management_screen_cont_3);
    lv_obj_add_flag(ui->device_management_screen_sMagLightOff, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->device_management_screen_sMagLightOff, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\sMLOff.png");
#else
    lv_img_set_src(ui->device_management_screen_sMagLightOff, "S:/sdfile/EXT_RESERVED/uipackres/ui/sMLOff.png");
#endif
    lv_img_set_pivot(ui->device_management_screen_sMagLightOff, 50,50);
    lv_img_set_angle(ui->device_management_screen_sMagLightOff, 0);
    lv_obj_set_pos(ui->device_management_screen_sMagLightOff, 27, 23);
    lv_obj_set_size(ui->device_management_screen_sMagLightOff, 70, 4);

    //Write style for device_management_screen_sMagLightOff, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sMagLightOff, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sMagLightOff, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sMagLightOff, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sMagLightOff, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sMagimgbtn
    ui->device_management_screen_sMagimgbtn = lv_imgbtn_create(ui->device_management_screen_cont_3);
    lv_obj_add_flag(ui->device_management_screen_sMagimgbtn, LV_OBJ_FLAG_CHECKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_imgbtn_set_src(ui->device_management_screen_sMagimgbtn, LV_IMGBTN_STATE_RELEASED, NULL, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\onoff_off.png", NULL);
    lv_imgbtn_set_src(ui->device_management_screen_sMagimgbtn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\onoff_on.png", NULL);
#else
    lv_imgbtn_set_src(ui->device_management_screen_sMagimgbtn, LV_IMGBTN_STATE_RELEASED, NULL, "S:/sdfile/EXT_RESERVED/uipackres/ui/onoff_off.png", NULL);
    lv_imgbtn_set_src(ui->device_management_screen_sMagimgbtn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, "S:/sdfile/EXT_RESERVED/uipackres/ui/onoff_on.png", NULL);
#endif
    ui->device_management_screen_sMagimgbtn_label = lv_label_create(ui->device_management_screen_sMagimgbtn);
    lv_label_set_text(ui->device_management_screen_sMagimgbtn_label, "");
    lv_label_set_long_mode(ui->device_management_screen_sMagimgbtn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->device_management_screen_sMagimgbtn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->device_management_screen_sMagimgbtn, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->device_management_screen_sMagimgbtn, 216, 17);
    lv_obj_set_size(ui->device_management_screen_sMagimgbtn, 48, 48);

    //Write style for device_management_screen_sMagimgbtn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->device_management_screen_sMagimgbtn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_sMagimgbtn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_sMagimgbtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_sMagimgbtn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sMagimgbtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sMagimgbtn, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_sMagimgbtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for device_management_screen_sMagimgbtn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sMagimgbtn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->device_management_screen_sMagimgbtn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->device_management_screen_sMagimgbtn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->device_management_screen_sMagimgbtn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->device_management_screen_sMagimgbtn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->device_management_screen_sMagimgbtn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for device_management_screen_sMagimgbtn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sMagimgbtn, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->device_management_screen_sMagimgbtn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->device_management_screen_sMagimgbtn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->device_management_screen_sMagimgbtn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->device_management_screen_sMagimgbtn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->device_management_screen_sMagimgbtn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for device_management_screen_sMagimgbtn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sMagimgbtn, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->device_management_screen_sMagimgbtn, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes device_management_screen_label_4
    ui->device_management_screen_label_4 = lv_label_create(ui->device_management_screen_cont_3);
    lv_label_set_text(ui->device_management_screen_label_4, "磁吸灯");
    lv_label_set_long_mode(ui->device_management_screen_label_4, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->device_management_screen_label_4, 15, 92);
    lv_obj_set_size(ui->device_management_screen_label_4, 100, 35);

    //Write style for device_management_screen_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_management_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_management_screen_label_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_label_4, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_management_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_management_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_management_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_management_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_management_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_management_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_management_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_cont_4
    ui->device_management_screen_cont_4 = lv_obj_create(ui->device_management_screen_tabview_1_tab_1);
    lv_obj_set_pos(ui->device_management_screen_cont_4, 372, 181);
    lv_obj_set_size(ui->device_management_screen_cont_4, 300, 150);
    lv_obj_set_scrollbar_mode(ui->device_management_screen_cont_4, LV_SCROLLBAR_MODE_OFF);

    //Write style for device_management_screen_cont_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_management_screen_cont_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->device_management_screen_cont_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->device_management_screen_cont_4, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->device_management_screen_cont_4, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_cont_4, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_management_screen_cont_4, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->device_management_screen_cont_4, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->device_management_screen_cont_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_management_screen_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_management_screen_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_management_screen_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_management_screen_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sRGBLightOn
    ui->device_management_screen_sRGBLightOn = lv_img_create(ui->device_management_screen_cont_4);
    lv_obj_add_flag(ui->device_management_screen_sRGBLightOn, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->device_management_screen_sRGBLightOn, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\sRGBLOn.png");
#else
    lv_img_set_src(ui->device_management_screen_sRGBLightOn, "S:/sdfile/EXT_RESERVED/uipackres/ui/sRGBLOn.png");
#endif
    lv_img_set_pivot(ui->device_management_screen_sRGBLightOn, 50,50);
    lv_img_set_angle(ui->device_management_screen_sRGBLightOn, 0);
    lv_obj_set_pos(ui->device_management_screen_sRGBLightOn, 28, 23);
    lv_obj_set_size(ui->device_management_screen_sRGBLightOn, 60, 58);

    //Write style for device_management_screen_sRGBLightOn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sRGBLightOn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sRGBLightOn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sRGBLightOn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sRGBLightOn, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sRGBLightOff
    ui->device_management_screen_sRGBLightOff = lv_img_create(ui->device_management_screen_cont_4);
    lv_obj_add_flag(ui->device_management_screen_sRGBLightOff, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->device_management_screen_sRGBLightOff, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\sRGBLOff.png");
#else
    lv_img_set_src(ui->device_management_screen_sRGBLightOff, "S:/sdfile/EXT_RESERVED/uipackres/ui/sRGBLOff.png");
#endif
    lv_img_set_pivot(ui->device_management_screen_sRGBLightOff, 50,50);
    lv_img_set_angle(ui->device_management_screen_sRGBLightOff, 0);
    lv_obj_set_pos(ui->device_management_screen_sRGBLightOff, 27, 23);
    lv_obj_set_size(ui->device_management_screen_sRGBLightOff, 60, 58);

    //Write style for device_management_screen_sRGBLightOff, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sRGBLightOff, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sRGBLightOff, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sRGBLightOff, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sRGBLightOff, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sRGBLightBtn
    ui->device_management_screen_sRGBLightBtn = lv_imgbtn_create(ui->device_management_screen_cont_4);
    lv_obj_add_flag(ui->device_management_screen_sRGBLightBtn, LV_OBJ_FLAG_CHECKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_imgbtn_set_src(ui->device_management_screen_sRGBLightBtn, LV_IMGBTN_STATE_RELEASED, NULL, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\onoff_off.png", NULL);
    lv_imgbtn_set_src(ui->device_management_screen_sRGBLightBtn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\onoff_on.png", NULL);
#else
    lv_imgbtn_set_src(ui->device_management_screen_sRGBLightBtn, LV_IMGBTN_STATE_RELEASED, NULL, "S:/sdfile/EXT_RESERVED/uipackres/ui/onoff_off.png", NULL);
    lv_imgbtn_set_src(ui->device_management_screen_sRGBLightBtn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, "S:/sdfile/EXT_RESERVED/uipackres/ui/onoff_on.png", NULL);
#endif
    ui->device_management_screen_sRGBLightBtn_label = lv_label_create(ui->device_management_screen_sRGBLightBtn);
    lv_label_set_text(ui->device_management_screen_sRGBLightBtn_label, "");
    lv_label_set_long_mode(ui->device_management_screen_sRGBLightBtn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->device_management_screen_sRGBLightBtn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->device_management_screen_sRGBLightBtn, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->device_management_screen_sRGBLightBtn, 227, 18);
    lv_obj_set_size(ui->device_management_screen_sRGBLightBtn, 48, 48);

    //Write style for device_management_screen_sRGBLightBtn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->device_management_screen_sRGBLightBtn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_sRGBLightBtn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_sRGBLightBtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_sRGBLightBtn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sRGBLightBtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sRGBLightBtn, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_sRGBLightBtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for device_management_screen_sRGBLightBtn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sRGBLightBtn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->device_management_screen_sRGBLightBtn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->device_management_screen_sRGBLightBtn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->device_management_screen_sRGBLightBtn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->device_management_screen_sRGBLightBtn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->device_management_screen_sRGBLightBtn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for device_management_screen_sRGBLightBtn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sRGBLightBtn, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->device_management_screen_sRGBLightBtn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->device_management_screen_sRGBLightBtn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->device_management_screen_sRGBLightBtn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->device_management_screen_sRGBLightBtn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->device_management_screen_sRGBLightBtn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for device_management_screen_sRGBLightBtn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sRGBLightBtn, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->device_management_screen_sRGBLightBtn, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes device_management_screen_label_5
    ui->device_management_screen_label_5 = lv_label_create(ui->device_management_screen_cont_4);
    lv_label_set_text(ui->device_management_screen_label_5, "彩色灯");
    lv_label_set_long_mode(ui->device_management_screen_label_5, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->device_management_screen_label_5, 17, 89);
    lv_obj_set_size(ui->device_management_screen_label_5, 100, 35);

    //Write style for device_management_screen_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_management_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_management_screen_label_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_label_5, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_management_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_management_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_management_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_management_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_management_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_management_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_management_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_cont_5
    ui->device_management_screen_cont_5 = lv_obj_create(ui->device_management_screen_tabview_1_tab_1);
    lv_obj_set_pos(ui->device_management_screen_cont_5, 21, 362);
    lv_obj_set_size(ui->device_management_screen_cont_5, 300, 150);
    lv_obj_set_scrollbar_mode(ui->device_management_screen_cont_5, LV_SCROLLBAR_MODE_OFF);

    //Write style for device_management_screen_cont_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_management_screen_cont_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->device_management_screen_cont_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->device_management_screen_cont_5, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->device_management_screen_cont_5, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_cont_5, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_management_screen_cont_5, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->device_management_screen_cont_5, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->device_management_screen_cont_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_management_screen_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_management_screen_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_management_screen_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_management_screen_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sFabricCurtainOn
    ui->device_management_screen_sFabricCurtainOn = lv_img_create(ui->device_management_screen_cont_5);
    lv_obj_add_flag(ui->device_management_screen_sFabricCurtainOn, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->device_management_screen_sFabricCurtainOn, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\sFCOn.png");
#else
    lv_img_set_src(ui->device_management_screen_sFabricCurtainOn, "S:/sdfile/EXT_RESERVED/uipackres/ui/sFCOn.png");
#endif
    lv_img_set_pivot(ui->device_management_screen_sFabricCurtainOn, 50,50);
    lv_img_set_angle(ui->device_management_screen_sFabricCurtainOn, 0);
    lv_obj_set_pos(ui->device_management_screen_sFabricCurtainOn, 28, 23);
    lv_obj_set_size(ui->device_management_screen_sFabricCurtainOn, 49, 43);

    //Write style for device_management_screen_sFabricCurtainOn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sFabricCurtainOn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sFabricCurtainOn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sFabricCurtainOn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sFabricCurtainOn, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sFabricCurtianOff
    ui->device_management_screen_sFabricCurtianOff = lv_img_create(ui->device_management_screen_cont_5);
    lv_obj_add_flag(ui->device_management_screen_sFabricCurtianOff, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->device_management_screen_sFabricCurtianOff, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\sFCOff.png");
#else
    lv_img_set_src(ui->device_management_screen_sFabricCurtianOff, "S:/sdfile/EXT_RESERVED/uipackres/ui/sFCOff.png");
#endif
    lv_img_set_pivot(ui->device_management_screen_sFabricCurtianOff, 50,50);
    lv_img_set_angle(ui->device_management_screen_sFabricCurtianOff, 0);
    lv_obj_set_pos(ui->device_management_screen_sFabricCurtianOff, 27, 21);
    lv_obj_set_size(ui->device_management_screen_sFabricCurtianOff, 49, 43);

    //Write style for device_management_screen_sFabricCurtianOff, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sFabricCurtianOff, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sFabricCurtianOff, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sFabricCurtianOff, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sFabricCurtianOff, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_label_6
    ui->device_management_screen_label_6 = lv_label_create(ui->device_management_screen_cont_5);
    lv_label_set_text(ui->device_management_screen_label_6, "布帘");
    lv_label_set_long_mode(ui->device_management_screen_label_6, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->device_management_screen_label_6, 5, 86);
    lv_obj_set_size(ui->device_management_screen_label_6, 100, 35);

    //Write style for device_management_screen_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_management_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_management_screen_label_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_label_6, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_management_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_management_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_management_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_management_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_management_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_management_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_management_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sFabricCurClose
    ui->device_management_screen_sFabricCurClose = lv_img_create(ui->device_management_screen_cont_5);
    lv_obj_add_flag(ui->device_management_screen_sFabricCurClose, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->device_management_screen_sFabricCurClose, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\sClose.png");
#else
    lv_img_set_src(ui->device_management_screen_sFabricCurClose, "S:/sdfile/EXT_RESERVED/uipackres/ui/sClose.png");
#endif
    lv_img_set_pivot(ui->device_management_screen_sFabricCurClose, 50,50);
    lv_img_set_angle(ui->device_management_screen_sFabricCurClose, 0);
    lv_obj_set_pos(ui->device_management_screen_sFabricCurClose, 212, 23);
    lv_obj_set_size(ui->device_management_screen_sFabricCurClose, 60, 60);

    //Write style for device_management_screen_sFabricCurClose, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sFabricCurClose, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sFabricCurClose, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sFabricCurClose, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sFabricCurClose, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sFabricCurOpen
    ui->device_management_screen_sFabricCurOpen = lv_img_create(ui->device_management_screen_cont_5);
    lv_obj_add_flag(ui->device_management_screen_sFabricCurOpen, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->device_management_screen_sFabricCurOpen, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\sOpen.png");
#else
    lv_img_set_src(ui->device_management_screen_sFabricCurOpen, "S:/sdfile/EXT_RESERVED/uipackres/ui/sOpen.png");
#endif
    lv_img_set_pivot(ui->device_management_screen_sFabricCurOpen, 50,50);
    lv_img_set_angle(ui->device_management_screen_sFabricCurOpen, 0);
    lv_obj_set_pos(ui->device_management_screen_sFabricCurOpen, 132, 25);
    lv_obj_set_size(ui->device_management_screen_sFabricCurOpen, 60, 60);

    //Write style for device_management_screen_sFabricCurOpen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sFabricCurOpen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sFabricCurOpen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sFabricCurOpen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sFabricCurOpen, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_cont_6
    ui->device_management_screen_cont_6 = lv_obj_create(ui->device_management_screen_tabview_1_tab_1);
    lv_obj_set_pos(ui->device_management_screen_cont_6, 372, 362);
    lv_obj_set_size(ui->device_management_screen_cont_6, 300, 150);
    lv_obj_set_scrollbar_mode(ui->device_management_screen_cont_6, LV_SCROLLBAR_MODE_OFF);

    //Write style for device_management_screen_cont_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_management_screen_cont_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->device_management_screen_cont_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->device_management_screen_cont_6, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->device_management_screen_cont_6, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_cont_6, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_management_screen_cont_6, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->device_management_screen_cont_6, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->device_management_screen_cont_6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_management_screen_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_management_screen_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_management_screen_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_management_screen_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sSheersOn
    ui->device_management_screen_sSheersOn = lv_img_create(ui->device_management_screen_cont_6);
    lv_obj_add_flag(ui->device_management_screen_sSheersOn, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->device_management_screen_sSheersOn, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\sFCOn.png");
#else
    lv_img_set_src(ui->device_management_screen_sSheersOn, "S:/sdfile/EXT_RESERVED/uipackres/ui/sFCOn.png");
#endif
    lv_img_set_pivot(ui->device_management_screen_sSheersOn, 50,50);
    lv_img_set_angle(ui->device_management_screen_sSheersOn, 0);
    lv_obj_set_pos(ui->device_management_screen_sSheersOn, 28, 23);
    lv_obj_set_size(ui->device_management_screen_sSheersOn, 49, 43);

    //Write style for device_management_screen_sSheersOn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sSheersOn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sSheersOn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sSheersOn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sSheersOn, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sSheersOff
    ui->device_management_screen_sSheersOff = lv_img_create(ui->device_management_screen_cont_6);
    lv_obj_add_flag(ui->device_management_screen_sSheersOff, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->device_management_screen_sSheersOff, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\sFCOff.png");
#else
    lv_img_set_src(ui->device_management_screen_sSheersOff, "S:/sdfile/EXT_RESERVED/uipackres/ui/sFCOff.png");
#endif
    lv_img_set_pivot(ui->device_management_screen_sSheersOff, 50,50);
    lv_img_set_angle(ui->device_management_screen_sSheersOff, 0);
    lv_obj_set_pos(ui->device_management_screen_sSheersOff, 27, 19);
    lv_obj_set_size(ui->device_management_screen_sSheersOff, 49, 43);

    //Write style for device_management_screen_sSheersOff, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sSheersOff, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sSheersOff, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sSheersOff, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sSheersOff, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_label_7
    ui->device_management_screen_label_7 = lv_label_create(ui->device_management_screen_cont_6);
    lv_label_set_text(ui->device_management_screen_label_7, "纱帘");
    lv_label_set_long_mode(ui->device_management_screen_label_7, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->device_management_screen_label_7, 15, 92);
    lv_obj_set_size(ui->device_management_screen_label_7, 100, 35);

    //Write style for device_management_screen_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_management_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_management_screen_label_7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_label_7, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_management_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_management_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_label_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_management_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_management_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_management_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_management_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_management_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sSheerOpen
    ui->device_management_screen_sSheerOpen = lv_img_create(ui->device_management_screen_cont_6);
    lv_obj_add_flag(ui->device_management_screen_sSheerOpen, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->device_management_screen_sSheerOpen, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\sOpen.png");
#else
    lv_img_set_src(ui->device_management_screen_sSheerOpen, "S:/sdfile/EXT_RESERVED/uipackres/ui/sOpen.png");
#endif
    lv_img_set_pivot(ui->device_management_screen_sSheerOpen, 50,50);
    lv_img_set_angle(ui->device_management_screen_sSheerOpen, 0);
    lv_obj_set_pos(ui->device_management_screen_sSheerOpen, 140, 28);
    lv_obj_set_size(ui->device_management_screen_sSheerOpen, 60, 60);

    //Write style for device_management_screen_sSheerOpen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sSheerOpen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sSheerOpen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sSheerOpen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sSheerOpen, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sSheerClose
    ui->device_management_screen_sSheerClose = lv_img_create(ui->device_management_screen_cont_6);
    lv_obj_add_flag(ui->device_management_screen_sSheerClose, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->device_management_screen_sSheerClose, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\sClose.png");
#else
    lv_img_set_src(ui->device_management_screen_sSheerClose, "S:/sdfile/EXT_RESERVED/uipackres/ui/sClose.png");
#endif
    lv_img_set_pivot(ui->device_management_screen_sSheerClose, 50,50);
    lv_img_set_angle(ui->device_management_screen_sSheerClose, 0);
    lv_obj_set_pos(ui->device_management_screen_sSheerClose, 212, 28);
    lv_obj_set_size(ui->device_management_screen_sSheerClose, 60, 60);

    //Write style for device_management_screen_sSheerClose, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sSheerClose, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sSheerClose, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sSheerClose, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sSheerClose, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_cont_7
    ui->device_management_screen_cont_7 = lv_obj_create(ui->device_management_screen_tabview_1_tab_1);
    lv_obj_set_pos(ui->device_management_screen_cont_7, 21, 543);
    lv_obj_set_size(ui->device_management_screen_cont_7, 300, 150);
    lv_obj_set_scrollbar_mode(ui->device_management_screen_cont_7, LV_SCROLLBAR_MODE_OFF);

    //Write style for device_management_screen_cont_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_management_screen_cont_7, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->device_management_screen_cont_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->device_management_screen_cont_7, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->device_management_screen_cont_7, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_cont_7, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_management_screen_cont_7, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->device_management_screen_cont_7, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->device_management_screen_cont_7, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_management_screen_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_management_screen_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_management_screen_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_management_screen_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sRollBlindOn
    ui->device_management_screen_sRollBlindOn = lv_img_create(ui->device_management_screen_cont_7);
    lv_obj_add_flag(ui->device_management_screen_sRollBlindOn, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->device_management_screen_sRollBlindOn, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\sRBOn.png");
#else
    lv_img_set_src(ui->device_management_screen_sRollBlindOn, "S:/sdfile/EXT_RESERVED/uipackres/ui/sRBOn.png");
#endif
    lv_img_set_pivot(ui->device_management_screen_sRollBlindOn, 50,50);
    lv_img_set_angle(ui->device_management_screen_sRollBlindOn, 0);
    lv_obj_set_pos(ui->device_management_screen_sRollBlindOn, 28, 23);
    lv_obj_set_size(ui->device_management_screen_sRollBlindOn, 65, 20);

    //Write style for device_management_screen_sRollBlindOn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sRollBlindOn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sRollBlindOn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sRollBlindOn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sRollBlindOn, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sRollBlindOff
    ui->device_management_screen_sRollBlindOff = lv_img_create(ui->device_management_screen_cont_7);
    lv_obj_add_flag(ui->device_management_screen_sRollBlindOff, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->device_management_screen_sRollBlindOff, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\sRBOff.png");
#else
    lv_img_set_src(ui->device_management_screen_sRollBlindOff, "S:/sdfile/EXT_RESERVED/uipackres/ui/sRBOff.png");
#endif
    lv_img_set_pivot(ui->device_management_screen_sRollBlindOff, 50,50);
    lv_img_set_angle(ui->device_management_screen_sRollBlindOff, 0);
    lv_obj_set_pos(ui->device_management_screen_sRollBlindOff, 28, 24);
    lv_obj_set_size(ui->device_management_screen_sRollBlindOff, 65, 43);

    //Write style for device_management_screen_sRollBlindOff, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sRollBlindOff, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sRollBlindOff, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sRollBlindOff, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sRollBlindOff, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_label_8
    ui->device_management_screen_label_8 = lv_label_create(ui->device_management_screen_cont_7);
    lv_label_set_text(ui->device_management_screen_label_8, "卷帘");
    lv_label_set_long_mode(ui->device_management_screen_label_8, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->device_management_screen_label_8, 15, 89);
    lv_obj_set_size(ui->device_management_screen_label_8, 100, 35);

    //Write style for device_management_screen_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_management_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_management_screen_label_8, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_label_8, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_management_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_management_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_label_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_management_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_management_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_management_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_management_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_management_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sRollBlindDown
    ui->device_management_screen_sRollBlindDown = lv_img_create(ui->device_management_screen_cont_7);
    lv_obj_add_flag(ui->device_management_screen_sRollBlindDown, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->device_management_screen_sRollBlindDown, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\sDown.png");
#else
    lv_img_set_src(ui->device_management_screen_sRollBlindDown, "S:/sdfile/EXT_RESERVED/uipackres/ui/sDown.png");
#endif
    lv_img_set_pivot(ui->device_management_screen_sRollBlindDown, 50,50);
    lv_img_set_angle(ui->device_management_screen_sRollBlindDown, 0);
    lv_obj_set_pos(ui->device_management_screen_sRollBlindDown, 210, 78);
    lv_obj_set_size(ui->device_management_screen_sRollBlindDown, 60, 60);

    //Write style for device_management_screen_sRollBlindDown, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sRollBlindDown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sRollBlindDown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sRollBlindDown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sRollBlindDown, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sRollBlindUp
    ui->device_management_screen_sRollBlindUp = lv_img_create(ui->device_management_screen_cont_7);
    lv_obj_add_flag(ui->device_management_screen_sRollBlindUp, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->device_management_screen_sRollBlindUp, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\sUp.png");
#else
    lv_img_set_src(ui->device_management_screen_sRollBlindUp, "S:/sdfile/EXT_RESERVED/uipackres/ui/sUp.png");
#endif
    lv_img_set_pivot(ui->device_management_screen_sRollBlindUp, 50,50);
    lv_img_set_angle(ui->device_management_screen_sRollBlindUp, 0);
    lv_obj_set_pos(ui->device_management_screen_sRollBlindUp, 211, 8);
    lv_obj_set_size(ui->device_management_screen_sRollBlindUp, 60, 60);

    //Write style for device_management_screen_sRollBlindUp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sRollBlindUp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sRollBlindUp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sRollBlindUp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sRollBlindUp, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_cont_8
    ui->device_management_screen_cont_8 = lv_obj_create(ui->device_management_screen_tabview_1_tab_1);
    lv_obj_set_pos(ui->device_management_screen_cont_8, 372, 543);
    lv_obj_set_size(ui->device_management_screen_cont_8, 300, 150);
    lv_obj_set_scrollbar_mode(ui->device_management_screen_cont_8, LV_SCROLLBAR_MODE_OFF);

    //Write style for device_management_screen_cont_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_management_screen_cont_8, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->device_management_screen_cont_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->device_management_screen_cont_8, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->device_management_screen_cont_8, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_cont_8, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_management_screen_cont_8, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->device_management_screen_cont_8, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->device_management_screen_cont_8, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_management_screen_cont_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_management_screen_cont_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_management_screen_cont_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_management_screen_cont_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_cont_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sDreamOn
    ui->device_management_screen_sDreamOn = lv_img_create(ui->device_management_screen_cont_8);
    lv_obj_add_flag(ui->device_management_screen_sDreamOn, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->device_management_screen_sDreamOn, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\sDreamOn.png");
#else
    lv_img_set_src(ui->device_management_screen_sDreamOn, "S:/sdfile/EXT_RESERVED/uipackres/ui/sDreamOn.png");
#endif
    lv_img_set_pivot(ui->device_management_screen_sDreamOn, 50,50);
    lv_img_set_angle(ui->device_management_screen_sDreamOn, 0);
    lv_obj_set_pos(ui->device_management_screen_sDreamOn, 28, 23);
    lv_obj_set_size(ui->device_management_screen_sDreamOn, 54, 41);

    //Write style for device_management_screen_sDreamOn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sDreamOn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sDreamOn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sDreamOn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sDreamOn, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sDreamOff
    ui->device_management_screen_sDreamOff = lv_img_create(ui->device_management_screen_cont_8);
    lv_obj_add_flag(ui->device_management_screen_sDreamOff, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->device_management_screen_sDreamOff, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\sDreamOff.png");
#else
    lv_img_set_src(ui->device_management_screen_sDreamOff, "S:/sdfile/EXT_RESERVED/uipackres/ui/sDreamOff.png");
#endif
    lv_img_set_pivot(ui->device_management_screen_sDreamOff, 50,50);
    lv_img_set_angle(ui->device_management_screen_sDreamOff, 0);
    lv_obj_set_pos(ui->device_management_screen_sDreamOff, 27, 21);
    lv_obj_set_size(ui->device_management_screen_sDreamOff, 54, 41);

    //Write style for device_management_screen_sDreamOff, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sDreamOff, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sDreamOff, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sDreamOff, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sDreamOff, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_label_10
    ui->device_management_screen_label_10 = lv_label_create(ui->device_management_screen_cont_8);
    lv_label_set_text(ui->device_management_screen_label_10, "梦幻帘");
    lv_label_set_long_mode(ui->device_management_screen_label_10, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->device_management_screen_label_10, 15, 92);
    lv_obj_set_size(ui->device_management_screen_label_10, 100, 35);

    //Write style for device_management_screen_label_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_management_screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_management_screen_label_10, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_label_10, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_label_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_management_screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_management_screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_label_10, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_management_screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_management_screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_management_screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_management_screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_management_screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sDreamClose
    ui->device_management_screen_sDreamClose = lv_img_create(ui->device_management_screen_cont_8);
    lv_obj_add_flag(ui->device_management_screen_sDreamClose, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->device_management_screen_sDreamClose, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\sClose.png");
#else
    lv_img_set_src(ui->device_management_screen_sDreamClose, "S:/sdfile/EXT_RESERVED/uipackres/ui/sClose.png");
#endif
    lv_img_set_pivot(ui->device_management_screen_sDreamClose, 50,50);
    lv_img_set_angle(ui->device_management_screen_sDreamClose, 0);
    lv_obj_set_pos(ui->device_management_screen_sDreamClose, 220, 18);
    lv_obj_set_size(ui->device_management_screen_sDreamClose, 54, 60);

    //Write style for device_management_screen_sDreamClose, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sDreamClose, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sDreamClose, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sDreamClose, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sDreamClose, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sDreamOpen
    ui->device_management_screen_sDreamOpen = lv_img_create(ui->device_management_screen_cont_8);
    lv_obj_add_flag(ui->device_management_screen_sDreamOpen, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->device_management_screen_sDreamOpen, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\sOpen.png");
#else
    lv_img_set_src(ui->device_management_screen_sDreamOpen, "S:/sdfile/EXT_RESERVED/uipackres/ui/sOpen.png");
#endif
    lv_img_set_pivot(ui->device_management_screen_sDreamOpen, 50,50);
    lv_img_set_angle(ui->device_management_screen_sDreamOpen, 0);
    lv_obj_set_pos(ui->device_management_screen_sDreamOpen, 137, 23);
    lv_obj_set_size(ui->device_management_screen_sDreamOpen, 60, 60);

    //Write style for device_management_screen_sDreamOpen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sDreamOpen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sDreamOpen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sDreamOpen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sDreamOpen, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_cont_9
    ui->device_management_screen_cont_9 = lv_obj_create(ui->device_management_screen_tabview_1_tab_1);
    lv_obj_set_pos(ui->device_management_screen_cont_9, 19, 722);
    lv_obj_set_size(ui->device_management_screen_cont_9, 300, 150);
    lv_obj_set_scrollbar_mode(ui->device_management_screen_cont_9, LV_SCROLLBAR_MODE_OFF);

    //Write style for device_management_screen_cont_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_management_screen_cont_9, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->device_management_screen_cont_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->device_management_screen_cont_9, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->device_management_screen_cont_9, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_cont_9, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_management_screen_cont_9, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->device_management_screen_cont_9, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->device_management_screen_cont_9, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_management_screen_cont_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_management_screen_cont_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_management_screen_cont_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_management_screen_cont_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_cont_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_imgbtn_6
    ui->device_management_screen_imgbtn_6 = lv_imgbtn_create(ui->device_management_screen_cont_9);
    lv_obj_add_flag(ui->device_management_screen_imgbtn_6, LV_OBJ_FLAG_CHECKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_imgbtn_set_src(ui->device_management_screen_imgbtn_6, LV_IMGBTN_STATE_RELEASED, NULL, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\onoff_off.png", NULL);
    lv_imgbtn_set_src(ui->device_management_screen_imgbtn_6, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\onoff_on.png", NULL);
#else
    lv_imgbtn_set_src(ui->device_management_screen_imgbtn_6, LV_IMGBTN_STATE_RELEASED, NULL, "S:/sdfile/EXT_RESERVED/uipackres/ui/onoff_off.png", NULL);
    lv_imgbtn_set_src(ui->device_management_screen_imgbtn_6, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, "S:/sdfile/EXT_RESERVED/uipackres/ui/onoff_on.png", NULL);
#endif
    ui->device_management_screen_imgbtn_6_label = lv_label_create(ui->device_management_screen_imgbtn_6);
    lv_label_set_text(ui->device_management_screen_imgbtn_6_label, "");
    lv_label_set_long_mode(ui->device_management_screen_imgbtn_6_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->device_management_screen_imgbtn_6_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->device_management_screen_imgbtn_6, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->device_management_screen_imgbtn_6, 227, 18);
    lv_obj_set_size(ui->device_management_screen_imgbtn_6, 48, 48);

    //Write style for device_management_screen_imgbtn_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->device_management_screen_imgbtn_6, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_imgbtn_6, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_imgbtn_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_imgbtn_6, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for device_management_screen_imgbtn_6, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->device_management_screen_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->device_management_screen_imgbtn_6, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->device_management_screen_imgbtn_6, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->device_management_screen_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->device_management_screen_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for device_management_screen_imgbtn_6, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->device_management_screen_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->device_management_screen_imgbtn_6, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->device_management_screen_imgbtn_6, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->device_management_screen_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->device_management_screen_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for device_management_screen_imgbtn_6, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_imgbtn_6, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->device_management_screen_imgbtn_6, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes device_management_screen_label_9
    ui->device_management_screen_label_9 = lv_label_create(ui->device_management_screen_cont_9);
    lv_label_set_text(ui->device_management_screen_label_9, "空调");
    lv_label_set_long_mode(ui->device_management_screen_label_9, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->device_management_screen_label_9, 15, 91);
    lv_obj_set_size(ui->device_management_screen_label_9, 100, 35);

    //Write style for device_management_screen_label_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_management_screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_management_screen_label_9, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_label_9, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_label_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_management_screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_management_screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_label_9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_management_screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_management_screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_management_screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_management_screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_management_screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sTempText
    ui->device_management_screen_sTempText = lv_label_create(ui->device_management_screen_cont_9);
    lv_label_set_text(ui->device_management_screen_sTempText, "16℃");
    lv_label_set_long_mode(ui->device_management_screen_sTempText, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->device_management_screen_sTempText, 190, 91);
    lv_obj_set_size(ui->device_management_screen_sTempText, 100, 32);

    //Write style for device_management_screen_sTempText, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_management_screen_sTempText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sTempText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_management_screen_sTempText, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_sTempText, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_sTempText, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_management_screen_sTempText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_management_screen_sTempText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_sTempText, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_management_screen_sTempText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_management_screen_sTempText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_management_screen_sTempText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_management_screen_sTempText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_management_screen_sTempText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_sTempText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sOffText
    ui->device_management_screen_sOffText = lv_label_create(ui->device_management_screen_cont_9);
    lv_label_set_text(ui->device_management_screen_sOffText, "关");
    lv_label_set_long_mode(ui->device_management_screen_sOffText, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->device_management_screen_sOffText, 125, 20);
    lv_obj_set_size(ui->device_management_screen_sOffText, 61, 37);

    //Write style for device_management_screen_sOffText, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_management_screen_sOffText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sOffText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_management_screen_sOffText, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_sOffText, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_sOffText, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_management_screen_sOffText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_management_screen_sOffText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_sOffText, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_management_screen_sOffText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_management_screen_sOffText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_management_screen_sOffText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_management_screen_sOffText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_management_screen_sOffText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_sOffText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sACFanText
    ui->device_management_screen_sACFanText = lv_label_create(ui->device_management_screen_cont_9);
    lv_label_set_text(ui->device_management_screen_sACFanText, "送风");
    lv_label_set_long_mode(ui->device_management_screen_sACFanText, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->device_management_screen_sACFanText, 125, 20);
    lv_obj_set_size(ui->device_management_screen_sACFanText, 61, 37);

    //Write style for device_management_screen_sACFanText, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_management_screen_sACFanText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sACFanText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_management_screen_sACFanText, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_sACFanText, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_sACFanText, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_management_screen_sACFanText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_management_screen_sACFanText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_sACFanText, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_management_screen_sACFanText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_management_screen_sACFanText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_management_screen_sACFanText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_management_screen_sACFanText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_management_screen_sACFanText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_sACFanText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sVentilateACimg
    ui->device_management_screen_sVentilateACimg = lv_img_create(ui->device_management_screen_cont_9);
    lv_obj_add_flag(ui->device_management_screen_sVentilateACimg, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->device_management_screen_sVentilateACimg, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\sVACimg.png");
#else
    lv_img_set_src(ui->device_management_screen_sVentilateACimg, "S:/sdfile/EXT_RESERVED/uipackres/ui/sVACimg.png");
#endif
    lv_img_set_pivot(ui->device_management_screen_sVentilateACimg, 50,50);
    lv_img_set_angle(ui->device_management_screen_sVentilateACimg, 0);
    lv_obj_set_pos(ui->device_management_screen_sVentilateACimg, 25, 20);
    lv_obj_set_size(ui->device_management_screen_sVentilateACimg, 77, 49);

    //Write style for device_management_screen_sVentilateACimg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sVentilateACimg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sVentilateACimg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sVentilateACimg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sVentilateACimg, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sAC
    ui->device_management_screen_sAC = lv_img_create(ui->device_management_screen_cont_9);
    lv_obj_add_flag(ui->device_management_screen_sAC, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->device_management_screen_sAC, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\sAC.png");
#else
    lv_img_set_src(ui->device_management_screen_sAC, "S:/sdfile/EXT_RESERVED/uipackres/ui/sAC.png");
#endif
    lv_img_set_pivot(ui->device_management_screen_sAC, 50,50);
    lv_img_set_angle(ui->device_management_screen_sAC, 0);
    lv_obj_set_pos(ui->device_management_screen_sAC, 25, 17);
    lv_obj_set_size(ui->device_management_screen_sAC, 77, 49);

    //Write style for device_management_screen_sAC, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sAC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sAC, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sAC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sAC, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sACCoolText
    ui->device_management_screen_sACCoolText = lv_label_create(ui->device_management_screen_cont_9);
    lv_label_set_text(ui->device_management_screen_sACCoolText, "制冷");
    lv_label_set_long_mode(ui->device_management_screen_sACCoolText, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->device_management_screen_sACCoolText, 125, 20);
    lv_obj_set_size(ui->device_management_screen_sACCoolText, 61, 37);

    //Write style for device_management_screen_sACCoolText, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_management_screen_sACCoolText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sACCoolText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_management_screen_sACCoolText, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_sACCoolText, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_sACCoolText, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_management_screen_sACCoolText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_management_screen_sACCoolText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_sACCoolText, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_management_screen_sACCoolText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_management_screen_sACCoolText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_management_screen_sACCoolText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_management_screen_sACCoolText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_management_screen_sACCoolText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_sACCoolText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sACHotText
    ui->device_management_screen_sACHotText = lv_label_create(ui->device_management_screen_cont_9);
    lv_label_set_text(ui->device_management_screen_sACHotText, "制热");
    lv_label_set_long_mode(ui->device_management_screen_sACHotText, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->device_management_screen_sACHotText, 125, 20);
    lv_obj_set_size(ui->device_management_screen_sACHotText, 61, 37);

    //Write style for device_management_screen_sACHotText, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_management_screen_sACHotText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sACHotText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_management_screen_sACHotText, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_sACHotText, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_sACHotText, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_management_screen_sACHotText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_management_screen_sACHotText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_sACHotText, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_management_screen_sACHotText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_management_screen_sACHotText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_management_screen_sACHotText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_management_screen_sACHotText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_management_screen_sACHotText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_sACHotText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sACDryText
    ui->device_management_screen_sACDryText = lv_label_create(ui->device_management_screen_cont_9);
    lv_label_set_text(ui->device_management_screen_sACDryText, "除湿");
    lv_label_set_long_mode(ui->device_management_screen_sACDryText, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->device_management_screen_sACDryText, 125, 20);
    lv_obj_set_size(ui->device_management_screen_sACDryText, 61, 37);

    //Write style for device_management_screen_sACDryText, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_management_screen_sACDryText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sACDryText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_management_screen_sACDryText, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_sACDryText, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_sACDryText, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_management_screen_sACDryText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_management_screen_sACDryText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_sACDryText, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_management_screen_sACDryText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_management_screen_sACDryText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_management_screen_sACDryText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_management_screen_sACDryText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_management_screen_sACDryText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_sACDryText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_cont_10
    ui->device_management_screen_cont_10 = lv_obj_create(ui->device_management_screen_tabview_1_tab_1);
    lv_obj_set_pos(ui->device_management_screen_cont_10, 373, 720);
    lv_obj_set_size(ui->device_management_screen_cont_10, 300, 150);
    lv_obj_set_scrollbar_mode(ui->device_management_screen_cont_10, LV_SCROLLBAR_MODE_OFF);

    //Write style for device_management_screen_cont_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_management_screen_cont_10, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->device_management_screen_cont_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->device_management_screen_cont_10, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->device_management_screen_cont_10, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_cont_10, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_management_screen_cont_10, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->device_management_screen_cont_10, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->device_management_screen_cont_10, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_management_screen_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_management_screen_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_management_screen_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_management_screen_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sMusicPauseImg
    ui->device_management_screen_sMusicPauseImg = lv_img_create(ui->device_management_screen_cont_10);
    lv_obj_add_flag(ui->device_management_screen_sMusicPauseImg, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->device_management_screen_sMusicPauseImg, &_small_disc_alpha_51x51);
    lv_img_set_pivot(ui->device_management_screen_sMusicPauseImg, 50,50);
    lv_img_set_angle(ui->device_management_screen_sMusicPauseImg, 0);
    lv_obj_set_pos(ui->device_management_screen_sMusicPauseImg, 27, 21);
    lv_obj_set_size(ui->device_management_screen_sMusicPauseImg, 51, 51);

    //Write style for device_management_screen_sMusicPauseImg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sMusicPauseImg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sMusicPauseImg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sMusicPauseImg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sMusicPauseImg, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sMusicPlayImg
    ui->device_management_screen_sMusicPlayImg = lv_img_create(ui->device_management_screen_cont_10);
    lv_obj_add_flag(ui->device_management_screen_sMusicPlayImg, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->device_management_screen_sMusicPlayImg, &_srack_alpha_20x31);
    lv_img_set_pivot(ui->device_management_screen_sMusicPlayImg, 50,50);
    lv_img_set_angle(ui->device_management_screen_sMusicPlayImg, 0);
    lv_obj_set_pos(ui->device_management_screen_sMusicPlayImg, 70, 13);
    lv_obj_set_size(ui->device_management_screen_sMusicPlayImg, 20, 31);

    //Write style for device_management_screen_sMusicPlayImg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sMusicPlayImg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sMusicPlayImg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sMusicPlayImg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sMusicPlayImg, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_imgbtn_9
    ui->device_management_screen_imgbtn_9 = lv_imgbtn_create(ui->device_management_screen_cont_10);
    lv_obj_add_flag(ui->device_management_screen_imgbtn_9, LV_OBJ_FLAG_CHECKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_imgbtn_set_src(ui->device_management_screen_imgbtn_9, LV_IMGBTN_STATE_RELEASED, NULL, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\small_play.png", NULL);
    lv_imgbtn_set_src(ui->device_management_screen_imgbtn_9, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\small_pause.png", NULL);
#else
    lv_imgbtn_set_src(ui->device_management_screen_imgbtn_9, LV_IMGBTN_STATE_RELEASED, NULL, "S:/sdfile/EXT_RESERVED/uipackres/ui/small_play.png", NULL);
    lv_imgbtn_set_src(ui->device_management_screen_imgbtn_9, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, "S:/sdfile/EXT_RESERVED/uipackres/ui/small_pause.png", NULL);
#endif
    ui->device_management_screen_imgbtn_9_label = lv_label_create(ui->device_management_screen_imgbtn_9);
    lv_label_set_text(ui->device_management_screen_imgbtn_9_label, "");
    lv_label_set_long_mode(ui->device_management_screen_imgbtn_9_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->device_management_screen_imgbtn_9_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->device_management_screen_imgbtn_9, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->device_management_screen_imgbtn_9, 203, 15);
    lv_obj_set_size(ui->device_management_screen_imgbtn_9, 60, 60);

    //Write style for device_management_screen_imgbtn_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->device_management_screen_imgbtn_9, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_imgbtn_9, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_imgbtn_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_imgbtn_9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_imgbtn_9, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for device_management_screen_imgbtn_9, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->device_management_screen_imgbtn_9, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->device_management_screen_imgbtn_9, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->device_management_screen_imgbtn_9, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->device_management_screen_imgbtn_9, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->device_management_screen_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for device_management_screen_imgbtn_9, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->device_management_screen_imgbtn_9, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->device_management_screen_imgbtn_9, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->device_management_screen_imgbtn_9, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->device_management_screen_imgbtn_9, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->device_management_screen_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for device_management_screen_imgbtn_9, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_imgbtn_9, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->device_management_screen_imgbtn_9, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes device_management_screen_label_12
    ui->device_management_screen_label_12 = lv_label_create(ui->device_management_screen_cont_10);
    lv_label_set_text(ui->device_management_screen_label_12, "音乐");
    lv_label_set_long_mode(ui->device_management_screen_label_12, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->device_management_screen_label_12, 15, 92);
    lv_obj_set_size(ui->device_management_screen_label_12, 100, 35);

    //Write style for device_management_screen_label_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_management_screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_management_screen_label_12, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_label_12, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_label_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_management_screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_management_screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_label_12, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_management_screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_management_screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_management_screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_management_screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_management_screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_cont_11
    ui->device_management_screen_cont_11 = lv_obj_create(ui->device_management_screen_tabview_1_tab_1);
    lv_obj_set_pos(ui->device_management_screen_cont_11, 20, 905);
    lv_obj_set_size(ui->device_management_screen_cont_11, 300, 150);
    lv_obj_set_scrollbar_mode(ui->device_management_screen_cont_11, LV_SCROLLBAR_MODE_OFF);

    //Write style for device_management_screen_cont_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_management_screen_cont_11, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->device_management_screen_cont_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->device_management_screen_cont_11, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->device_management_screen_cont_11, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_cont_11, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_management_screen_cont_11, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->device_management_screen_cont_11, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->device_management_screen_cont_11, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_management_screen_cont_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_management_screen_cont_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_management_screen_cont_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_management_screen_cont_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_cont_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sDryRackDown
    ui->device_management_screen_sDryRackDown = lv_img_create(ui->device_management_screen_cont_11);
    lv_obj_add_flag(ui->device_management_screen_sDryRackDown, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->device_management_screen_sDryRackDown, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\sDryRackOn.png");
#else
    lv_img_set_src(ui->device_management_screen_sDryRackDown, "S:/sdfile/EXT_RESERVED/uipackres/ui/sDryRackOn.png");
#endif
    lv_img_set_pivot(ui->device_management_screen_sDryRackDown, 50,50);
    lv_img_set_angle(ui->device_management_screen_sDryRackDown, 0);
    lv_obj_set_pos(ui->device_management_screen_sDryRackDown, 27, 16);
    lv_obj_set_size(ui->device_management_screen_sDryRackDown, 104, 58);

    //Write style for device_management_screen_sDryRackDown, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sDryRackDown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sDryRackDown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sDryRackDown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sDryRackDown, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sDryRackUp
    ui->device_management_screen_sDryRackUp = lv_img_create(ui->device_management_screen_cont_11);
    lv_obj_add_flag(ui->device_management_screen_sDryRackUp, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->device_management_screen_sDryRackUp, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\sDryRackOff.png");
#else
    lv_img_set_src(ui->device_management_screen_sDryRackUp, "S:/sdfile/EXT_RESERVED/uipackres/ui/sDryRackOff.png");
#endif
    lv_img_set_pivot(ui->device_management_screen_sDryRackUp, 50,50);
    lv_img_set_angle(ui->device_management_screen_sDryRackUp, 0);
    lv_obj_set_pos(ui->device_management_screen_sDryRackUp, 25, 16);
    lv_obj_set_size(ui->device_management_screen_sDryRackUp, 104, 27);

    //Write style for device_management_screen_sDryRackUp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sDryRackUp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sDryRackUp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sDryRackUp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sDryRackUp, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_label_11
    ui->device_management_screen_label_11 = lv_label_create(ui->device_management_screen_cont_11);
    lv_label_set_text(ui->device_management_screen_label_11, "晾衣机");
    lv_label_set_long_mode(ui->device_management_screen_label_11, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->device_management_screen_label_11, 15, 92);
    lv_obj_set_size(ui->device_management_screen_label_11, 100, 35);

    //Write style for device_management_screen_label_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_management_screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_management_screen_label_11, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_label_11, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_label_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_management_screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_management_screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_label_11, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_management_screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_management_screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_management_screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_management_screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_management_screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sDryRackDownBtn
    ui->device_management_screen_sDryRackDownBtn = lv_img_create(ui->device_management_screen_cont_11);
    lv_obj_add_flag(ui->device_management_screen_sDryRackDownBtn, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->device_management_screen_sDryRackDownBtn, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\sDown.png");
#else
    lv_img_set_src(ui->device_management_screen_sDryRackDownBtn, "S:/sdfile/EXT_RESERVED/uipackres/ui/sDown.png");
#endif
    lv_img_set_pivot(ui->device_management_screen_sDryRackDownBtn, 50,50);
    lv_img_set_angle(ui->device_management_screen_sDryRackDownBtn, 0);
    lv_obj_set_pos(ui->device_management_screen_sDryRackDownBtn, 208, 78);
    lv_obj_set_size(ui->device_management_screen_sDryRackDownBtn, 60, 60);

    //Write style for device_management_screen_sDryRackDownBtn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sDryRackDownBtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sDryRackDownBtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sDryRackDownBtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sDryRackDownBtn, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sDryRackUpBtn
    ui->device_management_screen_sDryRackUpBtn = lv_img_create(ui->device_management_screen_cont_11);
    lv_obj_add_flag(ui->device_management_screen_sDryRackUpBtn, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->device_management_screen_sDryRackUpBtn, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\sUp.png");
#else
    lv_img_set_src(ui->device_management_screen_sDryRackUpBtn, "S:/sdfile/EXT_RESERVED/uipackres/ui/sUp.png");
#endif
    lv_img_set_pivot(ui->device_management_screen_sDryRackUpBtn, 50,50);
    lv_img_set_angle(ui->device_management_screen_sDryRackUpBtn, 0);
    lv_obj_set_pos(ui->device_management_screen_sDryRackUpBtn, 206, 4);
    lv_obj_set_size(ui->device_management_screen_sDryRackUpBtn, 60, 60);

    //Write style for device_management_screen_sDryRackUpBtn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sDryRackUpBtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sDryRackUpBtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sDryRackUpBtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sDryRackUpBtn, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_cont_12
    ui->device_management_screen_cont_12 = lv_obj_create(ui->device_management_screen_tabview_1_tab_1);
    lv_obj_set_pos(ui->device_management_screen_cont_12, 372, 905);
    lv_obj_set_size(ui->device_management_screen_cont_12, 300, 150);
    lv_obj_set_scrollbar_mode(ui->device_management_screen_cont_12, LV_SCROLLBAR_MODE_OFF);

    //Write style for device_management_screen_cont_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_management_screen_cont_12, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->device_management_screen_cont_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->device_management_screen_cont_12, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->device_management_screen_cont_12, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_cont_12, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_management_screen_cont_12, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->device_management_screen_cont_12, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->device_management_screen_cont_12, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_management_screen_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_management_screen_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_management_screen_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_management_screen_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sFanOpenImg
    ui->device_management_screen_sFanOpenImg = lv_img_create(ui->device_management_screen_cont_12);
    lv_obj_add_flag(ui->device_management_screen_sFanOpenImg, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->device_management_screen_sFanOpenImg, &_sFanAndLTon_alpha_60x60);
    lv_img_set_pivot(ui->device_management_screen_sFanOpenImg, 50,50);
    lv_img_set_angle(ui->device_management_screen_sFanOpenImg, 0);
    lv_obj_set_pos(ui->device_management_screen_sFanOpenImg, 27, 22);
    lv_obj_set_size(ui->device_management_screen_sFanOpenImg, 60, 60);

    //Write style for device_management_screen_sFanOpenImg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sFanOpenImg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sFanOpenImg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sFanOpenImg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sFanOpenImg, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sFancloseImg
    ui->device_management_screen_sFancloseImg = lv_img_create(ui->device_management_screen_cont_12);
    lv_obj_add_flag(ui->device_management_screen_sFancloseImg, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->device_management_screen_sFancloseImg, &_sFanAndLToff_alpha_60x60);
    lv_img_set_pivot(ui->device_management_screen_sFancloseImg, 50,50);
    lv_img_set_angle(ui->device_management_screen_sFancloseImg, 0);
    lv_obj_set_pos(ui->device_management_screen_sFancloseImg, 27, 22);
    lv_obj_set_size(ui->device_management_screen_sFancloseImg, 60, 60);

    //Write style for device_management_screen_sFancloseImg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sFancloseImg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sFancloseImg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sFancloseImg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sFancloseImg, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sSourceBtn
    ui->device_management_screen_sSourceBtn = lv_imgbtn_create(ui->device_management_screen_cont_12);
    lv_obj_add_flag(ui->device_management_screen_sSourceBtn, LV_OBJ_FLAG_CHECKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_imgbtn_set_src(ui->device_management_screen_sSourceBtn, LV_IMGBTN_STATE_RELEASED, NULL, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\onoff_off.png", NULL);
    lv_imgbtn_set_src(ui->device_management_screen_sSourceBtn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\onoff_on.png", NULL);
#else
    lv_imgbtn_set_src(ui->device_management_screen_sSourceBtn, LV_IMGBTN_STATE_RELEASED, NULL, "S:/sdfile/EXT_RESERVED/uipackres/ui/onoff_off.png", NULL);
    lv_imgbtn_set_src(ui->device_management_screen_sSourceBtn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, "S:/sdfile/EXT_RESERVED/uipackres/ui/onoff_on.png", NULL);
#endif
    ui->device_management_screen_sSourceBtn_label = lv_label_create(ui->device_management_screen_sSourceBtn);
    lv_label_set_text(ui->device_management_screen_sSourceBtn_label, "");
    lv_label_set_long_mode(ui->device_management_screen_sSourceBtn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->device_management_screen_sSourceBtn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->device_management_screen_sSourceBtn, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->device_management_screen_sSourceBtn, 226, 17);
    lv_obj_set_size(ui->device_management_screen_sSourceBtn, 48, 48);

    //Write style for device_management_screen_sSourceBtn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->device_management_screen_sSourceBtn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_sSourceBtn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_sSourceBtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_sSourceBtn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sSourceBtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sSourceBtn, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_sSourceBtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for device_management_screen_sSourceBtn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sSourceBtn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->device_management_screen_sSourceBtn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->device_management_screen_sSourceBtn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->device_management_screen_sSourceBtn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->device_management_screen_sSourceBtn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->device_management_screen_sSourceBtn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for device_management_screen_sSourceBtn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sSourceBtn, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->device_management_screen_sSourceBtn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->device_management_screen_sSourceBtn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->device_management_screen_sSourceBtn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->device_management_screen_sSourceBtn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->device_management_screen_sSourceBtn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for device_management_screen_sSourceBtn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sSourceBtn, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->device_management_screen_sSourceBtn, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes device_management_screen_label_14
    ui->device_management_screen_label_14 = lv_label_create(ui->device_management_screen_cont_12);
    lv_label_set_text(ui->device_management_screen_label_14, "风扇灯");
    lv_label_set_long_mode(ui->device_management_screen_label_14, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->device_management_screen_label_14, 23, 86);
    lv_obj_set_size(ui->device_management_screen_label_14, 100, 35);

    //Write style for device_management_screen_label_14, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_management_screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_management_screen_label_14, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_label_14, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_label_14, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_management_screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_management_screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_label_14, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_management_screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_management_screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_management_screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_management_screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_management_screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sFanLightBtn
    ui->device_management_screen_sFanLightBtn = lv_imgbtn_create(ui->device_management_screen_cont_12);
    lv_obj_add_flag(ui->device_management_screen_sFanLightBtn, LV_OBJ_FLAG_CHECKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_imgbtn_set_src(ui->device_management_screen_sFanLightBtn, LV_IMGBTN_STATE_RELEASED, NULL, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\slightOff.png", NULL);
    lv_imgbtn_set_src(ui->device_management_screen_sFanLightBtn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\slightOn.png", NULL);
#else
    lv_imgbtn_set_src(ui->device_management_screen_sFanLightBtn, LV_IMGBTN_STATE_RELEASED, NULL, "S:/sdfile/EXT_RESERVED/uipackres/ui/slightOff.png", NULL);
    lv_imgbtn_set_src(ui->device_management_screen_sFanLightBtn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, "S:/sdfile/EXT_RESERVED/uipackres/ui/slightOn.png", NULL);
#endif
    ui->device_management_screen_sFanLightBtn_label = lv_label_create(ui->device_management_screen_sFanLightBtn);
    lv_label_set_text(ui->device_management_screen_sFanLightBtn_label, "");
    lv_label_set_long_mode(ui->device_management_screen_sFanLightBtn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->device_management_screen_sFanLightBtn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->device_management_screen_sFanLightBtn, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->device_management_screen_sFanLightBtn, 147, 7);
    lv_obj_set_size(ui->device_management_screen_sFanLightBtn, 60, 60);

    //Write style for device_management_screen_sFanLightBtn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->device_management_screen_sFanLightBtn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_sFanLightBtn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_sFanLightBtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_sFanLightBtn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sFanLightBtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sFanLightBtn, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_sFanLightBtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for device_management_screen_sFanLightBtn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sFanLightBtn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->device_management_screen_sFanLightBtn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->device_management_screen_sFanLightBtn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->device_management_screen_sFanLightBtn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->device_management_screen_sFanLightBtn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->device_management_screen_sFanLightBtn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for device_management_screen_sFanLightBtn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sFanLightBtn, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->device_management_screen_sFanLightBtn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->device_management_screen_sFanLightBtn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->device_management_screen_sFanLightBtn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->device_management_screen_sFanLightBtn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->device_management_screen_sFanLightBtn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for device_management_screen_sFanLightBtn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sFanLightBtn, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->device_management_screen_sFanLightBtn, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes device_management_screen_cont_13
    ui->device_management_screen_cont_13 = lv_obj_create(ui->device_management_screen_tabview_1_tab_1);
    lv_obj_set_pos(ui->device_management_screen_cont_13, 20, 1086);
    lv_obj_set_size(ui->device_management_screen_cont_13, 300, 150);
    lv_obj_set_scrollbar_mode(ui->device_management_screen_cont_13, LV_SCROLLBAR_MODE_OFF);

    //Write style for device_management_screen_cont_13, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_management_screen_cont_13, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->device_management_screen_cont_13, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->device_management_screen_cont_13, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->device_management_screen_cont_13, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_cont_13, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_management_screen_cont_13, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->device_management_screen_cont_13, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->device_management_screen_cont_13, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_management_screen_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_management_screen_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_management_screen_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_management_screen_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_label_13
    ui->device_management_screen_label_13 = lv_label_create(ui->device_management_screen_cont_13);
    lv_label_set_text(ui->device_management_screen_label_13, "浴霸");
    lv_label_set_long_mode(ui->device_management_screen_label_13, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->device_management_screen_label_13, 2, 83);
    lv_obj_set_size(ui->device_management_screen_label_13, 100, 35);

    //Write style for device_management_screen_label_13, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_management_screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_management_screen_label_13, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_label_13, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_label_13, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_management_screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_management_screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_label_13, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_management_screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_management_screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_management_screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_management_screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_management_screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_IdleBtn
    ui->device_management_screen_IdleBtn = lv_img_create(ui->device_management_screen_cont_13);
    lv_obj_add_flag(ui->device_management_screen_IdleBtn, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->device_management_screen_IdleBtn, &_sIdleBtn_alpha_60x60);
    lv_img_set_pivot(ui->device_management_screen_IdleBtn, 50,50);
    lv_img_set_angle(ui->device_management_screen_IdleBtn, 0);
    lv_obj_set_pos(ui->device_management_screen_IdleBtn, 230, 15);
    lv_obj_set_size(ui->device_management_screen_IdleBtn, 60, 60);

    //Write style for device_management_screen_IdleBtn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_IdleBtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_IdleBtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_IdleBtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_IdleBtn, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sHeatLightImg
    ui->device_management_screen_sHeatLightImg = lv_img_create(ui->device_management_screen_cont_13);
    lv_obj_add_flag(ui->device_management_screen_sHeatLightImg, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->device_management_screen_sHeatLightImg, &_sHlight_alpha_65x43);
    lv_img_set_pivot(ui->device_management_screen_sHeatLightImg, 50,50);
    lv_img_set_angle(ui->device_management_screen_sHeatLightImg, 0);
    lv_obj_set_pos(ui->device_management_screen_sHeatLightImg, 20, 14);
    lv_obj_set_size(ui->device_management_screen_sHeatLightImg, 65, 43);

    //Write style for device_management_screen_sHeatLightImg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sHeatLightImg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sHeatLightImg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sHeatLightImg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sHeatLightImg, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sHeaterLightBtn
    ui->device_management_screen_sHeaterLightBtn = lv_imgbtn_create(ui->device_management_screen_cont_13);
    lv_obj_add_flag(ui->device_management_screen_sHeaterLightBtn, LV_OBJ_FLAG_CHECKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_imgbtn_set_src(ui->device_management_screen_sHeaterLightBtn, LV_IMGBTN_STATE_RELEASED, NULL, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\slightOff.png", NULL);
    lv_imgbtn_set_src(ui->device_management_screen_sHeaterLightBtn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\slightOn.png", NULL);
#else
    lv_imgbtn_set_src(ui->device_management_screen_sHeaterLightBtn, LV_IMGBTN_STATE_RELEASED, NULL, "S:/sdfile/EXT_RESERVED/uipackres/ui/slightOff.png", NULL);
    lv_imgbtn_set_src(ui->device_management_screen_sHeaterLightBtn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, "S:/sdfile/EXT_RESERVED/uipackres/ui/slightOn.png", NULL);
#endif
    ui->device_management_screen_sHeaterLightBtn_label = lv_label_create(ui->device_management_screen_sHeaterLightBtn);
    lv_label_set_text(ui->device_management_screen_sHeaterLightBtn_label, "");
    lv_label_set_long_mode(ui->device_management_screen_sHeaterLightBtn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->device_management_screen_sHeaterLightBtn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->device_management_screen_sHeaterLightBtn, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->device_management_screen_sHeaterLightBtn, 151, 17);
    lv_obj_set_size(ui->device_management_screen_sHeaterLightBtn, 60, 60);

    //Write style for device_management_screen_sHeaterLightBtn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->device_management_screen_sHeaterLightBtn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_sHeaterLightBtn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_sHeaterLightBtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_sHeaterLightBtn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sHeaterLightBtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sHeaterLightBtn, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_sHeaterLightBtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for device_management_screen_sHeaterLightBtn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sHeaterLightBtn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->device_management_screen_sHeaterLightBtn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->device_management_screen_sHeaterLightBtn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->device_management_screen_sHeaterLightBtn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->device_management_screen_sHeaterLightBtn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->device_management_screen_sHeaterLightBtn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for device_management_screen_sHeaterLightBtn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sHeaterLightBtn, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->device_management_screen_sHeaterLightBtn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->device_management_screen_sHeaterLightBtn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->device_management_screen_sHeaterLightBtn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->device_management_screen_sHeaterLightBtn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->device_management_screen_sHeaterLightBtn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for device_management_screen_sHeaterLightBtn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sHeaterLightBtn, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->device_management_screen_sHeaterLightBtn, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes device_management_screen_sHeatLowModeImg
    ui->device_management_screen_sHeatLowModeImg = lv_img_create(ui->device_management_screen_cont_13);
    lv_obj_add_flag(ui->device_management_screen_sHeatLowModeImg, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->device_management_screen_sHeatLowModeImg, &_sLowHeatMode_alpha_65x43);
    lv_img_set_pivot(ui->device_management_screen_sHeatLowModeImg, 50,50);
    lv_img_set_angle(ui->device_management_screen_sHeatLowModeImg, 0);
    lv_obj_set_pos(ui->device_management_screen_sHeatLowModeImg, 20, 14);
    lv_obj_set_size(ui->device_management_screen_sHeatLowModeImg, 65, 43);

    //Write style for device_management_screen_sHeatLowModeImg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sHeatLowModeImg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sHeatLowModeImg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sHeatLowModeImg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sHeatLowModeImg, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sHeatHighModeImg
    ui->device_management_screen_sHeatHighModeImg = lv_img_create(ui->device_management_screen_cont_13);
    lv_obj_add_flag(ui->device_management_screen_sHeatHighModeImg, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->device_management_screen_sHeatHighModeImg, &_sHeatMode_alpha_65x43);
    lv_img_set_pivot(ui->device_management_screen_sHeatHighModeImg, 50,50);
    lv_img_set_angle(ui->device_management_screen_sHeatHighModeImg, 0);
    lv_obj_set_pos(ui->device_management_screen_sHeatHighModeImg, 20, 14);
    lv_obj_set_size(ui->device_management_screen_sHeatHighModeImg, 65, 43);

    //Write style for device_management_screen_sHeatHighModeImg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sHeatHighModeImg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sHeatHighModeImg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sHeatHighModeImg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sHeatHighModeImg, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sVentilateModeImg
    ui->device_management_screen_sVentilateModeImg = lv_img_create(ui->device_management_screen_cont_13);
    lv_obj_add_flag(ui->device_management_screen_sVentilateModeImg, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->device_management_screen_sVentilateModeImg, &_sventilate_alpha_65x43);
    lv_img_set_pivot(ui->device_management_screen_sVentilateModeImg, 50,50);
    lv_img_set_angle(ui->device_management_screen_sVentilateModeImg, 0);
    lv_obj_set_pos(ui->device_management_screen_sVentilateModeImg, 20, 14);
    lv_obj_set_size(ui->device_management_screen_sVentilateModeImg, 65, 43);

    //Write style for device_management_screen_sVentilateModeImg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sVentilateModeImg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sVentilateModeImg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sVentilateModeImg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sVentilateModeImg, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sWindModeImg
    ui->device_management_screen_sWindModeImg = lv_img_create(ui->device_management_screen_cont_13);
    lv_obj_add_flag(ui->device_management_screen_sWindModeImg, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->device_management_screen_sWindModeImg, &_sFanMode_alpha_65x43);
    lv_img_set_pivot(ui->device_management_screen_sWindModeImg, 50,50);
    lv_img_set_angle(ui->device_management_screen_sWindModeImg, 0);
    lv_obj_set_pos(ui->device_management_screen_sWindModeImg, 20, 14);
    lv_obj_set_size(ui->device_management_screen_sWindModeImg, 65, 43);

    //Write style for device_management_screen_sWindModeImg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sWindModeImg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sWindModeImg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sWindModeImg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sWindModeImg, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sHeatDevImg
    ui->device_management_screen_sHeatDevImg = lv_img_create(ui->device_management_screen_cont_13);
    lv_obj_add_flag(ui->device_management_screen_sHeatDevImg, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->device_management_screen_sHeatDevImg, &_sDev_alpha_65x43);
    lv_img_set_pivot(ui->device_management_screen_sHeatDevImg, 50,50);
    lv_img_set_angle(ui->device_management_screen_sHeatDevImg, 0);
    lv_obj_set_pos(ui->device_management_screen_sHeatDevImg, 20, 14);
    lv_obj_set_size(ui->device_management_screen_sHeatDevImg, 65, 43);

    //Write style for device_management_screen_sHeatDevImg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sHeatDevImg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sHeatDevImg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sHeatDevImg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sHeatDevImg, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sidleModeImg
    ui->device_management_screen_sidleModeImg = lv_img_create(ui->device_management_screen_cont_13);
    lv_obj_add_flag(ui->device_management_screen_sidleModeImg, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->device_management_screen_sidleModeImg, &_sIdleMode_alpha_65x43);
    lv_img_set_pivot(ui->device_management_screen_sidleModeImg, 50,50);
    lv_img_set_angle(ui->device_management_screen_sidleModeImg, 0);
    lv_obj_set_pos(ui->device_management_screen_sidleModeImg, 20, 14);
    lv_obj_set_size(ui->device_management_screen_sidleModeImg, 65, 43);

    //Write style for device_management_screen_sidleModeImg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sidleModeImg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sidleModeImg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sidleModeImg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sidleModeImg, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_label_1
    ui->device_management_screen_label_1 = lv_label_create(ui->device_management_screen);
    lv_label_set_text(ui->device_management_screen_label_1, "设备管理");
    lv_label_set_long_mode(ui->device_management_screen_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->device_management_screen_label_1, 20, 20);
    lv_obj_set_size(ui->device_management_screen_label_1, 150, 40);

    //Write style for device_management_screen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->device_management_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_management_screen_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_label_1, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->device_management_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->device_management_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->device_management_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->device_management_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->device_management_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->device_management_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->device_management_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_sDRLightImg
    ui->device_management_screen_sDRLightImg = lv_img_create(ui->device_management_screen);
    lv_obj_add_flag(ui->device_management_screen_sDRLightImg, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->device_management_screen_sDRLightImg, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\sDryRackL.png");
#else
    lv_img_set_src(ui->device_management_screen_sDRLightImg, "S:/sdfile/EXT_RESERVED/uipackres/ui/sDryRackL.png");
#endif
    lv_img_set_pivot(ui->device_management_screen_sDRLightImg, 50,50);
    lv_img_set_angle(ui->device_management_screen_sDRLightImg, 0);
    lv_obj_set_pos(ui->device_management_screen_sDRLightImg, 111, 1031);
    lv_obj_set_size(ui->device_management_screen_sDRLightImg, 21, 5);

    //Write style for device_management_screen_sDRLightImg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sDRLightImg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sDRLightImg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sDRLightImg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sDRLightImg, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of device_management_screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->device_management_screen);

    //Init events for screen.
    events_init_device_management_screen(ui);
}
