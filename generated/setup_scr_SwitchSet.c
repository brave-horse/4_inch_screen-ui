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



void setup_scr_SwitchSet(lv_ui *ui)
{
    //Write codes SwitchSet
    ui->SwitchSet = lv_obj_create(NULL);
    lv_obj_set_size(ui->SwitchSet, 720, 720);
    lv_obj_set_scrollbar_mode(ui->SwitchSet, LV_SCROLLBAR_MODE_OFF);

    //Write style for SwitchSet, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->SwitchSet, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SwitchSet, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SwitchSet, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SwitchSet_tabview_1
    ui->SwitchSet_tabview_1 = lv_tabview_create(ui->SwitchSet, LV_DIR_TOP, 85);
    lv_obj_set_pos(ui->SwitchSet_tabview_1, 0, 0);
    lv_obj_set_size(ui->SwitchSet_tabview_1, 720, 720);
    lv_obj_set_scrollbar_mode(ui->SwitchSet_tabview_1, LV_SCROLLBAR_MODE_ON);

    //Write style for SwitchSet_tabview_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->SwitchSet_tabview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SwitchSet_tabview_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SwitchSet_tabview_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SwitchSet_tabview_1, lv_color_hex(0x4d4d4d), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SwitchSet_tabview_1, &lv_font_ZiTiQuanWeiJunHeiW22_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SwitchSet_tabview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->SwitchSet_tabview_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->SwitchSet_tabview_1, 16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->SwitchSet_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SwitchSet_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SwitchSet_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_SwitchSet_tabview_1_extra_btnm_main_default
    static lv_style_t style_SwitchSet_tabview_1_extra_btnm_main_default;
    ui_init_style(&style_SwitchSet_tabview_1_extra_btnm_main_default);

    lv_style_set_bg_opa(&style_SwitchSet_tabview_1_extra_btnm_main_default, 255);
    lv_style_set_bg_color(&style_SwitchSet_tabview_1_extra_btnm_main_default, lv_color_hex(0x243241));
    lv_style_set_bg_grad_dir(&style_SwitchSet_tabview_1_extra_btnm_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_SwitchSet_tabview_1_extra_btnm_main_default, 0);
    lv_style_set_radius(&style_SwitchSet_tabview_1_extra_btnm_main_default, 0);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->SwitchSet_tabview_1), &style_SwitchSet_tabview_1_extra_btnm_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_SwitchSet_tabview_1_extra_btnm_items_default
    static lv_style_t style_SwitchSet_tabview_1_extra_btnm_items_default;
    ui_init_style(&style_SwitchSet_tabview_1_extra_btnm_items_default);

    lv_style_set_text_color(&style_SwitchSet_tabview_1_extra_btnm_items_default, lv_color_hex(0x4d4d4d));
    lv_style_set_text_font(&style_SwitchSet_tabview_1_extra_btnm_items_default, &lv_font_ZiTiQuanWeiJunHeiW22_12);
    lv_style_set_text_opa(&style_SwitchSet_tabview_1_extra_btnm_items_default, 255);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->SwitchSet_tabview_1), &style_SwitchSet_tabview_1_extra_btnm_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_SwitchSet_tabview_1_extra_btnm_items_checked
    static lv_style_t style_SwitchSet_tabview_1_extra_btnm_items_checked;
    ui_init_style(&style_SwitchSet_tabview_1_extra_btnm_items_checked);

    lv_style_set_text_color(&style_SwitchSet_tabview_1_extra_btnm_items_checked, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_SwitchSet_tabview_1_extra_btnm_items_checked, &lv_font_ZiTiQuanWeiJunHeiW22_20);
    lv_style_set_text_opa(&style_SwitchSet_tabview_1_extra_btnm_items_checked, 255);
    lv_style_set_border_width(&style_SwitchSet_tabview_1_extra_btnm_items_checked, 0);
    lv_style_set_radius(&style_SwitchSet_tabview_1_extra_btnm_items_checked, 0);
    lv_style_set_bg_opa(&style_SwitchSet_tabview_1_extra_btnm_items_checked, 255);
    lv_style_set_bg_color(&style_SwitchSet_tabview_1_extra_btnm_items_checked, lv_color_hex(0x0f0f12));
    lv_style_set_bg_grad_dir(&style_SwitchSet_tabview_1_extra_btnm_items_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->SwitchSet_tabview_1), &style_SwitchSet_tabview_1_extra_btnm_items_checked, LV_PART_ITEMS|LV_STATE_CHECKED);

    //Write codes
    ui->SwitchSet_tabview_1_tab_1 = lv_tabview_add_tab(ui->SwitchSet_tabview_1,"");
    lv_obj_t * SwitchSet_tabview_1_tab_1_label = lv_label_create(ui->SwitchSet_tabview_1_tab_1);
    lv_label_set_text(SwitchSet_tabview_1_tab_1_label, "");

    //Write codes SwitchSet_cont_2
    ui->SwitchSet_cont_2 = lv_obj_create(ui->SwitchSet);
    lv_obj_set_pos(ui->SwitchSet_cont_2, -1, 516);
    lv_obj_set_size(ui->SwitchSet_cont_2, 720, 215);
    lv_obj_set_scrollbar_mode(ui->SwitchSet_cont_2, LV_SCROLLBAR_MODE_OFF);

    //Write style for SwitchSet_cont_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->SwitchSet_cont_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->SwitchSet_cont_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->SwitchSet_cont_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->SwitchSet_cont_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SwitchSet_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->SwitchSet_cont_2, 133, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SwitchSet_cont_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SwitchSet_cont_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->SwitchSet_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->SwitchSet_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->SwitchSet_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->SwitchSet_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SwitchSet_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SwitchSet_btn_5
    ui->SwitchSet_btn_5 = lv_btn_create(ui->SwitchSet_cont_2);
    ui->SwitchSet_btn_5_label = lv_label_create(ui->SwitchSet_btn_5);
    lv_label_set_text(ui->SwitchSet_btn_5_label, "清除已学");
    lv_label_set_long_mode(ui->SwitchSet_btn_5_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->SwitchSet_btn_5_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->SwitchSet_btn_5, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->SwitchSet_btn_5_label, LV_PCT(100));
    lv_obj_set_pos(ui->SwitchSet_btn_5, 563, 27);
    lv_obj_set_size(ui->SwitchSet_btn_5, 100, 50);

    //Write style for SwitchSet_btn_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->SwitchSet_btn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SwitchSet_btn_5, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SwitchSet_btn_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->SwitchSet_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SwitchSet_btn_5, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SwitchSet_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SwitchSet_btn_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SwitchSet_btn_5, &lv_font_ZiTiQuanWeiJunHeiW22_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SwitchSet_btn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->SwitchSet_btn_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SwitchSet_btn_4
    ui->SwitchSet_btn_4 = lv_btn_create(ui->SwitchSet_cont_2);
    ui->SwitchSet_btn_4_label = lv_label_create(ui->SwitchSet_btn_4);
    lv_label_set_text(ui->SwitchSet_btn_4_label, "开始学码");
    lv_label_set_long_mode(ui->SwitchSet_btn_4_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->SwitchSet_btn_4_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->SwitchSet_btn_4, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->SwitchSet_btn_4_label, LV_PCT(100));
    lv_obj_set_pos(ui->SwitchSet_btn_4, 563, 122);
    lv_obj_set_size(ui->SwitchSet_btn_4, 100, 50);

    //Write style for SwitchSet_btn_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->SwitchSet_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SwitchSet_btn_4, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SwitchSet_btn_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->SwitchSet_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SwitchSet_btn_4, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SwitchSet_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SwitchSet_btn_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SwitchSet_btn_4, &lv_font_ZiTiQuanWeiJunHeiW22_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SwitchSet_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->SwitchSet_btn_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SwitchSet_label_2
    ui->SwitchSet_label_2 = lv_label_create(ui->SwitchSet_cont_2);
    lv_label_set_text(ui->SwitchSet_label_2, "按键3  互控");
    lv_label_set_long_mode(ui->SwitchSet_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->SwitchSet_label_2, 0, 19);
    lv_obj_set_size(ui->SwitchSet_label_2, 170, 40);

    //Write style for SwitchSet_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->SwitchSet_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SwitchSet_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SwitchSet_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SwitchSet_label_2, &lv_font_ZiTiQuanWeiJunHeiW22_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SwitchSet_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->SwitchSet_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->SwitchSet_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->SwitchSet_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->SwitchSet_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->SwitchSet_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->SwitchSet_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->SwitchSet_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->SwitchSet_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SwitchSet_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SwitchSet_cont_1
    ui->SwitchSet_cont_1 = lv_obj_create(ui->SwitchSet);
    lv_obj_set_pos(ui->SwitchSet_cont_1, -2, 87);
    lv_obj_set_size(ui->SwitchSet_cont_1, 720, 215);
    lv_obj_set_scrollbar_mode(ui->SwitchSet_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for SwitchSet_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->SwitchSet_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->SwitchSet_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->SwitchSet_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->SwitchSet_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SwitchSet_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->SwitchSet_cont_1, 133, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SwitchSet_cont_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SwitchSet_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->SwitchSet_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->SwitchSet_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->SwitchSet_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->SwitchSet_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SwitchSet_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SwitchSet_btn_2
    ui->SwitchSet_btn_2 = lv_btn_create(ui->SwitchSet_cont_1);
    ui->SwitchSet_btn_2_label = lv_label_create(ui->SwitchSet_btn_2);
    lv_label_set_text(ui->SwitchSet_btn_2_label, "清除已学");
    lv_label_set_long_mode(ui->SwitchSet_btn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->SwitchSet_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->SwitchSet_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->SwitchSet_btn_2_label, LV_PCT(100));
    lv_obj_set_pos(ui->SwitchSet_btn_2, 563, 27);
    lv_obj_set_size(ui->SwitchSet_btn_2, 100, 50);

    //Write style for SwitchSet_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->SwitchSet_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SwitchSet_btn_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SwitchSet_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->SwitchSet_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SwitchSet_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SwitchSet_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SwitchSet_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SwitchSet_btn_2, &lv_font_ZiTiQuanWeiJunHeiW22_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SwitchSet_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->SwitchSet_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SwitchSet_btn_3
    ui->SwitchSet_btn_3 = lv_btn_create(ui->SwitchSet_cont_1);
    ui->SwitchSet_btn_3_label = lv_label_create(ui->SwitchSet_btn_3);
    lv_label_set_text(ui->SwitchSet_btn_3_label, "开始学码");
    lv_label_set_long_mode(ui->SwitchSet_btn_3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->SwitchSet_btn_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->SwitchSet_btn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->SwitchSet_btn_3_label, LV_PCT(100));
    lv_obj_set_pos(ui->SwitchSet_btn_3, 563, 122);
    lv_obj_set_size(ui->SwitchSet_btn_3, 100, 50);

    //Write style for SwitchSet_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->SwitchSet_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SwitchSet_btn_3, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SwitchSet_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->SwitchSet_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SwitchSet_btn_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SwitchSet_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SwitchSet_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SwitchSet_btn_3, &lv_font_ZiTiQuanWeiJunHeiW22_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SwitchSet_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->SwitchSet_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SwitchSet_label_1
    ui->SwitchSet_label_1 = lv_label_create(ui->SwitchSet_cont_1);
    lv_label_set_text(ui->SwitchSet_label_1, "按键1  互控");
    lv_label_set_long_mode(ui->SwitchSet_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->SwitchSet_label_1, 0, 19);
    lv_obj_set_size(ui->SwitchSet_label_1, 170, 40);

    //Write style for SwitchSet_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->SwitchSet_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SwitchSet_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SwitchSet_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SwitchSet_label_1, &lv_font_ZiTiQuanWeiJunHeiW22_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SwitchSet_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->SwitchSet_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->SwitchSet_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->SwitchSet_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->SwitchSet_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->SwitchSet_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->SwitchSet_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->SwitchSet_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->SwitchSet_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SwitchSet_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SwitchSet_cont_3
    ui->SwitchSet_cont_3 = lv_obj_create(ui->SwitchSet);
    lv_obj_set_pos(ui->SwitchSet_cont_3, -2, 302);
    lv_obj_set_size(ui->SwitchSet_cont_3, 720, 215);
    lv_obj_set_scrollbar_mode(ui->SwitchSet_cont_3, LV_SCROLLBAR_MODE_OFF);

    //Write style for SwitchSet_cont_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->SwitchSet_cont_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->SwitchSet_cont_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->SwitchSet_cont_3, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->SwitchSet_cont_3, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SwitchSet_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->SwitchSet_cont_3, 133, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SwitchSet_cont_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SwitchSet_cont_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->SwitchSet_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->SwitchSet_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->SwitchSet_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->SwitchSet_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SwitchSet_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SwitchSet_btn_7
    ui->SwitchSet_btn_7 = lv_btn_create(ui->SwitchSet_cont_3);
    ui->SwitchSet_btn_7_label = lv_label_create(ui->SwitchSet_btn_7);
    lv_label_set_text(ui->SwitchSet_btn_7_label, "清除已学");
    lv_label_set_long_mode(ui->SwitchSet_btn_7_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->SwitchSet_btn_7_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->SwitchSet_btn_7, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->SwitchSet_btn_7_label, LV_PCT(100));
    lv_obj_set_pos(ui->SwitchSet_btn_7, 563, 27);
    lv_obj_set_size(ui->SwitchSet_btn_7, 100, 50);

    //Write style for SwitchSet_btn_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->SwitchSet_btn_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SwitchSet_btn_7, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SwitchSet_btn_7, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->SwitchSet_btn_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SwitchSet_btn_7, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SwitchSet_btn_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SwitchSet_btn_7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SwitchSet_btn_7, &lv_font_ZiTiQuanWeiJunHeiW22_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SwitchSet_btn_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->SwitchSet_btn_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SwitchSet_btn_6
    ui->SwitchSet_btn_6 = lv_btn_create(ui->SwitchSet_cont_3);
    ui->SwitchSet_btn_6_label = lv_label_create(ui->SwitchSet_btn_6);
    lv_label_set_text(ui->SwitchSet_btn_6_label, "开始学码");
    lv_label_set_long_mode(ui->SwitchSet_btn_6_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->SwitchSet_btn_6_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->SwitchSet_btn_6, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->SwitchSet_btn_6_label, LV_PCT(100));
    lv_obj_set_pos(ui->SwitchSet_btn_6, 563, 122);
    lv_obj_set_size(ui->SwitchSet_btn_6, 100, 50);

    //Write style for SwitchSet_btn_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->SwitchSet_btn_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SwitchSet_btn_6, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SwitchSet_btn_6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->SwitchSet_btn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SwitchSet_btn_6, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SwitchSet_btn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SwitchSet_btn_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SwitchSet_btn_6, &lv_font_ZiTiQuanWeiJunHeiW22_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SwitchSet_btn_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->SwitchSet_btn_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SwitchSet_label_3
    ui->SwitchSet_label_3 = lv_label_create(ui->SwitchSet_cont_3);
    lv_label_set_text(ui->SwitchSet_label_3, "按键2  互控");
    lv_label_set_long_mode(ui->SwitchSet_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->SwitchSet_label_3, 0, 19);
    lv_obj_set_size(ui->SwitchSet_label_3, 170, 40);

    //Write style for SwitchSet_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->SwitchSet_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SwitchSet_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SwitchSet_label_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SwitchSet_label_3, &lv_font_ZiTiQuanWeiJunHeiW22_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SwitchSet_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->SwitchSet_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->SwitchSet_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->SwitchSet_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->SwitchSet_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->SwitchSet_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->SwitchSet_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->SwitchSet_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->SwitchSet_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SwitchSet_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SwitchSet_btn_1
    ui->SwitchSet_btn_1 = lv_btn_create(ui->SwitchSet);
    ui->SwitchSet_btn_1_label = lv_label_create(ui->SwitchSet_btn_1);
    lv_label_set_text(ui->SwitchSet_btn_1_label, "<  开关配置");
    lv_label_set_long_mode(ui->SwitchSet_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->SwitchSet_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->SwitchSet_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->SwitchSet_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->SwitchSet_btn_1, 40, 25);
    lv_obj_set_size(ui->SwitchSet_btn_1, 152, 38);

    //Write style for SwitchSet_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->SwitchSet_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->SwitchSet_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SwitchSet_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SwitchSet_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SwitchSet_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SwitchSet_btn_1, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SwitchSet_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->SwitchSet_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SwitchSet_btn_8
    ui->SwitchSet_btn_8 = lv_btn_create(ui->SwitchSet);
    ui->SwitchSet_btn_8_label = lv_label_create(ui->SwitchSet_btn_8);
    lv_label_set_text(ui->SwitchSet_btn_8_label, "");
    lv_label_set_long_mode(ui->SwitchSet_btn_8_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->SwitchSet_btn_8_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->SwitchSet_btn_8, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->SwitchSet_btn_8_label, LV_PCT(100));
    lv_obj_set_pos(ui->SwitchSet_btn_8, 4, 4);
    lv_obj_set_size(ui->SwitchSet_btn_8, 229, 82);

    //Write style for SwitchSet_btn_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->SwitchSet_btn_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->SwitchSet_btn_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SwitchSet_btn_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SwitchSet_btn_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SwitchSet_btn_8, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SwitchSet_btn_8, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SwitchSet_btn_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->SwitchSet_btn_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of SwitchSet.


    //Update current screen layout.
    lv_obj_update_layout(ui->SwitchSet);

}
