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



void setup_scr_NetSett(lv_ui *ui)
{
    //Write codes NetSett
    ui->NetSett = lv_obj_create(NULL);
    lv_obj_set_size(ui->NetSett, 720, 720);
    lv_obj_set_scrollbar_mode(ui->NetSett, LV_SCROLLBAR_MODE_OFF);

    //Write style for NetSett, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->NetSett, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->NetSett, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->NetSett, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes NetSett_tabview_1
    ui->NetSett_tabview_1 = lv_tabview_create(ui->NetSett, LV_DIR_TOP, 70);
    lv_obj_set_pos(ui->NetSett_tabview_1, 0, 0);
    lv_obj_set_size(ui->NetSett_tabview_1, 720, 720);
    lv_obj_set_scrollbar_mode(ui->NetSett_tabview_1, LV_SCROLLBAR_MODE_ON);

    //Write style for NetSett_tabview_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->NetSett_tabview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->NetSett_tabview_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->NetSett_tabview_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->NetSett_tabview_1, lv_color_hex(0x4d4d4d), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->NetSett_tabview_1, &lv_font_ZiTiQuanWeiJunHeiW22_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->NetSett_tabview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->NetSett_tabview_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->NetSett_tabview_1, 16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->NetSett_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->NetSett_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->NetSett_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_NetSett_tabview_1_extra_btnm_main_default
    static lv_style_t style_NetSett_tabview_1_extra_btnm_main_default;
    ui_init_style(&style_NetSett_tabview_1_extra_btnm_main_default);

    lv_style_set_bg_opa(&style_NetSett_tabview_1_extra_btnm_main_default, 255);
    lv_style_set_bg_color(&style_NetSett_tabview_1_extra_btnm_main_default, lv_color_hex(0x243241));
    lv_style_set_bg_grad_dir(&style_NetSett_tabview_1_extra_btnm_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_NetSett_tabview_1_extra_btnm_main_default, 0);
    lv_style_set_radius(&style_NetSett_tabview_1_extra_btnm_main_default, 0);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->NetSett_tabview_1), &style_NetSett_tabview_1_extra_btnm_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_NetSett_tabview_1_extra_btnm_items_default
    static lv_style_t style_NetSett_tabview_1_extra_btnm_items_default;
    ui_init_style(&style_NetSett_tabview_1_extra_btnm_items_default);

    lv_style_set_text_color(&style_NetSett_tabview_1_extra_btnm_items_default, lv_color_hex(0x4d4d4d));
    lv_style_set_text_font(&style_NetSett_tabview_1_extra_btnm_items_default, &lv_font_ZiTiQuanWeiJunHeiW22_12);
    lv_style_set_text_opa(&style_NetSett_tabview_1_extra_btnm_items_default, 255);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->NetSett_tabview_1), &style_NetSett_tabview_1_extra_btnm_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_NetSett_tabview_1_extra_btnm_items_checked
    static lv_style_t style_NetSett_tabview_1_extra_btnm_items_checked;
    ui_init_style(&style_NetSett_tabview_1_extra_btnm_items_checked);

    lv_style_set_text_color(&style_NetSett_tabview_1_extra_btnm_items_checked, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_NetSett_tabview_1_extra_btnm_items_checked, &lv_font_ZiTiQuanWeiJunHeiW22_20);
    lv_style_set_text_opa(&style_NetSett_tabview_1_extra_btnm_items_checked, 255);
    lv_style_set_border_width(&style_NetSett_tabview_1_extra_btnm_items_checked, 0);
    lv_style_set_radius(&style_NetSett_tabview_1_extra_btnm_items_checked, 0);
    lv_style_set_bg_opa(&style_NetSett_tabview_1_extra_btnm_items_checked, 255);
    lv_style_set_bg_color(&style_NetSett_tabview_1_extra_btnm_items_checked, lv_color_hex(0x0f0f12));
    lv_style_set_bg_grad_dir(&style_NetSett_tabview_1_extra_btnm_items_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->NetSett_tabview_1), &style_NetSett_tabview_1_extra_btnm_items_checked, LV_PART_ITEMS|LV_STATE_CHECKED);

    //Write codes
    ui->NetSett_tabview_1_tab_1 = lv_tabview_add_tab(ui->NetSett_tabview_1,"");
    lv_obj_t * NetSett_tabview_1_tab_1_label = lv_label_create(ui->NetSett_tabview_1_tab_1);
    lv_label_set_text(NetSett_tabview_1_tab_1_label, "");

    //Write codes NetSett_NetSet
    ui->NetSett_NetSet = lv_btn_create(ui->NetSett);
    ui->NetSett_NetSet_label = lv_label_create(ui->NetSett_NetSet);
    lv_label_set_text(ui->NetSett_NetSet_label, "<  网络设置");
    lv_label_set_long_mode(ui->NetSett_NetSet_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->NetSett_NetSet_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->NetSett_NetSet, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->NetSett_NetSet_label, LV_PCT(100));
    lv_obj_set_pos(ui->NetSett_NetSet, 11, 7);
    lv_obj_set_size(ui->NetSett_NetSet, 156, 50);

    //Write style for NetSett_NetSet, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->NetSett_NetSet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->NetSett_NetSet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->NetSett_NetSet, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->NetSett_NetSet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->NetSett_NetSet, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->NetSett_NetSet, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->NetSett_NetSet, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->NetSett_NetSet, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of NetSett.


    //Update current screen layout.
    lv_obj_update_layout(ui->NetSett);

}
