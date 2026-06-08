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



void setup_scr_screen_1(lv_ui *ui)
{
    //Write codes screen_1
    ui->screen_1 = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_1, 720, 720);
    lv_obj_set_scrollbar_mode(ui->screen_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_1_tabview_1
    ui->screen_1_tabview_1 = lv_tabview_create(ui->screen_1, LV_DIR_TOP, 70);
    lv_obj_set_pos(ui->screen_1_tabview_1, 0, 0);
    lv_obj_set_size(ui->screen_1_tabview_1, 720, 720);
    lv_obj_set_scrollbar_mode(ui->screen_1_tabview_1, LV_SCROLLBAR_MODE_ON);

    //Write style for screen_1_tabview_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_1_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_1_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_1_tabview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_1_tabview_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_1_tabview_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_1_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_1_tabview_1, lv_color_hex(0x4d4d4d), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_1_tabview_1, &lv_font_ZiTiQuanWeiJunHeiW22_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_1_tabview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_1_tabview_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_1_tabview_1, 16, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_1_tabview_1_extra_btnm_main_default
    static lv_style_t style_screen_1_tabview_1_extra_btnm_main_default;
    ui_init_style(&style_screen_1_tabview_1_extra_btnm_main_default);

    lv_style_set_bg_opa(&style_screen_1_tabview_1_extra_btnm_main_default, 255);
    lv_style_set_bg_color(&style_screen_1_tabview_1_extra_btnm_main_default, lv_color_hex(0x4f3f3f));
    lv_style_set_bg_grad_dir(&style_screen_1_tabview_1_extra_btnm_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_screen_1_tabview_1_extra_btnm_main_default, 0);
    lv_style_set_radius(&style_screen_1_tabview_1_extra_btnm_main_default, 0);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->screen_1_tabview_1), &style_screen_1_tabview_1_extra_btnm_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_1_tabview_1_extra_btnm_items_default
    static lv_style_t style_screen_1_tabview_1_extra_btnm_items_default;
    ui_init_style(&style_screen_1_tabview_1_extra_btnm_items_default);

    lv_style_set_text_color(&style_screen_1_tabview_1_extra_btnm_items_default, lv_color_hex(0x4d4d4d));
    lv_style_set_text_font(&style_screen_1_tabview_1_extra_btnm_items_default, &lv_font_ZiTiQuanWeiJunHeiW22_12);
    lv_style_set_text_opa(&style_screen_1_tabview_1_extra_btnm_items_default, 255);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->screen_1_tabview_1), &style_screen_1_tabview_1_extra_btnm_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_screen_1_tabview_1_extra_btnm_items_checked
    static lv_style_t style_screen_1_tabview_1_extra_btnm_items_checked;
    ui_init_style(&style_screen_1_tabview_1_extra_btnm_items_checked);

    lv_style_set_text_color(&style_screen_1_tabview_1_extra_btnm_items_checked, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_screen_1_tabview_1_extra_btnm_items_checked, &lv_font_ZiTiQuanWeiJunHeiW22_20);
    lv_style_set_text_opa(&style_screen_1_tabview_1_extra_btnm_items_checked, 255);
    lv_style_set_border_width(&style_screen_1_tabview_1_extra_btnm_items_checked, 0);
    lv_style_set_radius(&style_screen_1_tabview_1_extra_btnm_items_checked, 0);
    lv_style_set_bg_opa(&style_screen_1_tabview_1_extra_btnm_items_checked, 255);
    lv_style_set_bg_color(&style_screen_1_tabview_1_extra_btnm_items_checked, lv_color_hex(0x0f0f12));
    lv_style_set_bg_grad_dir(&style_screen_1_tabview_1_extra_btnm_items_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->screen_1_tabview_1), &style_screen_1_tabview_1_extra_btnm_items_checked, LV_PART_ITEMS|LV_STATE_CHECKED);

    //Write codes
    ui->screen_1_tabview_1_tab_1 = lv_tabview_add_tab(ui->screen_1_tabview_1,"");
    lv_obj_t * screen_1_tabview_1_tab_1_label = lv_label_create(ui->screen_1_tabview_1_tab_1);
    lv_label_set_text(screen_1_tabview_1_tab_1_label, "");

    //Write codes screen_1_cont_1
    ui->screen_1_cont_1 = lv_obj_create(ui->screen_1);
    lv_obj_set_pos(ui->screen_1_cont_1, 0, 72);
    lv_obj_set_size(ui->screen_1_cont_1, 720, 645);
    lv_obj_set_scrollbar_mode(ui->screen_1_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_1_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_1_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_1_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_1_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_1_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_1_cont_1, 133, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_1_cont_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_1_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_1_btn_1
    ui->screen_1_btn_1 = lv_btn_create(ui->screen_1);
    ui->screen_1_btn_1_label = lv_label_create(ui->screen_1_btn_1);
    lv_label_set_text(ui->screen_1_btn_1_label, "<  卷帘");
    lv_label_set_long_mode(ui->screen_1_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_1_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_1_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_1_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_1_btn_1, 11, 5);
    lv_obj_set_size(ui->screen_1_btn_1, 156, 50);

    //Write style for screen_1_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_1_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_1_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_1_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_1_btn_1, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_1_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_1_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_1_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_1_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_1_FabCurtianOpen
    ui->screen_1_FabCurtianOpen = lv_img_create(ui->screen_1);
    lv_obj_add_flag(ui->screen_1_FabCurtianOpen, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_1_FabCurtianOpen, &_RollBlindUp_alpha_94x95);
    lv_img_set_pivot(ui->screen_1_FabCurtianOpen, 50,50);
    lv_img_set_angle(ui->screen_1_FabCurtianOpen, 0);
    lv_obj_set_pos(ui->screen_1_FabCurtianOpen, 62, 568);
    lv_obj_set_size(ui->screen_1_FabCurtianOpen, 94, 95);

    //Write style for screen_1_FabCurtianOpen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_1_FabCurtianOpen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_1_FabCurtianOpen, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_1_FabCurtianOpen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_1_FabCurtianOpen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_1_FabCurtianClose
    ui->screen_1_FabCurtianClose = lv_img_create(ui->screen_1);
    lv_obj_add_flag(ui->screen_1_FabCurtianClose, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_1_FabCurtianClose, &_RollBlindDown_alpha_94x95);
    lv_img_set_pivot(ui->screen_1_FabCurtianClose, 50,50);
    lv_img_set_angle(ui->screen_1_FabCurtianClose, 0);
    lv_obj_set_pos(ui->screen_1_FabCurtianClose, 560, 562);
    lv_obj_set_size(ui->screen_1_FabCurtianClose, 94, 95);

    //Write style for screen_1_FabCurtianClose, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_1_FabCurtianClose, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_1_FabCurtianClose, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_1_FabCurtianClose, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_1_FabCurtianClose, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_1_cont_2
    ui->screen_1_cont_2 = lv_obj_create(ui->screen_1);
    lv_obj_set_pos(ui->screen_1_cont_2, 127, 181);
    lv_obj_set_size(ui->screen_1_cont_2, 435, 353);
    lv_obj_set_scrollbar_mode(ui->screen_1_cont_2, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_1_cont_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_1_cont_2, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_1_cont_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_1_cont_2, lv_color_hex(0x2c2424), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_1_cont_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_1_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_1_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_1_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_1_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_1_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_1_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_1_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_1_FabCurtianPause
    ui->screen_1_FabCurtianPause = lv_img_create(ui->screen_1);
    lv_obj_add_flag(ui->screen_1_FabCurtianPause, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_1_FabCurtianPause, &_FabCurtianPause_alpha_109x110);
    lv_img_set_pivot(ui->screen_1_FabCurtianPause, 50,50);
    lv_img_set_angle(ui->screen_1_FabCurtianPause, 0);
    lv_obj_set_pos(ui->screen_1_FabCurtianPause, 283, 557);
    lv_obj_set_size(ui->screen_1_FabCurtianPause, 109, 110);

    //Write style for screen_1_FabCurtianPause, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_1_FabCurtianPause, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_1_FabCurtianPause, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_1_FabCurtianPause, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_1_FabCurtianPause, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_1_FabCurtianBg1
    ui->screen_1_FabCurtianBg1 = lv_img_create(ui->screen_1);
    lv_obj_add_flag(ui->screen_1_FabCurtianBg1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_1_FabCurtianBg1, &_FabCurtianBg1_alpha_62x60);
    lv_img_set_pivot(ui->screen_1_FabCurtianBg1, 50,50);
    lv_img_set_angle(ui->screen_1_FabCurtianBg1, 0);
    lv_obj_set_pos(ui->screen_1_FabCurtianBg1, 232, 255);
    lv_obj_set_size(ui->screen_1_FabCurtianBg1, 62, 60);

    //Write style for screen_1_FabCurtianBg1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_1_FabCurtianBg1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_1_FabCurtianBg1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_1_FabCurtianBg1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_1_FabCurtianBg1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_1_FabCurtianBg3
    ui->screen_1_FabCurtianBg3 = lv_img_create(ui->screen_1);
    lv_obj_add_flag(ui->screen_1_FabCurtianBg3, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_1_FabCurtianBg3, &_FabCurtianBg3_alpha_42x14);
    lv_img_set_pivot(ui->screen_1_FabCurtianBg3, 50,50);
    lv_img_set_angle(ui->screen_1_FabCurtianBg3, 0);
    lv_obj_set_pos(ui->screen_1_FabCurtianBg3, 252, 384);
    lv_obj_set_size(ui->screen_1_FabCurtianBg3, 42, 14);

    //Write style for screen_1_FabCurtianBg3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_1_FabCurtianBg3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_1_FabCurtianBg3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_1_FabCurtianBg3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_1_FabCurtianBg3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_1_FabCurtianBg2
    ui->screen_1_FabCurtianBg2 = lv_img_create(ui->screen_1);
    lv_obj_add_flag(ui->screen_1_FabCurtianBg2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_1_FabCurtianBg2, &_FabCurtianBg2_alpha_34x73);
    lv_img_set_pivot(ui->screen_1_FabCurtianBg2, 50,50);
    lv_img_set_angle(ui->screen_1_FabCurtianBg2, 0);
    lv_obj_set_pos(ui->screen_1_FabCurtianBg2, 415, 272);
    lv_obj_set_size(ui->screen_1_FabCurtianBg2, 34, 73);

    //Write style for screen_1_FabCurtianBg2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_1_FabCurtianBg2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_1_FabCurtianBg2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_1_FabCurtianBg2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_1_FabCurtianBg2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_1_FabCurtianLeft
    ui->screen_1_FabCurtianLeft = lv_img_create(ui->screen_1);
    lv_obj_add_flag(ui->screen_1_FabCurtianLeft, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_1_FabCurtianLeft, &_RollBlindCloth_alpha_435x353);
    lv_img_set_pivot(ui->screen_1_FabCurtianLeft, 50,50);
    lv_img_set_angle(ui->screen_1_FabCurtianLeft, 0);
    lv_obj_set_pos(ui->screen_1_FabCurtianLeft, 127, 181);
    lv_obj_set_size(ui->screen_1_FabCurtianLeft, 435, 353);

    //Write style for screen_1_FabCurtianLeft, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_1_FabCurtianLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_1_FabCurtianLeft, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_1_FabCurtianLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_1_FabCurtianLeft, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_1_FabCurtianPull1
    ui->screen_1_FabCurtianPull1 = lv_img_create(ui->screen_1);
    lv_obj_add_flag(ui->screen_1_FabCurtianPull1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_1_FabCurtianPull1, &_CurtainPull_alpha_39x39);
    lv_img_set_pivot(ui->screen_1_FabCurtianPull1, 50,50);
    lv_img_set_angle(ui->screen_1_FabCurtianPull1, 0);
    lv_obj_set_pos(ui->screen_1_FabCurtianPull1, 316, 481);
    lv_obj_set_size(ui->screen_1_FabCurtianPull1, 39, 39);

    //Write style for screen_1_FabCurtianPull1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_1_FabCurtianPull1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_1_FabCurtianPull1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_1_FabCurtianPull1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_1_FabCurtianPull1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_1_RollBlindPole
    ui->screen_1_RollBlindPole = lv_img_create(ui->screen_1);
    lv_obj_add_flag(ui->screen_1_RollBlindPole, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_1_RollBlindPole, &_RollBlindPole_alpha_462x26);
    lv_img_set_pivot(ui->screen_1_RollBlindPole, 50,50);
    lv_img_set_angle(ui->screen_1_RollBlindPole, 0);
    lv_obj_set_pos(ui->screen_1_RollBlindPole, 112, 178);
    lv_obj_set_size(ui->screen_1_RollBlindPole, 462, 26);

    //Write style for screen_1_RollBlindPole, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_1_RollBlindPole, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_1_RollBlindPole, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_1_RollBlindPole, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_1_RollBlindPole, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_1.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_1);

}
