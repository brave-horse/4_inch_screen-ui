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
    lv_obj_set_pos(ui->device_management_screen_cont_1, 18, 0);
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
    lv_imgbtn_set_src(ui->device_management_screen_Light_CT_on_off_1_img, LV_IMGBTN_STATE_RELEASED, NULL, "S:/sdfile/EXT_RESERVED/uipackres/ui/dev_manage/onoff_off.png", NULL);
    lv_imgbtn_set_src(ui->device_management_screen_Light_CT_on_off_1_img, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, "S:/sdfile/EXT_RESERVED/uipackres/ui/dev_manage/onoff_on.png", NULL);
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
    lv_img_set_src(ui->device_management_screen_sdev_on, "S:/sdfile/EXT_RESERVED/uipackres/ui/dev_manage/sdev_on.png");
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

    //Write codes device_management_screen_sdev_off
    ui->device_management_screen_sdev_off = lv_img_create(ui->device_management_screen_cont_1);
    lv_obj_add_flag(ui->device_management_screen_sdev_off, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->device_management_screen_sdev_off, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\sdev_off.png");
#else
    lv_img_set_src(ui->device_management_screen_sdev_off, "S:/sdfile/EXT_RESERVED/uipackres/ui/dev_manage/sdev_off.png");
#endif
    lv_img_set_pivot(ui->device_management_screen_sdev_off, 50,50);
    lv_img_set_angle(ui->device_management_screen_sdev_off, 0);
    lv_obj_set_pos(ui->device_management_screen_sdev_off, 40, 13);
    lv_obj_set_size(ui->device_management_screen_sdev_off, 50, 57);

    //Write style for device_management_screen_sdev_off, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->device_management_screen_sdev_off, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->device_management_screen_sdev_off, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_sdev_off, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->device_management_screen_sdev_off, true, LV_PART_MAIN|LV_STATE_DEFAULT);

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

    //Write codes device_management_screen_btn_4
    ui->device_management_screen_btn_4 = lv_btn_create(ui->device_management_screen_tabview_1_tab_1);
    lv_obj_add_flag(ui->device_management_screen_btn_4, LV_OBJ_FLAG_CHECKABLE);
    ui->device_management_screen_btn_4_label = lv_label_create(ui->device_management_screen_btn_4);
    lv_label_set_text(ui->device_management_screen_btn_4_label, "按键1");
    lv_label_set_long_mode(ui->device_management_screen_btn_4_label, LV_LABEL_LONG_CLIP);
    lv_obj_align(ui->device_management_screen_btn_4_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->device_management_screen_btn_4, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->device_management_screen_btn_4_label, LV_PCT(100));
    lv_obj_set_pos(ui->device_management_screen_btn_4, 376, 211);
    lv_obj_set_size(ui->device_management_screen_btn_4, 300, 150);

    //Write style for device_management_screen_btn_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->device_management_screen_btn_4, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->device_management_screen_btn_4, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->device_management_screen_btn_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->device_management_screen_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_btn_4, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_management_screen_btn_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_btn_4, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_btn_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_btn_3
    ui->device_management_screen_btn_3 = lv_btn_create(ui->device_management_screen_tabview_1_tab_1);
    lv_obj_add_flag(ui->device_management_screen_btn_3, LV_OBJ_FLAG_CHECKABLE);
    ui->device_management_screen_btn_3_label = lv_label_create(ui->device_management_screen_btn_3);
    lv_label_set_text(ui->device_management_screen_btn_3_label, "按键1");
    lv_label_set_long_mode(ui->device_management_screen_btn_3_label, LV_LABEL_LONG_CLIP);
    lv_obj_align(ui->device_management_screen_btn_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->device_management_screen_btn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->device_management_screen_btn_3_label, LV_PCT(100));
    lv_obj_set_pos(ui->device_management_screen_btn_3, 13, 212);
    lv_obj_set_size(ui->device_management_screen_btn_3, 300, 150);

    //Write style for device_management_screen_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->device_management_screen_btn_3, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->device_management_screen_btn_3, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->device_management_screen_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->device_management_screen_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_btn_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_management_screen_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_btn_3, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_btn_6
    ui->device_management_screen_btn_6 = lv_btn_create(ui->device_management_screen_tabview_1_tab_1);
    lv_obj_add_flag(ui->device_management_screen_btn_6, LV_OBJ_FLAG_CHECKABLE);
    ui->device_management_screen_btn_6_label = lv_label_create(ui->device_management_screen_btn_6);
    lv_label_set_text(ui->device_management_screen_btn_6_label, "按键1");
    lv_label_set_long_mode(ui->device_management_screen_btn_6_label, LV_LABEL_LONG_CLIP);
    lv_obj_align(ui->device_management_screen_btn_6_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->device_management_screen_btn_6, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->device_management_screen_btn_6_label, LV_PCT(100));
    lv_obj_set_pos(ui->device_management_screen_btn_6, 14, 602);
    lv_obj_set_size(ui->device_management_screen_btn_6, 300, 150);

    //Write style for device_management_screen_btn_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->device_management_screen_btn_6, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->device_management_screen_btn_6, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->device_management_screen_btn_6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->device_management_screen_btn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_btn_6, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_btn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_management_screen_btn_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_btn_6, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_btn_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_btn_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_btn_5
    ui->device_management_screen_btn_5 = lv_btn_create(ui->device_management_screen_tabview_1_tab_1);
    lv_obj_add_flag(ui->device_management_screen_btn_5, LV_OBJ_FLAG_CHECKABLE);
    ui->device_management_screen_btn_5_label = lv_label_create(ui->device_management_screen_btn_5);
    lv_label_set_text(ui->device_management_screen_btn_5_label, "按键1");
    lv_label_set_long_mode(ui->device_management_screen_btn_5_label, LV_LABEL_LONG_CLIP);
    lv_obj_align(ui->device_management_screen_btn_5_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->device_management_screen_btn_5, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->device_management_screen_btn_5_label, LV_PCT(100));
    lv_obj_set_pos(ui->device_management_screen_btn_5, 14, 407);
    lv_obj_set_size(ui->device_management_screen_btn_5, 300, 150);

    //Write style for device_management_screen_btn_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->device_management_screen_btn_5, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->device_management_screen_btn_5, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->device_management_screen_btn_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->device_management_screen_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_btn_5, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_management_screen_btn_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_btn_5, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_btn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_btn_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_btn_8
    ui->device_management_screen_btn_8 = lv_btn_create(ui->device_management_screen_tabview_1_tab_1);
    lv_obj_add_flag(ui->device_management_screen_btn_8, LV_OBJ_FLAG_CHECKABLE);
    ui->device_management_screen_btn_8_label = lv_label_create(ui->device_management_screen_btn_8);
    lv_label_set_text(ui->device_management_screen_btn_8_label, "按键1");
    lv_label_set_long_mode(ui->device_management_screen_btn_8_label, LV_LABEL_LONG_CLIP);
    lv_obj_align(ui->device_management_screen_btn_8_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->device_management_screen_btn_8, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->device_management_screen_btn_8_label, LV_PCT(100));
    lv_obj_set_pos(ui->device_management_screen_btn_8, 376, 599);
    lv_obj_set_size(ui->device_management_screen_btn_8, 300, 150);

    //Write style for device_management_screen_btn_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->device_management_screen_btn_8, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->device_management_screen_btn_8, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->device_management_screen_btn_8, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->device_management_screen_btn_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_btn_8, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_btn_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_management_screen_btn_8, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_btn_8, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_btn_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_btn_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_btn_7
    ui->device_management_screen_btn_7 = lv_btn_create(ui->device_management_screen_tabview_1_tab_1);
    lv_obj_add_flag(ui->device_management_screen_btn_7, LV_OBJ_FLAG_CHECKABLE);
    ui->device_management_screen_btn_7_label = lv_label_create(ui->device_management_screen_btn_7);
    lv_label_set_text(ui->device_management_screen_btn_7_label, "按键1");
    lv_label_set_long_mode(ui->device_management_screen_btn_7_label, LV_LABEL_LONG_CLIP);
    lv_obj_align(ui->device_management_screen_btn_7_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->device_management_screen_btn_7, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->device_management_screen_btn_7_label, LV_PCT(100));
    lv_obj_set_pos(ui->device_management_screen_btn_7, 376, 405);
    lv_obj_set_size(ui->device_management_screen_btn_7, 300, 150);

    //Write style for device_management_screen_btn_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->device_management_screen_btn_7, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->device_management_screen_btn_7, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->device_management_screen_btn_7, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->device_management_screen_btn_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_btn_7, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_btn_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_management_screen_btn_7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_btn_7, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_btn_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_btn_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_btn_9
    ui->device_management_screen_btn_9 = lv_btn_create(ui->device_management_screen_tabview_1_tab_1);
    lv_obj_add_flag(ui->device_management_screen_btn_9, LV_OBJ_FLAG_CHECKABLE);
    ui->device_management_screen_btn_9_label = lv_label_create(ui->device_management_screen_btn_9);
    lv_label_set_text(ui->device_management_screen_btn_9_label, "按键1");
    lv_label_set_long_mode(ui->device_management_screen_btn_9_label, LV_LABEL_LONG_CLIP);
    lv_obj_align(ui->device_management_screen_btn_9_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->device_management_screen_btn_9, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->device_management_screen_btn_9_label, LV_PCT(100));
    lv_obj_set_pos(ui->device_management_screen_btn_9, 14, 797);
    lv_obj_set_size(ui->device_management_screen_btn_9, 300, 150);

    //Write style for device_management_screen_btn_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->device_management_screen_btn_9, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->device_management_screen_btn_9, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->device_management_screen_btn_9, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->device_management_screen_btn_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_btn_9, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_btn_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_management_screen_btn_9, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_btn_9, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_btn_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_btn_9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_btn_10
    ui->device_management_screen_btn_10 = lv_btn_create(ui->device_management_screen_tabview_1_tab_1);
    lv_obj_add_flag(ui->device_management_screen_btn_10, LV_OBJ_FLAG_CHECKABLE);
    ui->device_management_screen_btn_10_label = lv_label_create(ui->device_management_screen_btn_10);
    lv_label_set_text(ui->device_management_screen_btn_10_label, "按键1");
    lv_label_set_long_mode(ui->device_management_screen_btn_10_label, LV_LABEL_LONG_CLIP);
    lv_obj_align(ui->device_management_screen_btn_10_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->device_management_screen_btn_10, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->device_management_screen_btn_10_label, LV_PCT(100));
    lv_obj_set_pos(ui->device_management_screen_btn_10, 376, 793);
    lv_obj_set_size(ui->device_management_screen_btn_10, 300, 150);

    //Write style for device_management_screen_btn_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->device_management_screen_btn_10, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->device_management_screen_btn_10, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->device_management_screen_btn_10, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->device_management_screen_btn_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->device_management_screen_btn_10, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->device_management_screen_btn_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->device_management_screen_btn_10, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->device_management_screen_btn_10, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->device_management_screen_btn_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->device_management_screen_btn_10, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes device_management_screen_cont_2
    ui->device_management_screen_cont_2 = lv_obj_create(ui->device_management_screen_tabview_1_tab_1);
    lv_obj_set_pos(ui->device_management_screen_cont_2, 372, -1);
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

    //The custom code of device_management_screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->device_management_screen);

    //Init events for screen.
    events_init_device_management_screen(ui);
}
