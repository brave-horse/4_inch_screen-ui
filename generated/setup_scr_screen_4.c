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



void setup_scr_screen_4(lv_ui *ui)
{
    //Write codes screen_4
    ui->screen_4 = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_4, 720, 720);
    lv_obj_set_scrollbar_mode(ui->screen_4, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_4_tabview_1
    ui->screen_4_tabview_1 = lv_tabview_create(ui->screen_4, LV_DIR_TOP, 70);
    lv_obj_set_pos(ui->screen_4_tabview_1, 0, 0);
    lv_obj_set_size(ui->screen_4_tabview_1, 720, 720);
    lv_obj_set_scrollbar_mode(ui->screen_4_tabview_1, LV_SCROLLBAR_MODE_ON);

    //Write style for screen_4_tabview_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_4_tabview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_4_tabview_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_4_tabview_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_4_tabview_1, lv_color_hex(0x4d4d4d), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_4_tabview_1, &lv_font_ZiTiQuanWeiJunHeiW22_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_4_tabview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_4_tabview_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_4_tabview_1, 16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_4_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_4_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_4_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_4_tabview_1_extra_btnm_main_default
    static lv_style_t style_screen_4_tabview_1_extra_btnm_main_default;
    ui_init_style(&style_screen_4_tabview_1_extra_btnm_main_default);

    lv_style_set_bg_opa(&style_screen_4_tabview_1_extra_btnm_main_default, 255);
    lv_style_set_bg_color(&style_screen_4_tabview_1_extra_btnm_main_default, lv_color_hex(0x4f3f3f));
    lv_style_set_bg_grad_dir(&style_screen_4_tabview_1_extra_btnm_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_screen_4_tabview_1_extra_btnm_main_default, 0);
    lv_style_set_radius(&style_screen_4_tabview_1_extra_btnm_main_default, 0);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->screen_4_tabview_1), &style_screen_4_tabview_1_extra_btnm_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_4_tabview_1_extra_btnm_items_default
    static lv_style_t style_screen_4_tabview_1_extra_btnm_items_default;
    ui_init_style(&style_screen_4_tabview_1_extra_btnm_items_default);

    lv_style_set_text_color(&style_screen_4_tabview_1_extra_btnm_items_default, lv_color_hex(0x4d4d4d));
    lv_style_set_text_font(&style_screen_4_tabview_1_extra_btnm_items_default, &lv_font_ZiTiQuanWeiJunHeiW22_12);
    lv_style_set_text_opa(&style_screen_4_tabview_1_extra_btnm_items_default, 255);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->screen_4_tabview_1), &style_screen_4_tabview_1_extra_btnm_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_screen_4_tabview_1_extra_btnm_items_checked
    static lv_style_t style_screen_4_tabview_1_extra_btnm_items_checked;
    ui_init_style(&style_screen_4_tabview_1_extra_btnm_items_checked);

    lv_style_set_text_color(&style_screen_4_tabview_1_extra_btnm_items_checked, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_screen_4_tabview_1_extra_btnm_items_checked, &lv_font_ZiTiQuanWeiJunHeiW22_20);
    lv_style_set_text_opa(&style_screen_4_tabview_1_extra_btnm_items_checked, 255);
    lv_style_set_border_width(&style_screen_4_tabview_1_extra_btnm_items_checked, 0);
    lv_style_set_radius(&style_screen_4_tabview_1_extra_btnm_items_checked, 0);
    lv_style_set_bg_opa(&style_screen_4_tabview_1_extra_btnm_items_checked, 255);
    lv_style_set_bg_color(&style_screen_4_tabview_1_extra_btnm_items_checked, lv_color_hex(0x0c0b0d));
    lv_style_set_bg_grad_dir(&style_screen_4_tabview_1_extra_btnm_items_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->screen_4_tabview_1), &style_screen_4_tabview_1_extra_btnm_items_checked, LV_PART_ITEMS|LV_STATE_CHECKED);

    //Write codes
    ui->screen_4_tabview_1_tab_1 = lv_tabview_add_tab(ui->screen_4_tabview_1,"");
    lv_obj_t * screen_4_tabview_1_tab_1_label = lv_label_create(ui->screen_4_tabview_1_tab_1);
    lv_label_set_text(screen_4_tabview_1_tab_1_label, "");

    //Write codes screen_4_list_1
    ui->screen_4_list_1 = lv_list_create(ui->screen_4);
    ui->screen_4_list_1_item0 = lv_list_add_btn(ui->screen_4_list_1, LV_SYMBOL_WIFI, "网络设置");
    ui->screen_4_list_1_item1 = lv_list_add_btn(ui->screen_4_list_1, LV_SYMBOL_LOOP, "显示设置");
    ui->screen_4_list_1_item2 = lv_list_add_btn(ui->screen_4_list_1, LV_SYMBOL_SAVE, "开关配置");
    ui->screen_4_list_1_item3 = lv_list_add_btn(ui->screen_4_list_1, LV_SYMBOL_SAVE, "传感器配置");
    ui->screen_4_list_1_item4 = lv_list_add_btn(ui->screen_4_list_1, LV_SYMBOL_SAVE, "设备重启");
    ui->screen_4_list_1_item5 = lv_list_add_btn(ui->screen_4_list_1, LV_SYMBOL_SAVE, "恢复出厂");
    ui->screen_4_list_1_item6 = lv_list_add_btn(ui->screen_4_list_1, LV_SYMBOL_SAVE, "关于产品");
    lv_obj_set_pos(ui->screen_4_list_1, 0, 71);
    lv_obj_set_size(ui->screen_4_list_1, 720, 650);
    lv_obj_set_scrollbar_mode(ui->screen_4_list_1, LV_SCROLLBAR_MODE_ON);

    //Write style state: LV_STATE_DEFAULT for &style_screen_4_list_1_main_main_default
    static lv_style_t style_screen_4_list_1_main_main_default;
    ui_init_style(&style_screen_4_list_1_main_main_default);

    lv_style_set_pad_top(&style_screen_4_list_1_main_main_default, 20);
    lv_style_set_pad_left(&style_screen_4_list_1_main_main_default, 0);
    lv_style_set_pad_right(&style_screen_4_list_1_main_main_default, 0);
    lv_style_set_pad_bottom(&style_screen_4_list_1_main_main_default, 0);
    lv_style_set_bg_opa(&style_screen_4_list_1_main_main_default, 255);
    lv_style_set_bg_color(&style_screen_4_list_1_main_main_default, lv_color_hex(0x000000));
    lv_style_set_bg_grad_dir(&style_screen_4_list_1_main_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_screen_4_list_1_main_main_default, 0);
    lv_style_set_radius(&style_screen_4_list_1_main_main_default, 0);
    lv_style_set_shadow_width(&style_screen_4_list_1_main_main_default, 0);
    lv_obj_add_style(ui->screen_4_list_1, &style_screen_4_list_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_4_list_1_main_scrollbar_default
    static lv_style_t style_screen_4_list_1_main_scrollbar_default;
    ui_init_style(&style_screen_4_list_1_main_scrollbar_default);

    lv_style_set_radius(&style_screen_4_list_1_main_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_screen_4_list_1_main_scrollbar_default, 255);
    lv_style_set_bg_color(&style_screen_4_list_1_main_scrollbar_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_4_list_1_main_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->screen_4_list_1, &style_screen_4_list_1_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_4_list_1_extra_btns_main_default
    static lv_style_t style_screen_4_list_1_extra_btns_main_default;
    ui_init_style(&style_screen_4_list_1_extra_btns_main_default);

    lv_style_set_pad_top(&style_screen_4_list_1_extra_btns_main_default, 20);
    lv_style_set_pad_left(&style_screen_4_list_1_extra_btns_main_default, 30);
    lv_style_set_pad_right(&style_screen_4_list_1_extra_btns_main_default, 10);
    lv_style_set_pad_bottom(&style_screen_4_list_1_extra_btns_main_default, 20);
    lv_style_set_border_width(&style_screen_4_list_1_extra_btns_main_default, 2);
    lv_style_set_border_opa(&style_screen_4_list_1_extra_btns_main_default, 255);
    lv_style_set_border_color(&style_screen_4_list_1_extra_btns_main_default, lv_color_hex(0x151313));
    lv_style_set_border_side(&style_screen_4_list_1_extra_btns_main_default, LV_BORDER_SIDE_BOTTOM);
    lv_style_set_text_color(&style_screen_4_list_1_extra_btns_main_default, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_screen_4_list_1_extra_btns_main_default, &lv_font_ZiTiQuanWeiJunHeiW22_30);
    lv_style_set_text_opa(&style_screen_4_list_1_extra_btns_main_default, 255);
    lv_style_set_radius(&style_screen_4_list_1_extra_btns_main_default, 0);
    lv_style_set_bg_opa(&style_screen_4_list_1_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_screen_4_list_1_extra_btns_main_default, lv_color_hex(0x000000));
    lv_style_set_bg_grad_dir(&style_screen_4_list_1_extra_btns_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->screen_4_list_1_item6, &style_screen_4_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_4_list_1_item5, &style_screen_4_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_4_list_1_item4, &style_screen_4_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_4_list_1_item3, &style_screen_4_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_4_list_1_item2, &style_screen_4_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_4_list_1_item1, &style_screen_4_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_4_list_1_item0, &style_screen_4_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_4_list_1_extra_texts_main_default
    static lv_style_t style_screen_4_list_1_extra_texts_main_default;
    ui_init_style(&style_screen_4_list_1_extra_texts_main_default);

    lv_style_set_pad_top(&style_screen_4_list_1_extra_texts_main_default, 0);
    lv_style_set_pad_left(&style_screen_4_list_1_extra_texts_main_default, 30);
    lv_style_set_pad_right(&style_screen_4_list_1_extra_texts_main_default, 0);
    lv_style_set_pad_bottom(&style_screen_4_list_1_extra_texts_main_default, 5);
    lv_style_set_border_width(&style_screen_4_list_1_extra_texts_main_default, 5);
    lv_style_set_border_opa(&style_screen_4_list_1_extra_texts_main_default, 255);
    lv_style_set_border_color(&style_screen_4_list_1_extra_texts_main_default, lv_color_hex(0xfafafa));
    lv_style_set_border_side(&style_screen_4_list_1_extra_texts_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_text_color(&style_screen_4_list_1_extra_texts_main_default, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_screen_4_list_1_extra_texts_main_default, &lv_font_ZiTiQuanWeiJunHeiW22_30);
    lv_style_set_text_opa(&style_screen_4_list_1_extra_texts_main_default, 255);
    lv_style_set_radius(&style_screen_4_list_1_extra_texts_main_default, 5);
    lv_style_set_transform_width(&style_screen_4_list_1_extra_texts_main_default, 0);
    lv_style_set_bg_opa(&style_screen_4_list_1_extra_texts_main_default, 0);

    //Write codes screen_4_btn_1
    ui->screen_4_btn_1 = lv_btn_create(ui->screen_4);
    ui->screen_4_btn_1_label = lv_label_create(ui->screen_4_btn_1);
    lv_label_set_text(ui->screen_4_btn_1_label, "返回");
    lv_label_set_long_mode(ui->screen_4_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_4_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_4_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_4_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_4_btn_1, 49, 11);
    lv_obj_set_size(ui->screen_4_btn_1, 100, 50);

    //Write style for screen_4_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_4_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_4_btn_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_4_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_4_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_4_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_4_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_4_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_4_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_4_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_4_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_4.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_4);

    //Init events for screen.
    events_init_screen_4(ui);
}
