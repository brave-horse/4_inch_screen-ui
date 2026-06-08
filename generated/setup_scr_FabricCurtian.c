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



void setup_scr_FabricCurtian(lv_ui *ui)
{
    //Write codes FabricCurtian
    ui->FabricCurtian = lv_obj_create(NULL);
    lv_obj_set_size(ui->FabricCurtian, 720, 720);
    lv_obj_set_scrollbar_mode(ui->FabricCurtian, LV_SCROLLBAR_MODE_OFF);

    //Write style for FabricCurtian, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->FabricCurtian, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->FabricCurtian, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->FabricCurtian, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes FabricCurtian_tabview_1
    ui->FabricCurtian_tabview_1 = lv_tabview_create(ui->FabricCurtian, LV_DIR_TOP, 70);
    lv_obj_set_pos(ui->FabricCurtian_tabview_1, 0, 0);
    lv_obj_set_size(ui->FabricCurtian_tabview_1, 720, 720);
    lv_obj_set_scrollbar_mode(ui->FabricCurtian_tabview_1, LV_SCROLLBAR_MODE_ON);

    //Write style for FabricCurtian_tabview_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->FabricCurtian_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->FabricCurtian_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->FabricCurtian_tabview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->FabricCurtian_tabview_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->FabricCurtian_tabview_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->FabricCurtian_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->FabricCurtian_tabview_1, lv_color_hex(0x4d4d4d), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->FabricCurtian_tabview_1, &lv_font_ZiTiQuanWeiJunHeiW22_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->FabricCurtian_tabview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->FabricCurtian_tabview_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->FabricCurtian_tabview_1, 16, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_FabricCurtian_tabview_1_extra_btnm_main_default
    static lv_style_t style_FabricCurtian_tabview_1_extra_btnm_main_default;
    ui_init_style(&style_FabricCurtian_tabview_1_extra_btnm_main_default);

    lv_style_set_bg_opa(&style_FabricCurtian_tabview_1_extra_btnm_main_default, 255);
    lv_style_set_bg_color(&style_FabricCurtian_tabview_1_extra_btnm_main_default, lv_color_hex(0x4f3f3f));
    lv_style_set_bg_grad_dir(&style_FabricCurtian_tabview_1_extra_btnm_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_FabricCurtian_tabview_1_extra_btnm_main_default, 0);
    lv_style_set_radius(&style_FabricCurtian_tabview_1_extra_btnm_main_default, 0);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->FabricCurtian_tabview_1), &style_FabricCurtian_tabview_1_extra_btnm_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_FabricCurtian_tabview_1_extra_btnm_items_default
    static lv_style_t style_FabricCurtian_tabview_1_extra_btnm_items_default;
    ui_init_style(&style_FabricCurtian_tabview_1_extra_btnm_items_default);

    lv_style_set_text_color(&style_FabricCurtian_tabview_1_extra_btnm_items_default, lv_color_hex(0x4d4d4d));
    lv_style_set_text_font(&style_FabricCurtian_tabview_1_extra_btnm_items_default, &lv_font_ZiTiQuanWeiJunHeiW22_12);
    lv_style_set_text_opa(&style_FabricCurtian_tabview_1_extra_btnm_items_default, 255);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->FabricCurtian_tabview_1), &style_FabricCurtian_tabview_1_extra_btnm_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_FabricCurtian_tabview_1_extra_btnm_items_checked
    static lv_style_t style_FabricCurtian_tabview_1_extra_btnm_items_checked;
    ui_init_style(&style_FabricCurtian_tabview_1_extra_btnm_items_checked);

    lv_style_set_text_color(&style_FabricCurtian_tabview_1_extra_btnm_items_checked, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_FabricCurtian_tabview_1_extra_btnm_items_checked, &lv_font_ZiTiQuanWeiJunHeiW22_20);
    lv_style_set_text_opa(&style_FabricCurtian_tabview_1_extra_btnm_items_checked, 255);
    lv_style_set_border_width(&style_FabricCurtian_tabview_1_extra_btnm_items_checked, 0);
    lv_style_set_radius(&style_FabricCurtian_tabview_1_extra_btnm_items_checked, 0);
    lv_style_set_bg_opa(&style_FabricCurtian_tabview_1_extra_btnm_items_checked, 255);
    lv_style_set_bg_color(&style_FabricCurtian_tabview_1_extra_btnm_items_checked, lv_color_hex(0x0f0f12));
    lv_style_set_bg_grad_dir(&style_FabricCurtian_tabview_1_extra_btnm_items_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->FabricCurtian_tabview_1), &style_FabricCurtian_tabview_1_extra_btnm_items_checked, LV_PART_ITEMS|LV_STATE_CHECKED);

    //Write codes
    ui->FabricCurtian_tabview_1_tab_1 = lv_tabview_add_tab(ui->FabricCurtian_tabview_1,"");
    lv_obj_t * FabricCurtian_tabview_1_tab_1_label = lv_label_create(ui->FabricCurtian_tabview_1_tab_1);
    lv_label_set_text(FabricCurtian_tabview_1_tab_1_label, "");

    //Write codes FabricCurtian_cont_1
    ui->FabricCurtian_cont_1 = lv_obj_create(ui->FabricCurtian);
    lv_obj_set_pos(ui->FabricCurtian_cont_1, 0, 72);
    lv_obj_set_size(ui->FabricCurtian_cont_1, 720, 645);
    lv_obj_set_scrollbar_mode(ui->FabricCurtian_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for FabricCurtian_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->FabricCurtian_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->FabricCurtian_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->FabricCurtian_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->FabricCurtian_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->FabricCurtian_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->FabricCurtian_cont_1, 133, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->FabricCurtian_cont_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->FabricCurtian_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->FabricCurtian_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->FabricCurtian_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->FabricCurtian_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->FabricCurtian_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->FabricCurtian_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes FabricCurtian_imgbtn_1
    ui->FabricCurtian_imgbtn_1 = lv_imgbtn_create(ui->FabricCurtian);
    lv_obj_add_flag(ui->FabricCurtian_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_imgbtn_set_src(ui->FabricCurtian_imgbtn_1, LV_IMGBTN_STATE_RELEASED, NULL, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\scene_btn.png", NULL);
    lv_imgbtn_set_src(ui->FabricCurtian_imgbtn_1, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\btn_close.png", NULL);
#else
    lv_imgbtn_set_src(ui->FabricCurtian_imgbtn_1, LV_IMGBTN_STATE_RELEASED, NULL, "S:/sdfile/EXT_RESERVED/uipackres/ui/scene_btn.png", NULL);
    lv_imgbtn_set_src(ui->FabricCurtian_imgbtn_1, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, "S:/sdfile/EXT_RESERVED/uipackres/ui/btn_close.png", NULL);
#endif
    ui->FabricCurtian_imgbtn_1_label = lv_label_create(ui->FabricCurtian_imgbtn_1);
    lv_label_set_text(ui->FabricCurtian_imgbtn_1_label, "");
    lv_label_set_long_mode(ui->FabricCurtian_imgbtn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->FabricCurtian_imgbtn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->FabricCurtian_imgbtn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->FabricCurtian_imgbtn_1, 652, 101);
    lv_obj_set_size(ui->FabricCurtian_imgbtn_1, 48, 48);

    //Write style for FabricCurtian_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->FabricCurtian_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->FabricCurtian_imgbtn_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->FabricCurtian_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->FabricCurtian_imgbtn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->FabricCurtian_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->FabricCurtian_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->FabricCurtian_imgbtn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for FabricCurtian_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_shadow_width(ui->FabricCurtian_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->FabricCurtian_imgbtn_1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->FabricCurtian_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->FabricCurtian_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_recolor_opa(ui->FabricCurtian_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->FabricCurtian_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for FabricCurtian_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_shadow_width(ui->FabricCurtian_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->FabricCurtian_imgbtn_1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->FabricCurtian_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->FabricCurtian_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_recolor_opa(ui->FabricCurtian_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->FabricCurtian_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for FabricCurtian_imgbtn_1, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->FabricCurtian_imgbtn_1, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->FabricCurtian_imgbtn_1, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes FabricCurtian_btn_1
    ui->FabricCurtian_btn_1 = lv_btn_create(ui->FabricCurtian);
    ui->FabricCurtian_btn_1_label = lv_label_create(ui->FabricCurtian_btn_1);
    lv_label_set_text(ui->FabricCurtian_btn_1_label, "<  布帘");
    lv_label_set_long_mode(ui->FabricCurtian_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->FabricCurtian_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->FabricCurtian_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->FabricCurtian_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->FabricCurtian_btn_1, 11, 5);
    lv_obj_set_size(ui->FabricCurtian_btn_1, 156, 50);

    //Write style for FabricCurtian_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->FabricCurtian_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->FabricCurtian_btn_1, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->FabricCurtian_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->FabricCurtian_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->FabricCurtian_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->FabricCurtian_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->FabricCurtian_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->FabricCurtian_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes FabricCurtian_on_off_2_img
    ui->FabricCurtian_on_off_2_img = lv_imgbtn_create(ui->FabricCurtian);
    lv_obj_add_flag(ui->FabricCurtian_on_off_2_img, LV_OBJ_FLAG_CHECKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_imgbtn_set_src(ui->FabricCurtian_on_off_2_img, LV_IMGBTN_STATE_RELEASED, NULL, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\onoff_off.png", NULL);
    lv_imgbtn_set_src(ui->FabricCurtian_on_off_2_img, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\onoff_on.png", NULL);
#else
    lv_imgbtn_set_src(ui->FabricCurtian_on_off_2_img, LV_IMGBTN_STATE_RELEASED, NULL, "S:/sdfile/EXT_RESERVED/uipackres/ui/onoff_off.png", NULL);
    lv_imgbtn_set_src(ui->FabricCurtian_on_off_2_img, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, "S:/sdfile/EXT_RESERVED/uipackres/ui/onoff_on.png", NULL);
#endif
    ui->FabricCurtian_on_off_2_img_label = lv_label_create(ui->FabricCurtian_on_off_2_img);
    lv_label_set_text(ui->FabricCurtian_on_off_2_img_label, "");
    lv_label_set_long_mode(ui->FabricCurtian_on_off_2_img_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->FabricCurtian_on_off_2_img_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->FabricCurtian_on_off_2_img, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->FabricCurtian_on_off_2_img, 20, 101);
    lv_obj_set_size(ui->FabricCurtian_on_off_2_img, 48, 48);

    //Write style for FabricCurtian_on_off_2_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->FabricCurtian_on_off_2_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->FabricCurtian_on_off_2_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->FabricCurtian_on_off_2_img, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->FabricCurtian_on_off_2_img, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->FabricCurtian_on_off_2_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->FabricCurtian_on_off_2_img, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->FabricCurtian_on_off_2_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for FabricCurtian_on_off_2_img, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->FabricCurtian_on_off_2_img, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->FabricCurtian_on_off_2_img, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->FabricCurtian_on_off_2_img, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->FabricCurtian_on_off_2_img, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->FabricCurtian_on_off_2_img, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->FabricCurtian_on_off_2_img, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for FabricCurtian_on_off_2_img, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->FabricCurtian_on_off_2_img, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->FabricCurtian_on_off_2_img, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->FabricCurtian_on_off_2_img, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->FabricCurtian_on_off_2_img, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->FabricCurtian_on_off_2_img, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->FabricCurtian_on_off_2_img, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for FabricCurtian_on_off_2_img, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->FabricCurtian_on_off_2_img, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->FabricCurtian_on_off_2_img, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes FabricCurtian_FabCurtianOpen
    ui->FabricCurtian_FabCurtianOpen = lv_img_create(ui->FabricCurtian);
    lv_obj_add_flag(ui->FabricCurtian_FabCurtianOpen, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->FabricCurtian_FabCurtianOpen, &_FabCurtianOpen_alpha_94x95);
    lv_img_set_pivot(ui->FabricCurtian_FabCurtianOpen, 50,50);
    lv_img_set_angle(ui->FabricCurtian_FabCurtianOpen, 0);
    lv_obj_set_pos(ui->FabricCurtian_FabCurtianOpen, 62, 568);
    lv_obj_set_size(ui->FabricCurtian_FabCurtianOpen, 94, 95);

    //Write style for FabricCurtian_FabCurtianOpen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->FabricCurtian_FabCurtianOpen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->FabricCurtian_FabCurtianOpen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->FabricCurtian_FabCurtianOpen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->FabricCurtian_FabCurtianOpen, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes FabricCurtian_FabCurtianClose
    ui->FabricCurtian_FabCurtianClose = lv_img_create(ui->FabricCurtian);
    lv_obj_add_flag(ui->FabricCurtian_FabCurtianClose, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->FabricCurtian_FabCurtianClose, &_FabCurtianClose_alpha_95x95);
    lv_img_set_pivot(ui->FabricCurtian_FabCurtianClose, 50,50);
    lv_img_set_angle(ui->FabricCurtian_FabCurtianClose, 0);
    lv_obj_set_pos(ui->FabricCurtian_FabCurtianClose, 560, 562);
    lv_obj_set_size(ui->FabricCurtian_FabCurtianClose, 95, 95);

    //Write style for FabricCurtian_FabCurtianClose, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->FabricCurtian_FabCurtianClose, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->FabricCurtian_FabCurtianClose, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->FabricCurtian_FabCurtianClose, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->FabricCurtian_FabCurtianClose, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes FabricCurtian_FabCurtianPause
    ui->FabricCurtian_FabCurtianPause = lv_img_create(ui->FabricCurtian);
    lv_obj_add_flag(ui->FabricCurtian_FabCurtianPause, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->FabricCurtian_FabCurtianPause, &_FabCurtianPause_alpha_109x110);
    lv_img_set_pivot(ui->FabricCurtian_FabCurtianPause, 50,50);
    lv_img_set_angle(ui->FabricCurtian_FabCurtianPause, 0);
    lv_obj_set_pos(ui->FabricCurtian_FabCurtianPause, 267, 562);
    lv_obj_set_size(ui->FabricCurtian_FabCurtianPause, 109, 110);

    //Write style for FabricCurtian_FabCurtianPause, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->FabricCurtian_FabCurtianPause, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->FabricCurtian_FabCurtianPause, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->FabricCurtian_FabCurtianPause, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->FabricCurtian_FabCurtianPause, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes FabricCurtian_FabCurtianBg1
    ui->FabricCurtian_FabCurtianBg1 = lv_img_create(ui->FabricCurtian);
    lv_obj_add_flag(ui->FabricCurtian_FabCurtianBg1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->FabricCurtian_FabCurtianBg1, &_FabCurtianBg1_alpha_62x60);
    lv_img_set_pivot(ui->FabricCurtian_FabCurtianBg1, 50,50);
    lv_img_set_angle(ui->FabricCurtian_FabCurtianBg1, 0);
    lv_obj_set_pos(ui->FabricCurtian_FabCurtianBg1, 232, 255);
    lv_obj_set_size(ui->FabricCurtian_FabCurtianBg1, 62, 60);

    //Write style for FabricCurtian_FabCurtianBg1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->FabricCurtian_FabCurtianBg1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->FabricCurtian_FabCurtianBg1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->FabricCurtian_FabCurtianBg1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->FabricCurtian_FabCurtianBg1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes FabricCurtian_FabCurtianBg3
    ui->FabricCurtian_FabCurtianBg3 = lv_img_create(ui->FabricCurtian);
    lv_obj_add_flag(ui->FabricCurtian_FabCurtianBg3, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->FabricCurtian_FabCurtianBg3, &_FabCurtianBg3_alpha_42x14);
    lv_img_set_pivot(ui->FabricCurtian_FabCurtianBg3, 50,50);
    lv_img_set_angle(ui->FabricCurtian_FabCurtianBg3, 0);
    lv_obj_set_pos(ui->FabricCurtian_FabCurtianBg3, 252, 384);
    lv_obj_set_size(ui->FabricCurtian_FabCurtianBg3, 42, 14);

    //Write style for FabricCurtian_FabCurtianBg3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->FabricCurtian_FabCurtianBg3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->FabricCurtian_FabCurtianBg3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->FabricCurtian_FabCurtianBg3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->FabricCurtian_FabCurtianBg3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes FabricCurtian_FabCurtianBg2
    ui->FabricCurtian_FabCurtianBg2 = lv_img_create(ui->FabricCurtian);
    lv_obj_add_flag(ui->FabricCurtian_FabCurtianBg2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->FabricCurtian_FabCurtianBg2, &_FabCurtianBg2_alpha_34x73);
    lv_img_set_pivot(ui->FabricCurtian_FabCurtianBg2, 50,50);
    lv_img_set_angle(ui->FabricCurtian_FabCurtianBg2, 0);
    lv_obj_set_pos(ui->FabricCurtian_FabCurtianBg2, 415, 272);
    lv_obj_set_size(ui->FabricCurtian_FabCurtianBg2, 34, 73);

    //Write style for FabricCurtian_FabCurtianBg2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->FabricCurtian_FabCurtianBg2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->FabricCurtian_FabCurtianBg2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->FabricCurtian_FabCurtianBg2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->FabricCurtian_FabCurtianBg2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes FabricCurtian_FabCurtianLeft
    ui->FabricCurtian_FabCurtianLeft = lv_img_create(ui->FabricCurtian);
    lv_obj_add_flag(ui->FabricCurtian_FabCurtianLeft, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->FabricCurtian_FabCurtianLeft, &_FabCurtianright_alpha_231x287);
    lv_img_set_pivot(ui->FabricCurtian_FabCurtianLeft, 50,50);
    lv_img_set_angle(ui->FabricCurtian_FabCurtianLeft, 0);
    lv_obj_set_pos(ui->FabricCurtian_FabCurtianLeft, 128, 193);
    lv_obj_set_size(ui->FabricCurtian_FabCurtianLeft, 231, 287);

    //Write style for FabricCurtian_FabCurtianLeft, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->FabricCurtian_FabCurtianLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->FabricCurtian_FabCurtianLeft, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->FabricCurtian_FabCurtianLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->FabricCurtian_FabCurtianLeft, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes FabricCurtian_FabCurtianright
    ui->FabricCurtian_FabCurtianright = lv_img_create(ui->FabricCurtian);
    lv_obj_add_flag(ui->FabricCurtian_FabCurtianright, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->FabricCurtian_FabCurtianright, &_FabCurtianright_alpha_231x287);
    lv_img_set_pivot(ui->FabricCurtian_FabCurtianright, 50,50);
    lv_img_set_angle(ui->FabricCurtian_FabCurtianright, 0);
    lv_obj_set_pos(ui->FabricCurtian_FabCurtianright, 359, 193);
    lv_obj_set_size(ui->FabricCurtian_FabCurtianright, 231, 287);

    //Write style for FabricCurtian_FabCurtianright, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->FabricCurtian_FabCurtianright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->FabricCurtian_FabCurtianright, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->FabricCurtian_FabCurtianright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->FabricCurtian_FabCurtianright, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes FabricCurtian_FabCurtianPull2
    ui->FabricCurtian_FabCurtianPull2 = lv_img_create(ui->FabricCurtian);
    lv_obj_add_flag(ui->FabricCurtian_FabCurtianPull2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->FabricCurtian_FabCurtianPull2, &_FabCurtianPull_alpha_45x45);
    lv_img_set_pivot(ui->FabricCurtian_FabCurtianPull2, 50,50);
    lv_img_set_angle(ui->FabricCurtian_FabCurtianPull2, 0);
    lv_obj_set_pos(ui->FabricCurtian_FabCurtianPull2, 367, 321);
    lv_obj_set_size(ui->FabricCurtian_FabCurtianPull2, 45, 45);

    //Write style for FabricCurtian_FabCurtianPull2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->FabricCurtian_FabCurtianPull2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->FabricCurtian_FabCurtianPull2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->FabricCurtian_FabCurtianPull2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->FabricCurtian_FabCurtianPull2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes FabricCurtian_FabCurtianPull1
    ui->FabricCurtian_FabCurtianPull1 = lv_img_create(ui->FabricCurtian);
    lv_obj_add_flag(ui->FabricCurtian_FabCurtianPull1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->FabricCurtian_FabCurtianPull1, &_FabCurtianPull_alpha_45x45);
    lv_img_set_pivot(ui->FabricCurtian_FabCurtianPull1, 50,50);
    lv_img_set_angle(ui->FabricCurtian_FabCurtianPull1, 0);
    lv_obj_set_pos(ui->FabricCurtian_FabCurtianPull1, 307, 321);
    lv_obj_set_size(ui->FabricCurtian_FabCurtianPull1, 45, 45);

    //Write style for FabricCurtian_FabCurtianPull1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->FabricCurtian_FabCurtianPull1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->FabricCurtian_FabCurtianPull1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->FabricCurtian_FabCurtianPull1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->FabricCurtian_FabCurtianPull1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes FabricCurtian_FabCurtianPole
    ui->FabricCurtian_FabCurtianPole = lv_img_create(ui->FabricCurtian);
    lv_obj_add_flag(ui->FabricCurtian_FabCurtianPole, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->FabricCurtian_FabCurtianPole, &_FabCurtianPole_alpha_494x34);
    lv_img_set_pivot(ui->FabricCurtian_FabCurtianPole, 50,50);
    lv_img_set_angle(ui->FabricCurtian_FabCurtianPole, 0);
    lv_obj_set_pos(ui->FabricCurtian_FabCurtianPole, 112, 178);
    lv_obj_set_size(ui->FabricCurtian_FabCurtianPole, 494, 34);

    //Write style for FabricCurtian_FabCurtianPole, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->FabricCurtian_FabCurtianPole, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->FabricCurtian_FabCurtianPole, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->FabricCurtian_FabCurtianPole, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->FabricCurtian_FabCurtianPole, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of FabricCurtian.


    //Update current screen layout.
    lv_obj_update_layout(ui->FabricCurtian);

}
