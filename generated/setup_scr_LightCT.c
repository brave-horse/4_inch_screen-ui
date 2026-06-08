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



void setup_scr_LightCT(lv_ui *ui)
{
    //Write codes LightCT
    ui->LightCT = lv_obj_create(NULL);
    lv_obj_set_size(ui->LightCT, 720, 720);
    lv_obj_set_scrollbar_mode(ui->LightCT, LV_SCROLLBAR_MODE_OFF);

    //Write style for LightCT, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->LightCT, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->LightCT, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->LightCT, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes LightCT_tabview_1
    ui->LightCT_tabview_1 = lv_tabview_create(ui->LightCT, LV_DIR_TOP, 70);
    lv_obj_set_pos(ui->LightCT_tabview_1, 0, 0);
    lv_obj_set_size(ui->LightCT_tabview_1, 720, 720);
    lv_obj_set_scrollbar_mode(ui->LightCT_tabview_1, LV_SCROLLBAR_MODE_ON);

    //Write style for LightCT_tabview_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->LightCT_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->LightCT_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->LightCT_tabview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->LightCT_tabview_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->LightCT_tabview_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->LightCT_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->LightCT_tabview_1, lv_color_hex(0x4d4d4d), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->LightCT_tabview_1, &lv_font_ZiTiQuanWeiJunHeiW22_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->LightCT_tabview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->LightCT_tabview_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->LightCT_tabview_1, 16, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_LightCT_tabview_1_extra_btnm_main_default
    static lv_style_t style_LightCT_tabview_1_extra_btnm_main_default;
    ui_init_style(&style_LightCT_tabview_1_extra_btnm_main_default);

    lv_style_set_bg_opa(&style_LightCT_tabview_1_extra_btnm_main_default, 255);
    lv_style_set_bg_color(&style_LightCT_tabview_1_extra_btnm_main_default, lv_color_hex(0x4f3f3f));
    lv_style_set_bg_grad_dir(&style_LightCT_tabview_1_extra_btnm_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_LightCT_tabview_1_extra_btnm_main_default, 0);
    lv_style_set_radius(&style_LightCT_tabview_1_extra_btnm_main_default, 0);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->LightCT_tabview_1), &style_LightCT_tabview_1_extra_btnm_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_LightCT_tabview_1_extra_btnm_items_default
    static lv_style_t style_LightCT_tabview_1_extra_btnm_items_default;
    ui_init_style(&style_LightCT_tabview_1_extra_btnm_items_default);

    lv_style_set_text_color(&style_LightCT_tabview_1_extra_btnm_items_default, lv_color_hex(0x4d4d4d));
    lv_style_set_text_font(&style_LightCT_tabview_1_extra_btnm_items_default, &lv_font_ZiTiQuanWeiJunHeiW22_12);
    lv_style_set_text_opa(&style_LightCT_tabview_1_extra_btnm_items_default, 255);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->LightCT_tabview_1), &style_LightCT_tabview_1_extra_btnm_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_LightCT_tabview_1_extra_btnm_items_checked
    static lv_style_t style_LightCT_tabview_1_extra_btnm_items_checked;
    ui_init_style(&style_LightCT_tabview_1_extra_btnm_items_checked);

    lv_style_set_text_color(&style_LightCT_tabview_1_extra_btnm_items_checked, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_LightCT_tabview_1_extra_btnm_items_checked, &lv_font_ZiTiQuanWeiJunHeiW22_20);
    lv_style_set_text_opa(&style_LightCT_tabview_1_extra_btnm_items_checked, 255);
    lv_style_set_border_width(&style_LightCT_tabview_1_extra_btnm_items_checked, 0);
    lv_style_set_radius(&style_LightCT_tabview_1_extra_btnm_items_checked, 0);
    lv_style_set_bg_opa(&style_LightCT_tabview_1_extra_btnm_items_checked, 255);
    lv_style_set_bg_color(&style_LightCT_tabview_1_extra_btnm_items_checked, lv_color_hex(0x0f0f12));
    lv_style_set_bg_grad_dir(&style_LightCT_tabview_1_extra_btnm_items_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->LightCT_tabview_1), &style_LightCT_tabview_1_extra_btnm_items_checked, LV_PART_ITEMS|LV_STATE_CHECKED);

    //Write codes
    ui->LightCT_tabview_1_tab_1 = lv_tabview_add_tab(ui->LightCT_tabview_1,"");
    lv_obj_t * LightCT_tabview_1_tab_1_label = lv_label_create(ui->LightCT_tabview_1_tab_1);
    lv_label_set_text(LightCT_tabview_1_tab_1_label, "");

    //Write codes LightCT_cont_1
    ui->LightCT_cont_1 = lv_obj_create(ui->LightCT);
    lv_obj_set_pos(ui->LightCT_cont_1, 0, 72);
    lv_obj_set_size(ui->LightCT_cont_1, 720, 645);
    lv_obj_set_scrollbar_mode(ui->LightCT_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for LightCT_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->LightCT_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->LightCT_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->LightCT_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->LightCT_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->LightCT_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->LightCT_cont_1, 133, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->LightCT_cont_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->LightCT_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->LightCT_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->LightCT_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->LightCT_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->LightCT_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->LightCT_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes LightCT_label_2
    ui->LightCT_label_2 = lv_label_create(ui->LightCT);
    lv_label_set_text(ui->LightCT_label_2, "色 温 | 4850K");
    lv_label_set_long_mode(ui->LightCT_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->LightCT_label_2, 258, 576);
    lv_obj_set_size(ui->LightCT_label_2, 211, 34);

    //Write style for LightCT_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->LightCT_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->LightCT_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->LightCT_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->LightCT_label_2, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->LightCT_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->LightCT_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->LightCT_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->LightCT_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->LightCT_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->LightCT_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->LightCT_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->LightCT_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->LightCT_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->LightCT_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes LightCT_ct_bar
    ui->LightCT_ct_bar = lv_img_create(ui->LightCT);
    lv_obj_add_flag(ui->LightCT_ct_bar, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->LightCT_ct_bar, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\ct_bar.png");
#else
    lv_img_set_src(ui->LightCT_ct_bar, "S:/sdfile/EXT_RESERVED/uipackres/ui/ct_bar.png");
#endif
    lv_img_set_pivot(ui->LightCT_ct_bar, 50,50);
    lv_img_set_angle(ui->LightCT_ct_bar, 0);
    lv_obj_set_pos(ui->LightCT_ct_bar, -216, 623);
    lv_obj_set_size(ui->LightCT_ct_bar, 600, 70);

    //Write style for LightCT_ct_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->LightCT_ct_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->LightCT_ct_bar, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->LightCT_ct_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->LightCT_ct_bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes LightCT_slider_2
    ui->LightCT_slider_2 = lv_slider_create(ui->LightCT);
    lv_slider_set_range(ui->LightCT_slider_2, 2700, 6500);
    lv_slider_set_mode(ui->LightCT_slider_2, LV_SLIDER_MODE_SYMMETRICAL);
    lv_slider_set_value(ui->LightCT_slider_2, 4600, LV_ANIM_OFF);
    lv_obj_set_pos(ui->LightCT_slider_2, -216, 623);
    lv_obj_set_size(ui->LightCT_slider_2, 600, 70);

    //Write style for LightCT_slider_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->LightCT_slider_2, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->LightCT_slider_2, lv_color_hex(0x495661), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->LightCT_slider_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->LightCT_slider_2, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->LightCT_slider_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->LightCT_slider_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for LightCT_slider_2, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->LightCT_slider_2, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->LightCT_slider_2, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for LightCT_slider_2, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->LightCT_slider_2, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->LightCT_slider_2, lv_color_hex(0x300208), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->LightCT_slider_2, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->LightCT_slider_2, 60, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes LightCT_slider_1
    ui->LightCT_slider_1 = lv_slider_create(ui->LightCT);
    lv_slider_set_range(ui->LightCT_slider_1, 0, 100);
    lv_slider_set_mode(ui->LightCT_slider_1, LV_SLIDER_MODE_SYMMETRICAL);
    lv_slider_set_value(ui->LightCT_slider_1, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->LightCT_slider_1, -221, 481);
    lv_obj_set_size(ui->LightCT_slider_1, 600, 70);

    //Write style for LightCT_slider_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->LightCT_slider_1, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->LightCT_slider_1, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->LightCT_slider_1, lv_color_hex(0xdedfdf), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->LightCT_slider_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->LightCT_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->LightCT_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for LightCT_slider_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->LightCT_slider_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->LightCT_slider_1, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->LightCT_slider_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->LightCT_slider_1, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for LightCT_slider_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->LightCT_slider_1, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->LightCT_slider_1, 60, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write style for LightCT_slider_1, Part: LV_PART_KNOB, State: LV_STATE_DISABLED.
    lv_obj_set_style_bg_opa(ui->LightCT_slider_1, 0, LV_PART_KNOB|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->LightCT_slider_1, 50, LV_PART_KNOB|LV_STATE_DISABLED);

    //Write codes LightCT_label_1
    ui->LightCT_label_1 = lv_label_create(ui->LightCT);
    lv_label_set_text(ui->LightCT_label_1, "亮 度 | 50%");
    lv_label_set_long_mode(ui->LightCT_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->LightCT_label_1, 241, 424);
    lv_obj_set_size(ui->LightCT_label_1, 227, 39);

    //Write style for LightCT_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->LightCT_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->LightCT_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->LightCT_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->LightCT_label_1, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->LightCT_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->LightCT_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->LightCT_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->LightCT_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->LightCT_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->LightCT_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->LightCT_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->LightCT_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->LightCT_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->LightCT_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes LightCT_dev_shell_img
    ui->LightCT_dev_shell_img = lv_img_create(ui->LightCT);
    lv_obj_add_flag(ui->LightCT_dev_shell_img, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->LightCT_dev_shell_img, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\dev_shell.png");
#else
    lv_img_set_src(ui->LightCT_dev_shell_img, "S:/sdfile/EXT_RESERVED/uipackres/ui/dev_shell.png");
#endif
    lv_img_set_pivot(ui->LightCT_dev_shell_img, 50,50);
    lv_img_set_angle(ui->LightCT_dev_shell_img, 0);
    lv_obj_set_pos(ui->LightCT_dev_shell_img, 270, 72);
    lv_obj_set_size(ui->LightCT_dev_shell_img, 166, 190);

    //Write style for LightCT_dev_shell_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->LightCT_dev_shell_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->LightCT_dev_shell_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->LightCT_dev_shell_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->LightCT_dev_shell_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes LightCT_white_lid
    ui->LightCT_white_lid = lv_img_create(ui->LightCT);
    lv_obj_add_flag(ui->LightCT_white_lid, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->LightCT_white_lid, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\white_lid.png");
#else
    lv_img_set_src(ui->LightCT_white_lid, "S:/sdfile/EXT_RESERVED/uipackres/ui/white_lid.png");
#endif
    lv_img_set_pivot(ui->LightCT_white_lid, 50,50);
    lv_img_set_angle(ui->LightCT_white_lid, 0);
    lv_obj_set_pos(ui->LightCT_white_lid, 207, 222);
    lv_obj_set_size(ui->LightCT_white_lid, 293, 60);

    //Write style for LightCT_white_lid, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->LightCT_white_lid, 184, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->LightCT_white_lid, lv_color_hex(0x090909), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->LightCT_white_lid, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->LightCT_white_lid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->LightCT_white_lid, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes LightCT_dev_orange_img
    ui->LightCT_dev_orange_img = lv_img_create(ui->LightCT);
    lv_obj_add_flag(ui->LightCT_dev_orange_img, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->LightCT_dev_orange_img, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\dev_orange.png");
#else
    lv_img_set_src(ui->LightCT_dev_orange_img, "S:/sdfile/EXT_RESERVED/uipackres/ui/dev_orange.png");
#endif
    lv_img_set_pivot(ui->LightCT_dev_orange_img, 50,50);
    lv_img_set_angle(ui->LightCT_dev_orange_img, 10);
    lv_obj_set_pos(ui->LightCT_dev_orange_img, 107, 232);
    lv_obj_set_size(ui->LightCT_dev_orange_img, 490, 164);

    //Write style for LightCT_dev_orange_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->LightCT_dev_orange_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->LightCT_dev_orange_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->LightCT_dev_orange_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->LightCT_dev_orange_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes LightCT_dev_white_img
    ui->LightCT_dev_white_img = lv_img_create(ui->LightCT);
    lv_obj_add_flag(ui->LightCT_dev_white_img, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->LightCT_dev_white_img, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\dev_white.png");
#else
    lv_img_set_src(ui->LightCT_dev_white_img, "S:/sdfile/EXT_RESERVED/uipackres/ui/dev_white.png");
#endif
    lv_img_set_pivot(ui->LightCT_dev_white_img, 50,50);
    lv_img_set_angle(ui->LightCT_dev_white_img, 10);
    lv_obj_set_pos(ui->LightCT_dev_white_img, 109, 232);
    lv_obj_set_size(ui->LightCT_dev_white_img, 490, 164);

    //Write style for LightCT_dev_white_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->LightCT_dev_white_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->LightCT_dev_white_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->LightCT_dev_white_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->LightCT_dev_white_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes LightCT_imgbtn_1
    ui->LightCT_imgbtn_1 = lv_imgbtn_create(ui->LightCT);
    lv_obj_add_flag(ui->LightCT_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_imgbtn_set_src(ui->LightCT_imgbtn_1, LV_IMGBTN_STATE_RELEASED, NULL, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\scene_btn.png", NULL);
    lv_imgbtn_set_src(ui->LightCT_imgbtn_1, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\btn_close.png", NULL);
#else
    lv_imgbtn_set_src(ui->LightCT_imgbtn_1, LV_IMGBTN_STATE_RELEASED, NULL, "S:/sdfile/EXT_RESERVED/uipackres/ui/scene_btn.png", NULL);
    lv_imgbtn_set_src(ui->LightCT_imgbtn_1, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, "S:/sdfile/EXT_RESERVED/uipackres/ui/btn_close.png", NULL);
#endif
    ui->LightCT_imgbtn_1_label = lv_label_create(ui->LightCT_imgbtn_1);
    lv_label_set_text(ui->LightCT_imgbtn_1_label, "");
    lv_label_set_long_mode(ui->LightCT_imgbtn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->LightCT_imgbtn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->LightCT_imgbtn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->LightCT_imgbtn_1, 652, 101);
    lv_obj_set_size(ui->LightCT_imgbtn_1, 48, 48);

    //Write style for LightCT_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->LightCT_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->LightCT_imgbtn_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->LightCT_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->LightCT_imgbtn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->LightCT_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->LightCT_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->LightCT_imgbtn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for LightCT_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_shadow_width(ui->LightCT_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->LightCT_imgbtn_1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->LightCT_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->LightCT_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_recolor_opa(ui->LightCT_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->LightCT_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for LightCT_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_shadow_width(ui->LightCT_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->LightCT_imgbtn_1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->LightCT_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->LightCT_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_recolor_opa(ui->LightCT_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->LightCT_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for LightCT_imgbtn_1, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->LightCT_imgbtn_1, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->LightCT_imgbtn_1, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes LightCT_btn_1
    ui->LightCT_btn_1 = lv_btn_create(ui->LightCT);
    ui->LightCT_btn_1_label = lv_label_create(ui->LightCT_btn_1);
    lv_label_set_text(ui->LightCT_btn_1_label, "<  色温灯");
    lv_label_set_long_mode(ui->LightCT_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->LightCT_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->LightCT_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->LightCT_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->LightCT_btn_1, 11, 7);
    lv_obj_set_size(ui->LightCT_btn_1, 156, 50);

    //Write style for LightCT_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->LightCT_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->LightCT_btn_1, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->LightCT_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->LightCT_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->LightCT_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->LightCT_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->LightCT_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->LightCT_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes LightCT_on_off_2_img
    ui->LightCT_on_off_2_img = lv_imgbtn_create(ui->LightCT);
    lv_obj_add_flag(ui->LightCT_on_off_2_img, LV_OBJ_FLAG_CHECKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_imgbtn_set_src(ui->LightCT_on_off_2_img, LV_IMGBTN_STATE_RELEASED, NULL, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\onoff_off.png", NULL);
    lv_imgbtn_set_src(ui->LightCT_on_off_2_img, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\onoff_on.png", NULL);
#else
    lv_imgbtn_set_src(ui->LightCT_on_off_2_img, LV_IMGBTN_STATE_RELEASED, NULL, "S:/sdfile/EXT_RESERVED/uipackres/ui/onoff_off.png", NULL);
    lv_imgbtn_set_src(ui->LightCT_on_off_2_img, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, "S:/sdfile/EXT_RESERVED/uipackres/ui/onoff_on.png", NULL);
#endif
    ui->LightCT_on_off_2_img_label = lv_label_create(ui->LightCT_on_off_2_img);
    lv_label_set_text(ui->LightCT_on_off_2_img_label, "");
    lv_label_set_long_mode(ui->LightCT_on_off_2_img_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->LightCT_on_off_2_img_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->LightCT_on_off_2_img, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->LightCT_on_off_2_img, 20, 101);
    lv_obj_set_size(ui->LightCT_on_off_2_img, 48, 48);

    //Write style for LightCT_on_off_2_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->LightCT_on_off_2_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->LightCT_on_off_2_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->LightCT_on_off_2_img, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->LightCT_on_off_2_img, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->LightCT_on_off_2_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->LightCT_on_off_2_img, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->LightCT_on_off_2_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for LightCT_on_off_2_img, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->LightCT_on_off_2_img, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->LightCT_on_off_2_img, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->LightCT_on_off_2_img, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->LightCT_on_off_2_img, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->LightCT_on_off_2_img, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->LightCT_on_off_2_img, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for LightCT_on_off_2_img, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->LightCT_on_off_2_img, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->LightCT_on_off_2_img, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->LightCT_on_off_2_img, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->LightCT_on_off_2_img, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->LightCT_on_off_2_img, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->LightCT_on_off_2_img, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for LightCT_on_off_2_img, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->LightCT_on_off_2_img, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->LightCT_on_off_2_img, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //The custom code of LightCT.


    //Update current screen layout.
    lv_obj_update_layout(ui->LightCT);

}
