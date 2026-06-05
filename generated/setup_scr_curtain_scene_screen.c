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



void setup_scr_curtain_scene_screen(lv_ui *ui)
{
    //Write codes curtain_scene_screen
    ui->curtain_scene_screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->curtain_scene_screen, 720, 720);
    lv_obj_set_scrollbar_mode(ui->curtain_scene_screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for curtain_scene_screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->curtain_scene_screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->curtain_scene_screen, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->curtain_scene_screen, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes curtain_scene_screen_tabview_1
    ui->curtain_scene_screen_tabview_1 = lv_tabview_create(ui->curtain_scene_screen, LV_DIR_TOP, 85);
    lv_obj_set_pos(ui->curtain_scene_screen_tabview_1, -1, -1);
    lv_obj_set_size(ui->curtain_scene_screen_tabview_1, 720, 720);
    lv_obj_set_scrollbar_mode(ui->curtain_scene_screen_tabview_1, LV_SCROLLBAR_MODE_ON);

    //Write style for curtain_scene_screen_tabview_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->curtain_scene_screen_tabview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->curtain_scene_screen_tabview_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->curtain_scene_screen_tabview_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->curtain_scene_screen_tabview_1, lv_color_hex(0x4d4d4d), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->curtain_scene_screen_tabview_1, &lv_font_ZiTiQuanWeiJunHeiW22_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->curtain_scene_screen_tabview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->curtain_scene_screen_tabview_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->curtain_scene_screen_tabview_1, 16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->curtain_scene_screen_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->curtain_scene_screen_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->curtain_scene_screen_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_curtain_scene_screen_tabview_1_extra_btnm_main_default
    static lv_style_t style_curtain_scene_screen_tabview_1_extra_btnm_main_default;
    ui_init_style(&style_curtain_scene_screen_tabview_1_extra_btnm_main_default);

    lv_style_set_bg_opa(&style_curtain_scene_screen_tabview_1_extra_btnm_main_default, 255);
    lv_style_set_bg_color(&style_curtain_scene_screen_tabview_1_extra_btnm_main_default, lv_color_hex(0x201b1b));
    lv_style_set_bg_grad_dir(&style_curtain_scene_screen_tabview_1_extra_btnm_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_curtain_scene_screen_tabview_1_extra_btnm_main_default, 0);
    lv_style_set_radius(&style_curtain_scene_screen_tabview_1_extra_btnm_main_default, 0);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->curtain_scene_screen_tabview_1), &style_curtain_scene_screen_tabview_1_extra_btnm_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_curtain_scene_screen_tabview_1_extra_btnm_items_default
    static lv_style_t style_curtain_scene_screen_tabview_1_extra_btnm_items_default;
    ui_init_style(&style_curtain_scene_screen_tabview_1_extra_btnm_items_default);

    lv_style_set_text_color(&style_curtain_scene_screen_tabview_1_extra_btnm_items_default, lv_color_hex(0x4d4d4d));
    lv_style_set_text_font(&style_curtain_scene_screen_tabview_1_extra_btnm_items_default, &lv_font_ZiTiQuanWeiJunHeiW22_12);
    lv_style_set_text_opa(&style_curtain_scene_screen_tabview_1_extra_btnm_items_default, 255);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->curtain_scene_screen_tabview_1), &style_curtain_scene_screen_tabview_1_extra_btnm_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_curtain_scene_screen_tabview_1_extra_btnm_items_checked
    static lv_style_t style_curtain_scene_screen_tabview_1_extra_btnm_items_checked;
    ui_init_style(&style_curtain_scene_screen_tabview_1_extra_btnm_items_checked);

    lv_style_set_text_color(&style_curtain_scene_screen_tabview_1_extra_btnm_items_checked, lv_color_hex(0x2195f6));
    lv_style_set_text_font(&style_curtain_scene_screen_tabview_1_extra_btnm_items_checked, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_curtain_scene_screen_tabview_1_extra_btnm_items_checked, 255);
    lv_style_set_border_width(&style_curtain_scene_screen_tabview_1_extra_btnm_items_checked, 0);
    lv_style_set_radius(&style_curtain_scene_screen_tabview_1_extra_btnm_items_checked, 0);
    lv_style_set_bg_opa(&style_curtain_scene_screen_tabview_1_extra_btnm_items_checked, 255);
    lv_style_set_bg_color(&style_curtain_scene_screen_tabview_1_extra_btnm_items_checked, lv_color_hex(0x201b1b));
    lv_style_set_bg_grad_dir(&style_curtain_scene_screen_tabview_1_extra_btnm_items_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->curtain_scene_screen_tabview_1), &style_curtain_scene_screen_tabview_1_extra_btnm_items_checked, LV_PART_ITEMS|LV_STATE_CHECKED);

    //Write codes
    ui->curtain_scene_screen_tabview_1_tab_1 = lv_tabview_add_tab(ui->curtain_scene_screen_tabview_1,"");
    lv_obj_t * curtain_scene_screen_tabview_1_tab_1_label = lv_label_create(ui->curtain_scene_screen_tabview_1_tab_1);
    lv_label_set_text(curtain_scene_screen_tabview_1_tab_1_label, "");

    //Write codes curtain_scene_screen_btn_10
    ui->curtain_scene_screen_btn_10 = lv_btn_create(ui->curtain_scene_screen_tabview_1_tab_1);
    lv_obj_add_flag(ui->curtain_scene_screen_btn_10, LV_OBJ_FLAG_CHECKABLE);
    ui->curtain_scene_screen_btn_10_label = lv_label_create(ui->curtain_scene_screen_btn_10);
    lv_label_set_text(ui->curtain_scene_screen_btn_10_label, "按键1");
    lv_label_set_long_mode(ui->curtain_scene_screen_btn_10_label, LV_LABEL_LONG_CLIP);
    lv_obj_align(ui->curtain_scene_screen_btn_10_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->curtain_scene_screen_btn_10, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->curtain_scene_screen_btn_10_label, LV_PCT(100));
    lv_obj_set_pos(ui->curtain_scene_screen_btn_10, 14, 17);
    lv_obj_set_size(ui->curtain_scene_screen_btn_10, 300, 150);

    //Write style for curtain_scene_screen_btn_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->curtain_scene_screen_btn_10, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->curtain_scene_screen_btn_10, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->curtain_scene_screen_btn_10, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->curtain_scene_screen_btn_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->curtain_scene_screen_btn_10, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->curtain_scene_screen_btn_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->curtain_scene_screen_btn_10, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->curtain_scene_screen_btn_10, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->curtain_scene_screen_btn_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->curtain_scene_screen_btn_10, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes curtain_scene_screen_btn_9
    ui->curtain_scene_screen_btn_9 = lv_btn_create(ui->curtain_scene_screen_tabview_1_tab_1);
    lv_obj_add_flag(ui->curtain_scene_screen_btn_9, LV_OBJ_FLAG_CHECKABLE);
    ui->curtain_scene_screen_btn_9_label = lv_label_create(ui->curtain_scene_screen_btn_9);
    lv_label_set_text(ui->curtain_scene_screen_btn_9_label, "按键1");
    lv_label_set_long_mode(ui->curtain_scene_screen_btn_9_label, LV_LABEL_LONG_CLIP);
    lv_obj_align(ui->curtain_scene_screen_btn_9_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->curtain_scene_screen_btn_9, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->curtain_scene_screen_btn_9_label, LV_PCT(100));
    lv_obj_set_pos(ui->curtain_scene_screen_btn_9, 376, 17);
    lv_obj_set_size(ui->curtain_scene_screen_btn_9, 300, 150);

    //Write style for curtain_scene_screen_btn_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->curtain_scene_screen_btn_9, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->curtain_scene_screen_btn_9, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->curtain_scene_screen_btn_9, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->curtain_scene_screen_btn_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->curtain_scene_screen_btn_9, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->curtain_scene_screen_btn_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->curtain_scene_screen_btn_9, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->curtain_scene_screen_btn_9, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->curtain_scene_screen_btn_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->curtain_scene_screen_btn_9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes curtain_scene_screen_btn_8
    ui->curtain_scene_screen_btn_8 = lv_btn_create(ui->curtain_scene_screen_tabview_1_tab_1);
    lv_obj_add_flag(ui->curtain_scene_screen_btn_8, LV_OBJ_FLAG_CHECKABLE);
    ui->curtain_scene_screen_btn_8_label = lv_label_create(ui->curtain_scene_screen_btn_8);
    lv_label_set_text(ui->curtain_scene_screen_btn_8_label, "按键1");
    lv_label_set_long_mode(ui->curtain_scene_screen_btn_8_label, LV_LABEL_LONG_CLIP);
    lv_obj_align(ui->curtain_scene_screen_btn_8_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->curtain_scene_screen_btn_8, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->curtain_scene_screen_btn_8_label, LV_PCT(100));
    lv_obj_set_pos(ui->curtain_scene_screen_btn_8, 376, 211);
    lv_obj_set_size(ui->curtain_scene_screen_btn_8, 300, 150);

    //Write style for curtain_scene_screen_btn_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->curtain_scene_screen_btn_8, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->curtain_scene_screen_btn_8, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->curtain_scene_screen_btn_8, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->curtain_scene_screen_btn_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->curtain_scene_screen_btn_8, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->curtain_scene_screen_btn_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->curtain_scene_screen_btn_8, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->curtain_scene_screen_btn_8, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->curtain_scene_screen_btn_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->curtain_scene_screen_btn_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes curtain_scene_screen_btn_7
    ui->curtain_scene_screen_btn_7 = lv_btn_create(ui->curtain_scene_screen_tabview_1_tab_1);
    lv_obj_add_flag(ui->curtain_scene_screen_btn_7, LV_OBJ_FLAG_CHECKABLE);
    ui->curtain_scene_screen_btn_7_label = lv_label_create(ui->curtain_scene_screen_btn_7);
    lv_label_set_text(ui->curtain_scene_screen_btn_7_label, "按键1");
    lv_label_set_long_mode(ui->curtain_scene_screen_btn_7_label, LV_LABEL_LONG_CLIP);
    lv_obj_align(ui->curtain_scene_screen_btn_7_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->curtain_scene_screen_btn_7, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->curtain_scene_screen_btn_7_label, LV_PCT(100));
    lv_obj_set_pos(ui->curtain_scene_screen_btn_7, 14, 212);
    lv_obj_set_size(ui->curtain_scene_screen_btn_7, 300, 150);

    //Write style for curtain_scene_screen_btn_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->curtain_scene_screen_btn_7, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->curtain_scene_screen_btn_7, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->curtain_scene_screen_btn_7, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->curtain_scene_screen_btn_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->curtain_scene_screen_btn_7, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->curtain_scene_screen_btn_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->curtain_scene_screen_btn_7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->curtain_scene_screen_btn_7, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->curtain_scene_screen_btn_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->curtain_scene_screen_btn_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes curtain_scene_screen_btn_6
    ui->curtain_scene_screen_btn_6 = lv_btn_create(ui->curtain_scene_screen_tabview_1_tab_1);
    lv_obj_add_flag(ui->curtain_scene_screen_btn_6, LV_OBJ_FLAG_CHECKABLE);
    ui->curtain_scene_screen_btn_6_label = lv_label_create(ui->curtain_scene_screen_btn_6);
    lv_label_set_text(ui->curtain_scene_screen_btn_6_label, "按键1");
    lv_label_set_long_mode(ui->curtain_scene_screen_btn_6_label, LV_LABEL_LONG_CLIP);
    lv_obj_align(ui->curtain_scene_screen_btn_6_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->curtain_scene_screen_btn_6, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->curtain_scene_screen_btn_6_label, LV_PCT(100));
    lv_obj_set_pos(ui->curtain_scene_screen_btn_6, 14, 602);
    lv_obj_set_size(ui->curtain_scene_screen_btn_6, 300, 150);

    //Write style for curtain_scene_screen_btn_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->curtain_scene_screen_btn_6, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->curtain_scene_screen_btn_6, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->curtain_scene_screen_btn_6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->curtain_scene_screen_btn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->curtain_scene_screen_btn_6, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->curtain_scene_screen_btn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->curtain_scene_screen_btn_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->curtain_scene_screen_btn_6, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->curtain_scene_screen_btn_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->curtain_scene_screen_btn_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes curtain_scene_screen_btn_5
    ui->curtain_scene_screen_btn_5 = lv_btn_create(ui->curtain_scene_screen_tabview_1_tab_1);
    lv_obj_add_flag(ui->curtain_scene_screen_btn_5, LV_OBJ_FLAG_CHECKABLE);
    ui->curtain_scene_screen_btn_5_label = lv_label_create(ui->curtain_scene_screen_btn_5);
    lv_label_set_text(ui->curtain_scene_screen_btn_5_label, "按键1");
    lv_label_set_long_mode(ui->curtain_scene_screen_btn_5_label, LV_LABEL_LONG_CLIP);
    lv_obj_align(ui->curtain_scene_screen_btn_5_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->curtain_scene_screen_btn_5, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->curtain_scene_screen_btn_5_label, LV_PCT(100));
    lv_obj_set_pos(ui->curtain_scene_screen_btn_5, 14, 407);
    lv_obj_set_size(ui->curtain_scene_screen_btn_5, 300, 150);

    //Write style for curtain_scene_screen_btn_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->curtain_scene_screen_btn_5, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->curtain_scene_screen_btn_5, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->curtain_scene_screen_btn_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->curtain_scene_screen_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->curtain_scene_screen_btn_5, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->curtain_scene_screen_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->curtain_scene_screen_btn_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->curtain_scene_screen_btn_5, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->curtain_scene_screen_btn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->curtain_scene_screen_btn_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes curtain_scene_screen_btn_4
    ui->curtain_scene_screen_btn_4 = lv_btn_create(ui->curtain_scene_screen_tabview_1_tab_1);
    lv_obj_add_flag(ui->curtain_scene_screen_btn_4, LV_OBJ_FLAG_CHECKABLE);
    ui->curtain_scene_screen_btn_4_label = lv_label_create(ui->curtain_scene_screen_btn_4);
    lv_label_set_text(ui->curtain_scene_screen_btn_4_label, "按键1");
    lv_label_set_long_mode(ui->curtain_scene_screen_btn_4_label, LV_LABEL_LONG_CLIP);
    lv_obj_align(ui->curtain_scene_screen_btn_4_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->curtain_scene_screen_btn_4, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->curtain_scene_screen_btn_4_label, LV_PCT(100));
    lv_obj_set_pos(ui->curtain_scene_screen_btn_4, 376, 599);
    lv_obj_set_size(ui->curtain_scene_screen_btn_4, 300, 150);

    //Write style for curtain_scene_screen_btn_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->curtain_scene_screen_btn_4, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->curtain_scene_screen_btn_4, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->curtain_scene_screen_btn_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->curtain_scene_screen_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->curtain_scene_screen_btn_4, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->curtain_scene_screen_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->curtain_scene_screen_btn_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->curtain_scene_screen_btn_4, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->curtain_scene_screen_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->curtain_scene_screen_btn_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes curtain_scene_screen_btn_3
    ui->curtain_scene_screen_btn_3 = lv_btn_create(ui->curtain_scene_screen_tabview_1_tab_1);
    lv_obj_add_flag(ui->curtain_scene_screen_btn_3, LV_OBJ_FLAG_CHECKABLE);
    ui->curtain_scene_screen_btn_3_label = lv_label_create(ui->curtain_scene_screen_btn_3);
    lv_label_set_text(ui->curtain_scene_screen_btn_3_label, "按键1");
    lv_label_set_long_mode(ui->curtain_scene_screen_btn_3_label, LV_LABEL_LONG_CLIP);
    lv_obj_align(ui->curtain_scene_screen_btn_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->curtain_scene_screen_btn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->curtain_scene_screen_btn_3_label, LV_PCT(100));
    lv_obj_set_pos(ui->curtain_scene_screen_btn_3, 376, 405);
    lv_obj_set_size(ui->curtain_scene_screen_btn_3, 300, 150);

    //Write style for curtain_scene_screen_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->curtain_scene_screen_btn_3, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->curtain_scene_screen_btn_3, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->curtain_scene_screen_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->curtain_scene_screen_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->curtain_scene_screen_btn_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->curtain_scene_screen_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->curtain_scene_screen_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->curtain_scene_screen_btn_3, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->curtain_scene_screen_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->curtain_scene_screen_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes curtain_scene_screen_btn_2
    ui->curtain_scene_screen_btn_2 = lv_btn_create(ui->curtain_scene_screen_tabview_1_tab_1);
    lv_obj_add_flag(ui->curtain_scene_screen_btn_2, LV_OBJ_FLAG_CHECKABLE);
    ui->curtain_scene_screen_btn_2_label = lv_label_create(ui->curtain_scene_screen_btn_2);
    lv_label_set_text(ui->curtain_scene_screen_btn_2_label, "按键1");
    lv_label_set_long_mode(ui->curtain_scene_screen_btn_2_label, LV_LABEL_LONG_CLIP);
    lv_obj_align(ui->curtain_scene_screen_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->curtain_scene_screen_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->curtain_scene_screen_btn_2_label, LV_PCT(100));
    lv_obj_set_pos(ui->curtain_scene_screen_btn_2, 14, 797);
    lv_obj_set_size(ui->curtain_scene_screen_btn_2, 300, 150);

    //Write style for curtain_scene_screen_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->curtain_scene_screen_btn_2, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->curtain_scene_screen_btn_2, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->curtain_scene_screen_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->curtain_scene_screen_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->curtain_scene_screen_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->curtain_scene_screen_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->curtain_scene_screen_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->curtain_scene_screen_btn_2, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->curtain_scene_screen_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->curtain_scene_screen_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes curtain_scene_screen_btn_1
    ui->curtain_scene_screen_btn_1 = lv_btn_create(ui->curtain_scene_screen_tabview_1_tab_1);
    lv_obj_add_flag(ui->curtain_scene_screen_btn_1, LV_OBJ_FLAG_CHECKABLE);
    ui->curtain_scene_screen_btn_1_label = lv_label_create(ui->curtain_scene_screen_btn_1);
    lv_label_set_text(ui->curtain_scene_screen_btn_1_label, "按键1");
    lv_label_set_long_mode(ui->curtain_scene_screen_btn_1_label, LV_LABEL_LONG_CLIP);
    lv_obj_align(ui->curtain_scene_screen_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->curtain_scene_screen_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->curtain_scene_screen_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->curtain_scene_screen_btn_1, 376, 793);
    lv_obj_set_size(ui->curtain_scene_screen_btn_1, 300, 150);

    //Write style for curtain_scene_screen_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->curtain_scene_screen_btn_1, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->curtain_scene_screen_btn_1, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->curtain_scene_screen_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->curtain_scene_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->curtain_scene_screen_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->curtain_scene_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->curtain_scene_screen_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->curtain_scene_screen_btn_1, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->curtain_scene_screen_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->curtain_scene_screen_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes curtain_scene_screen_label_1
    ui->curtain_scene_screen_label_1 = lv_label_create(ui->curtain_scene_screen);
    lv_label_set_text(ui->curtain_scene_screen_label_1, "窗帘情景");
    lv_label_set_long_mode(ui->curtain_scene_screen_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->curtain_scene_screen_label_1, 20, 19);
    lv_obj_set_size(ui->curtain_scene_screen_label_1, 150, 40);

    //Write style for curtain_scene_screen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->curtain_scene_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->curtain_scene_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->curtain_scene_screen_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->curtain_scene_screen_label_1, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->curtain_scene_screen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->curtain_scene_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->curtain_scene_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->curtain_scene_screen_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->curtain_scene_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->curtain_scene_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->curtain_scene_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->curtain_scene_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->curtain_scene_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->curtain_scene_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of curtain_scene_screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->curtain_scene_screen);

    //Init events for screen.
    events_init_curtain_scene_screen(ui);
}
