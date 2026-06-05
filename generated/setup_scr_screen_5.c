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



void setup_scr_screen_5(lv_ui *ui)
{
    //Write codes screen_5
    ui->screen_5 = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_5, 720, 720);
    lv_obj_set_scrollbar_mode(ui->screen_5, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_5, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_5_tabview_1
    ui->screen_5_tabview_1 = lv_tabview_create(ui->screen_5, LV_DIR_TOP, 70);
    lv_obj_set_pos(ui->screen_5_tabview_1, 0, 0);
    lv_obj_set_size(ui->screen_5_tabview_1, 720, 720);
    lv_obj_set_scrollbar_mode(ui->screen_5_tabview_1, LV_SCROLLBAR_MODE_ON);

    //Write style for screen_5_tabview_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_5_tabview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_5_tabview_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_5_tabview_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_5_tabview_1, lv_color_hex(0x4d4d4d), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_5_tabview_1, &lv_font_ZiTiQuanWeiJunHeiW22_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_5_tabview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_5_tabview_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_5_tabview_1, 16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_5_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_5_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_5_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_5_tabview_1_extra_btnm_main_default
    static lv_style_t style_screen_5_tabview_1_extra_btnm_main_default;
    ui_init_style(&style_screen_5_tabview_1_extra_btnm_main_default);

    lv_style_set_bg_opa(&style_screen_5_tabview_1_extra_btnm_main_default, 255);
    lv_style_set_bg_color(&style_screen_5_tabview_1_extra_btnm_main_default, lv_color_hex(0x4f3f3f));
    lv_style_set_bg_grad_dir(&style_screen_5_tabview_1_extra_btnm_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_screen_5_tabview_1_extra_btnm_main_default, 0);
    lv_style_set_radius(&style_screen_5_tabview_1_extra_btnm_main_default, 0);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->screen_5_tabview_1), &style_screen_5_tabview_1_extra_btnm_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_5_tabview_1_extra_btnm_items_default
    static lv_style_t style_screen_5_tabview_1_extra_btnm_items_default;
    ui_init_style(&style_screen_5_tabview_1_extra_btnm_items_default);

    lv_style_set_text_color(&style_screen_5_tabview_1_extra_btnm_items_default, lv_color_hex(0x4d4d4d));
    lv_style_set_text_font(&style_screen_5_tabview_1_extra_btnm_items_default, &lv_font_ZiTiQuanWeiJunHeiW22_12);
    lv_style_set_text_opa(&style_screen_5_tabview_1_extra_btnm_items_default, 255);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->screen_5_tabview_1), &style_screen_5_tabview_1_extra_btnm_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_screen_5_tabview_1_extra_btnm_items_checked
    static lv_style_t style_screen_5_tabview_1_extra_btnm_items_checked;
    ui_init_style(&style_screen_5_tabview_1_extra_btnm_items_checked);

    lv_style_set_text_color(&style_screen_5_tabview_1_extra_btnm_items_checked, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_screen_5_tabview_1_extra_btnm_items_checked, &lv_font_ZiTiQuanWeiJunHeiW22_20);
    lv_style_set_text_opa(&style_screen_5_tabview_1_extra_btnm_items_checked, 255);
    lv_style_set_border_width(&style_screen_5_tabview_1_extra_btnm_items_checked, 0);
    lv_style_set_radius(&style_screen_5_tabview_1_extra_btnm_items_checked, 0);
    lv_style_set_bg_opa(&style_screen_5_tabview_1_extra_btnm_items_checked, 255);
    lv_style_set_bg_color(&style_screen_5_tabview_1_extra_btnm_items_checked, lv_color_hex(0x0f0f12));
    lv_style_set_bg_grad_dir(&style_screen_5_tabview_1_extra_btnm_items_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->screen_5_tabview_1), &style_screen_5_tabview_1_extra_btnm_items_checked, LV_PART_ITEMS|LV_STATE_CHECKED);

    //Write codes
    ui->screen_5_tabview_1_tab_1 = lv_tabview_add_tab(ui->screen_5_tabview_1,"");
    lv_obj_t * screen_5_tabview_1_tab_1_label = lv_label_create(ui->screen_5_tabview_1_tab_1);
    lv_label_set_text(screen_5_tabview_1_tab_1_label, "");

    //Write codes screen_5_label_2
    ui->screen_5_label_2 = lv_label_create(ui->screen_5);
    lv_label_set_text(ui->screen_5_label_2, "色 温 | 4850K");
    lv_label_set_long_mode(ui->screen_5_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_5_label_2, 259, 554);
    lv_obj_set_size(ui->screen_5_label_2, 211, 34);

    //Write style for screen_5_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_5_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_5_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_5_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_5_label_2, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_5_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_5_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_5_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_5_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_5_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_5_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_5_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_5_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_5_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_5_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_5_slider_2
    ui->screen_5_slider_2 = lv_slider_create(ui->screen_5);
    lv_slider_set_range(ui->screen_5_slider_2, 2700, 6500);
    lv_slider_set_mode(ui->screen_5_slider_2, LV_SLIDER_MODE_SYMMETRICAL);
    lv_slider_set_value(ui->screen_5_slider_2, 4600, LV_ANIM_OFF);
    lv_obj_set_pos(ui->screen_5_slider_2, -223, 615);
    lv_obj_set_size(ui->screen_5_slider_2, 600, 70);

    //Write style for screen_5_slider_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_5_slider_2, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_5_slider_2, lv_color_hex(0x495661), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_5_slider_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_5_slider_2, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->screen_5_slider_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->screen_5_slider_2, &_ct_bar_600x70, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->screen_5_slider_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->screen_5_slider_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_5_slider_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_5_slider_2, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_5_slider_2, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_5_slider_2, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for screen_5_slider_2, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_5_slider_2, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_5_slider_2, lv_color_hex(0x300208), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_5_slider_2, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_5_slider_2, 60, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes screen_5_slider_1
    ui->screen_5_slider_1 = lv_slider_create(ui->screen_5);
    lv_slider_set_range(ui->screen_5_slider_1, 0, 100);
    lv_slider_set_mode(ui->screen_5_slider_1, LV_SLIDER_MODE_SYMMETRICAL);
    lv_slider_set_value(ui->screen_5_slider_1, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->screen_5_slider_1, -223, 462);
    lv_obj_set_size(ui->screen_5_slider_1, 600, 70);

    //Write style for screen_5_slider_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_5_slider_1, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_5_slider_1, lv_color_hex(0xdedfdf), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_5_slider_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_5_slider_1, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->screen_5_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_5_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_5_slider_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_5_slider_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_5_slider_1, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_5_slider_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_5_slider_1, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for screen_5_slider_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_5_slider_1, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_5_slider_1, 60, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write style for screen_5_slider_1, Part: LV_PART_KNOB, State: LV_STATE_DISABLED.
    lv_obj_set_style_bg_opa(ui->screen_5_slider_1, 0, LV_PART_KNOB|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->screen_5_slider_1, 50, LV_PART_KNOB|LV_STATE_DISABLED);

    //Write codes screen_5_label_1
    ui->screen_5_label_1 = lv_label_create(ui->screen_5);
    lv_label_set_text(ui->screen_5_label_1, "亮 度 | 50%");
    lv_label_set_long_mode(ui->screen_5_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_5_label_1, 239, 396);
    lv_obj_set_size(ui->screen_5_label_1, 227, 39);

    //Write style for screen_5_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_5_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_5_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_5_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_5_label_1, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_5_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_5_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_5_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_5_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_5_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_5_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_5_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_5_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_5_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_5_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_5_CT_on_off_2_img
    ui->screen_5_CT_on_off_2_img = lv_imgbtn_create(ui->screen_5);
    lv_obj_add_flag(ui->screen_5_CT_on_off_2_img, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->screen_5_CT_on_off_2_img, LV_IMGBTN_STATE_RELEASED, NULL, &_onoff_off_alpha_48x48, NULL);
    lv_imgbtn_set_src(ui->screen_5_CT_on_off_2_img, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_onoff_on_alpha_48x48, NULL);
    ui->screen_5_CT_on_off_2_img_label = lv_label_create(ui->screen_5_CT_on_off_2_img);
    lv_label_set_text(ui->screen_5_CT_on_off_2_img_label, "");
    lv_label_set_long_mode(ui->screen_5_CT_on_off_2_img_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_5_CT_on_off_2_img_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_5_CT_on_off_2_img, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->screen_5_CT_on_off_2_img, 18, 100);
    lv_obj_set_size(ui->screen_5_CT_on_off_2_img, 48, 48);

    //Write style for screen_5_CT_on_off_2_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_5_CT_on_off_2_img, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_5_CT_on_off_2_img, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_5_CT_on_off_2_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_5_CT_on_off_2_img, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_5_CT_on_off_2_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_5_CT_on_off_2_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_5_CT_on_off_2_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_5_CT_on_off_2_img, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->screen_5_CT_on_off_2_img, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->screen_5_CT_on_off_2_img, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_5_CT_on_off_2_img, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_5_CT_on_off_2_img, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_5_CT_on_off_2_img, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_5_CT_on_off_2_img, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_5_CT_on_off_2_img, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->screen_5_CT_on_off_2_img, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->screen_5_CT_on_off_2_img, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_5_CT_on_off_2_img, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_5_CT_on_off_2_img, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_5_CT_on_off_2_img, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_5_CT_on_off_2_img, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_5_CT_on_off_2_img, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->screen_5_CT_on_off_2_img, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->screen_5_CT_on_off_2_img, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes screen_5_dev_shell_img
    ui->screen_5_dev_shell_img = lv_img_create(ui->screen_5);
    lv_obj_add_flag(ui->screen_5_dev_shell_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_5_dev_shell_img, &_dev_shell_alpha_100x100);
    lv_img_set_pivot(ui->screen_5_dev_shell_img, 50,50);
    lv_img_set_angle(ui->screen_5_dev_shell_img, 0);
    lv_obj_set_pos(ui->screen_5_dev_shell_img, 269, 101);
    lv_obj_set_size(ui->screen_5_dev_shell_img, 100, 100);

    //Write style for screen_5_dev_shell_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_5_dev_shell_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_5_dev_shell_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_5_dev_shell_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_5_dev_shell_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_5_dev_white_lid
    ui->screen_5_dev_white_lid = lv_img_create(ui->screen_5);
    lv_obj_add_flag(ui->screen_5_dev_white_lid, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_5_dev_white_lid, &_dev_white_lid_alpha_174x27);
    lv_img_set_pivot(ui->screen_5_dev_white_lid, 50,50);
    lv_img_set_angle(ui->screen_5_dev_white_lid, 0);
    lv_obj_set_pos(ui->screen_5_dev_white_lid, 232, 181);
    lv_obj_set_size(ui->screen_5_dev_white_lid, 174, 27);

    //Write style for screen_5_dev_white_lid, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_5_dev_white_lid, 176, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->screen_5_dev_white_lid, lv_color_hex(0x0a0a0a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_5_dev_white_lid, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_5_dev_white_lid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_5_dev_white_lid, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_5_dev_orange_img
    ui->screen_5_dev_orange_img = lv_img_create(ui->screen_5);
    lv_obj_add_flag(ui->screen_5_dev_orange_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_5_dev_orange_img, &_dev_orange_alpha_280x80);
    lv_img_set_pivot(ui->screen_5_dev_orange_img, 50,50);
    lv_img_set_angle(ui->screen_5_dev_orange_img, 10);
    lv_obj_set_pos(ui->screen_5_dev_orange_img, 180, 185);
    lv_obj_set_size(ui->screen_5_dev_orange_img, 280, 80);

    //Write style for screen_5_dev_orange_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_5_dev_orange_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_5_dev_orange_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_5_dev_orange_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_5_dev_orange_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_5_dev_white_img
    ui->screen_5_dev_white_img = lv_img_create(ui->screen_5);
    lv_obj_add_flag(ui->screen_5_dev_white_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_5_dev_white_img, &_dev_white_alpha_280x80);
    lv_img_set_pivot(ui->screen_5_dev_white_img, 50,50);
    lv_img_set_angle(ui->screen_5_dev_white_img, 10);
    lv_obj_set_pos(ui->screen_5_dev_white_img, 180, 185);
    lv_obj_set_size(ui->screen_5_dev_white_img, 280, 80);

    //Write style for screen_5_dev_white_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_5_dev_white_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_5_dev_white_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_5_dev_white_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_5_dev_white_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_5_imgbtn_1
    ui->screen_5_imgbtn_1 = lv_imgbtn_create(ui->screen_5);
    lv_obj_add_flag(ui->screen_5_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->screen_5_imgbtn_1, LV_IMGBTN_STATE_RELEASED, NULL, &_scene_btn_alpha_48x48, NULL);
    lv_imgbtn_set_src(ui->screen_5_imgbtn_1, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_scene_btn_close_alpha_48x48, NULL);
    ui->screen_5_imgbtn_1_label = lv_label_create(ui->screen_5_imgbtn_1);
    lv_label_set_text(ui->screen_5_imgbtn_1_label, "");
    lv_label_set_long_mode(ui->screen_5_imgbtn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_5_imgbtn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_5_imgbtn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->screen_5_imgbtn_1, 652, 100);
    lv_obj_set_size(ui->screen_5_imgbtn_1, 48, 48);

    //Write style for screen_5_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_5_imgbtn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_5_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_5_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_5_imgbtn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_5_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_5_imgbtn_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_5_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_5_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->screen_5_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->screen_5_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_5_imgbtn_1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_5_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_5_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_5_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_5_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->screen_5_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->screen_5_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_5_imgbtn_1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_5_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_5_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_5_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_5_imgbtn_1, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->screen_5_imgbtn_1, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->screen_5_imgbtn_1, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes screen_5_btn_1
    ui->screen_5_btn_1 = lv_btn_create(ui->screen_5);
    ui->screen_5_btn_1_label = lv_label_create(ui->screen_5_btn_1);
    lv_label_set_text(ui->screen_5_btn_1_label, "<  色温灯");
    lv_label_set_long_mode(ui->screen_5_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_5_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_5_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_5_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_5_btn_1, 11, 7);
    lv_obj_set_size(ui->screen_5_btn_1, 156, 50);

    //Write style for screen_5_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_5_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_5_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_5_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_5_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_5_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_5_btn_1, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_5_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_5_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_5_cont_1
    ui->screen_5_cont_1 = lv_obj_create(ui->screen_5);
    lv_obj_set_pos(ui->screen_5_cont_1, 910, 0);
    lv_obj_set_size(ui->screen_5_cont_1, 720, 650);
    lv_obj_set_scrollbar_mode(ui->screen_5_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_5_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_5_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_5_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_5_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_5_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_5_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_5_cont_1, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_5_cont_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_5_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_5_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_5_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_5_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_5_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_5_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_5.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_5);

    //Init events for screen.
    events_init_screen_5(ui);
}
