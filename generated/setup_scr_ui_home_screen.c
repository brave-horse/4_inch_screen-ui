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



void setup_scr_ui_home_screen(lv_ui *ui)
{
    //Write codes ui_home_screen
    ui->ui_home_screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->ui_home_screen, 720, 720);
    lv_obj_set_scrollbar_mode(ui->ui_home_screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for ui_home_screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_home_screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_home_screen, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_home_screen, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_home_screen_img_1
    ui->ui_home_screen_img_1 = lv_img_create(ui->ui_home_screen);
    lv_obj_add_flag(ui->ui_home_screen_img_1, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->ui_home_screen_img_1, "D:\\7.NXP-GUI-PROJECT\\4_inch_screen\\import\\image\\4.png");
#else
    lv_img_set_src(ui->ui_home_screen_img_1, "S:/sdfile/EXT_RESERVED/uipackres/ui/4.png");
#endif
    lv_img_set_pivot(ui->ui_home_screen_img_1, 50,50);
    lv_img_set_angle(ui->ui_home_screen_img_1, 0);
    lv_obj_set_pos(ui->ui_home_screen_img_1, 0, -2);
    lv_obj_set_size(ui->ui_home_screen_img_1, 720, 720);

    //Write style for ui_home_screen_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->ui_home_screen_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->ui_home_screen_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_home_screen_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->ui_home_screen_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_home_screen_label_1
    ui->ui_home_screen_label_1 = lv_label_create(ui->ui_home_screen);
    lv_label_set_text(ui->ui_home_screen_label_1, "2026/06/01");
    lv_label_set_long_mode(ui->ui_home_screen_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->ui_home_screen_label_1, 66, 111);
    lv_obj_set_size(ui->ui_home_screen_label_1, 172, 43);

    //Write style for ui_home_screen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ui_home_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_home_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_home_screen_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_home_screen_label_1, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_home_screen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ui_home_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->ui_home_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_home_screen_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_home_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_home_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_home_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ui_home_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_home_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_home_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_home_screen_label_2
    ui->ui_home_screen_label_2 = lv_label_create(ui->ui_home_screen);
    lv_label_set_text(ui->ui_home_screen_label_2, "星期一");
    lv_label_set_long_mode(ui->ui_home_screen_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->ui_home_screen_label_2, 60, 177);
    lv_obj_set_size(ui->ui_home_screen_label_2, 118, 40);

    //Write style for ui_home_screen_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ui_home_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_home_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_home_screen_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_home_screen_label_2, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_home_screen_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ui_home_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->ui_home_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_home_screen_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_home_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_home_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_home_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ui_home_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_home_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_home_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_home_screen_btn_1
    ui->ui_home_screen_btn_1 = lv_btn_create(ui->ui_home_screen);
    lv_obj_add_flag(ui->ui_home_screen_btn_1, LV_OBJ_FLAG_CHECKABLE);
    ui->ui_home_screen_btn_1_label = lv_label_create(ui->ui_home_screen_btn_1);
    lv_label_set_text(ui->ui_home_screen_btn_1_label, "按键1");
    lv_label_set_long_mode(ui->ui_home_screen_btn_1_label, LV_LABEL_LONG_CLIP);
    lv_obj_align(ui->ui_home_screen_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->ui_home_screen_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->ui_home_screen_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->ui_home_screen_btn_1, 529, 118);
    lv_obj_set_size(ui->ui_home_screen_btn_1, 126, 115);

    //Write style for ui_home_screen_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_home_screen_btn_1, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_home_screen_btn_1, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_home_screen_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->ui_home_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_home_screen_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_home_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_home_screen_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_home_screen_btn_1, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_home_screen_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_home_screen_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for ui_home_screen_btn_1, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->ui_home_screen_btn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->ui_home_screen_btn_1, lv_color_hex(0x3b3e40), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->ui_home_screen_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->ui_home_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->ui_home_screen_btn_1, 5, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->ui_home_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->ui_home_screen_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->ui_home_screen_btn_1, &lv_font_ZiTiQuanWeiJunHeiW22_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->ui_home_screen_btn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for ui_home_screen_btn_1, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->ui_home_screen_btn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->ui_home_screen_btn_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->ui_home_screen_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->ui_home_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->ui_home_screen_btn_1, 5, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->ui_home_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->ui_home_screen_btn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->ui_home_screen_btn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->ui_home_screen_btn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for ui_home_screen_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_bg_opa(ui->ui_home_screen_btn_1, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->ui_home_screen_btn_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->ui_home_screen_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->ui_home_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->ui_home_screen_btn_1, 5, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->ui_home_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->ui_home_screen_btn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->ui_home_screen_btn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->ui_home_screen_btn_1, 255, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes ui_home_screen_btn_2
    ui->ui_home_screen_btn_2 = lv_btn_create(ui->ui_home_screen);
    lv_obj_add_flag(ui->ui_home_screen_btn_2, LV_OBJ_FLAG_CHECKABLE);
    ui->ui_home_screen_btn_2_label = lv_label_create(ui->ui_home_screen_btn_2);
    lv_label_set_text(ui->ui_home_screen_btn_2_label, "按键3");
    lv_label_set_long_mode(ui->ui_home_screen_btn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->ui_home_screen_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->ui_home_screen_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->ui_home_screen_btn_2_label, LV_PCT(100));
    lv_obj_set_pos(ui->ui_home_screen_btn_2, 529, 508);
    lv_obj_set_size(ui->ui_home_screen_btn_2, 126, 115);

    //Write style for ui_home_screen_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_home_screen_btn_2, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_home_screen_btn_2, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_home_screen_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->ui_home_screen_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_home_screen_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_home_screen_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_home_screen_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_home_screen_btn_2, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_home_screen_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_home_screen_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_home_screen_btn_3
    ui->ui_home_screen_btn_3 = lv_btn_create(ui->ui_home_screen);
    lv_obj_add_flag(ui->ui_home_screen_btn_3, LV_OBJ_FLAG_CHECKABLE);
    ui->ui_home_screen_btn_3_label = lv_label_create(ui->ui_home_screen_btn_3);
    lv_label_set_text(ui->ui_home_screen_btn_3_label, "按键2");
    lv_label_set_long_mode(ui->ui_home_screen_btn_3_label, LV_LABEL_LONG_CLIP);
    lv_obj_align(ui->ui_home_screen_btn_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->ui_home_screen_btn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->ui_home_screen_btn_3_label, LV_PCT(100));
    lv_obj_set_pos(ui->ui_home_screen_btn_3, 529, 302);
    lv_obj_set_size(ui->ui_home_screen_btn_3, 126, 115);

    //Write style for ui_home_screen_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_home_screen_btn_3, 162, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_home_screen_btn_3, lv_color_hex(0x3a5789), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_home_screen_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->ui_home_screen_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_home_screen_btn_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_home_screen_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_home_screen_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_home_screen_btn_3, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_home_screen_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_home_screen_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_home_screen_cont_1
    ui->ui_home_screen_cont_1 = lv_obj_create(ui->ui_home_screen);
    lv_obj_set_pos(ui->ui_home_screen_cont_1, 0, -430);
    lv_obj_set_size(ui->ui_home_screen_cont_1, 720, 320);
    lv_obj_set_scrollbar_mode(ui->ui_home_screen_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for ui_home_screen_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ui_home_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_home_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_home_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_home_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ui_home_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_home_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_home_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_home_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_home_screen_cont_2
    ui->ui_home_screen_cont_2 = lv_obj_create(ui->ui_home_screen_cont_1);
    lv_obj_set_pos(ui->ui_home_screen_cont_2, 47, 19);
    lv_obj_set_size(ui->ui_home_screen_cont_2, 640, 151);
    lv_obj_set_scrollbar_mode(ui->ui_home_screen_cont_2, LV_SCROLLBAR_MODE_OFF);

    //Write style for ui_home_screen_cont_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ui_home_screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_home_screen_cont_2, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_home_screen_cont_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_home_screen_cont_2, lv_color_hex(0x393939), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_home_screen_cont_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_home_screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ui_home_screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_home_screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_home_screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_home_screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_home_screen_MainSetBtn
    ui->ui_home_screen_MainSetBtn = lv_btn_create(ui->ui_home_screen_cont_2);
    ui->ui_home_screen_MainSetBtn_label = lv_label_create(ui->ui_home_screen_MainSetBtn);
    lv_label_set_text(ui->ui_home_screen_MainSetBtn_label, "");
    lv_label_set_long_mode(ui->ui_home_screen_MainSetBtn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->ui_home_screen_MainSetBtn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->ui_home_screen_MainSetBtn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->ui_home_screen_MainSetBtn_label, LV_PCT(100));
    lv_obj_set_pos(ui->ui_home_screen_MainSetBtn, 28, 25);
    lv_obj_set_size(ui->ui_home_screen_MainSetBtn, 100, 100);

    //Write style for ui_home_screen_MainSetBtn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_home_screen_MainSetBtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_home_screen_MainSetBtn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_home_screen_MainSetBtn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->ui_home_screen_MainSetBtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_home_screen_MainSetBtn, 80, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_home_screen_MainSetBtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_home_screen_MainSetBtn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_home_screen_MainSetBtn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_home_screen_MainSetBtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_home_screen_MainSetBtn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_home_screen_MainSetImg
    ui->ui_home_screen_MainSetImg = lv_img_create(ui->ui_home_screen_cont_2);
    lv_obj_add_flag(ui->ui_home_screen_MainSetImg, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->ui_home_screen_MainSetImg, &_sSetting_alpha_46x46);
    lv_img_set_pivot(ui->ui_home_screen_MainSetImg, 50,50);
    lv_img_set_angle(ui->ui_home_screen_MainSetImg, 0);
    lv_obj_set_pos(ui->ui_home_screen_MainSetImg, 54, 53);
    lv_obj_set_size(ui->ui_home_screen_MainSetImg, 46, 46);

    //Write style for ui_home_screen_MainSetImg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->ui_home_screen_MainSetImg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->ui_home_screen_MainSetImg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_home_screen_MainSetImg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->ui_home_screen_MainSetImg, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_home_screen_btn_4
    ui->ui_home_screen_btn_4 = lv_btn_create(ui->ui_home_screen_cont_2);
    ui->ui_home_screen_btn_4_label = lv_label_create(ui->ui_home_screen_btn_4);
    lv_label_set_text(ui->ui_home_screen_btn_4_label, "");
    lv_label_set_long_mode(ui->ui_home_screen_btn_4_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->ui_home_screen_btn_4_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->ui_home_screen_btn_4, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->ui_home_screen_btn_4_label, LV_PCT(100));
    lv_obj_set_pos(ui->ui_home_screen_btn_4, 190, 25);
    lv_obj_set_size(ui->ui_home_screen_btn_4, 100, 100);

    //Write style for ui_home_screen_btn_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_home_screen_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_home_screen_btn_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_home_screen_btn_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->ui_home_screen_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_home_screen_btn_4, 80, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_home_screen_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_home_screen_btn_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_home_screen_btn_4, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_home_screen_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_home_screen_btn_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_home_screen_btn_5
    ui->ui_home_screen_btn_5 = lv_btn_create(ui->ui_home_screen_cont_2);
    ui->ui_home_screen_btn_5_label = lv_label_create(ui->ui_home_screen_btn_5);
    lv_label_set_text(ui->ui_home_screen_btn_5_label, "");
    lv_label_set_long_mode(ui->ui_home_screen_btn_5_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->ui_home_screen_btn_5_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->ui_home_screen_btn_5, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->ui_home_screen_btn_5_label, LV_PCT(100));
    lv_obj_set_pos(ui->ui_home_screen_btn_5, 350, 25);
    lv_obj_set_size(ui->ui_home_screen_btn_5, 100, 100);

    //Write style for ui_home_screen_btn_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_home_screen_btn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_home_screen_btn_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_home_screen_btn_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->ui_home_screen_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_home_screen_btn_5, 80, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_home_screen_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_home_screen_btn_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_home_screen_btn_5, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_home_screen_btn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_home_screen_btn_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_home_screen_btn_6
    ui->ui_home_screen_btn_6 = lv_btn_create(ui->ui_home_screen_cont_2);
    ui->ui_home_screen_btn_6_label = lv_label_create(ui->ui_home_screen_btn_6);
    lv_label_set_text(ui->ui_home_screen_btn_6_label, "");
    lv_label_set_long_mode(ui->ui_home_screen_btn_6_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->ui_home_screen_btn_6_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->ui_home_screen_btn_6, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->ui_home_screen_btn_6_label, LV_PCT(100));
    lv_obj_set_pos(ui->ui_home_screen_btn_6, 509, 25);
    lv_obj_set_size(ui->ui_home_screen_btn_6, 100, 100);

    //Write style for ui_home_screen_btn_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_home_screen_btn_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_home_screen_btn_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_home_screen_btn_6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->ui_home_screen_btn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_home_screen_btn_6, 80, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_home_screen_btn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_home_screen_btn_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_home_screen_btn_6, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_home_screen_btn_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_home_screen_btn_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_home_screen_img_2
    ui->ui_home_screen_img_2 = lv_img_create(ui->ui_home_screen_cont_2);
    lv_obj_add_flag(ui->ui_home_screen_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->ui_home_screen_img_2, &_sSleep_off_alpha_46x46);
    lv_img_set_pivot(ui->ui_home_screen_img_2, 50,50);
    lv_img_set_angle(ui->ui_home_screen_img_2, 0);
    lv_obj_set_pos(ui->ui_home_screen_img_2, 216, 51);
    lv_obj_set_size(ui->ui_home_screen_img_2, 46, 46);

    //Write style for ui_home_screen_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->ui_home_screen_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->ui_home_screen_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_home_screen_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->ui_home_screen_img_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_home_screen_img_3
    ui->ui_home_screen_img_3 = lv_img_create(ui->ui_home_screen_cont_2);
    lv_obj_add_flag(ui->ui_home_screen_img_3, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->ui_home_screen_img_3, &_sHome_alpha_46x46);
    lv_img_set_pivot(ui->ui_home_screen_img_3, 50,50);
    lv_img_set_angle(ui->ui_home_screen_img_3, 0);
    lv_obj_set_pos(ui->ui_home_screen_img_3, 536, 46);
    lv_obj_set_size(ui->ui_home_screen_img_3, 46, 46);

    //Write style for ui_home_screen_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->ui_home_screen_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->ui_home_screen_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_home_screen_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->ui_home_screen_img_3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_home_screen_img_4
    ui->ui_home_screen_img_4 = lv_img_create(ui->ui_home_screen_cont_2);
    lv_obj_add_flag(ui->ui_home_screen_img_4, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->ui_home_screen_img_4, &_sManual_alpha_46x46);
    lv_img_set_pivot(ui->ui_home_screen_img_4, 50,50);
    lv_img_set_angle(ui->ui_home_screen_img_4, 0);
    lv_obj_set_pos(ui->ui_home_screen_img_4, 377, 51);
    lv_obj_set_size(ui->ui_home_screen_img_4, 46, 46);

    //Write style for ui_home_screen_img_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->ui_home_screen_img_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->ui_home_screen_img_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_home_screen_img_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->ui_home_screen_img_4, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_home_screen_slider_1
    ui->ui_home_screen_slider_1 = lv_slider_create(ui->ui_home_screen_cont_1);
    lv_slider_set_range(ui->ui_home_screen_slider_1, 0, 100);
    lv_slider_set_mode(ui->ui_home_screen_slider_1, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->ui_home_screen_slider_1, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->ui_home_screen_slider_1, 47, 199);
    lv_obj_set_size(ui->ui_home_screen_slider_1, 640, 62);

    //Write style for ui_home_screen_slider_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_home_screen_slider_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_home_screen_slider_1, lv_color_hex(0x393939), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_home_screen_slider_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_home_screen_slider_1, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->ui_home_screen_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_home_screen_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for ui_home_screen_slider_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_home_screen_slider_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_home_screen_slider_1, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_home_screen_slider_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_home_screen_slider_1, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for ui_home_screen_slider_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_home_screen_slider_1, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_home_screen_slider_1, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_home_screen_slider_1, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_home_screen_slider_1, 36, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes ui_home_screen_img_5
    ui->ui_home_screen_img_5 = lv_img_create(ui->ui_home_screen_cont_1);
    lv_obj_add_flag(ui->ui_home_screen_img_5, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->ui_home_screen_img_5, &_sSun_alpha_30x34);
    lv_img_set_pivot(ui->ui_home_screen_img_5, 50,50);
    lv_img_set_angle(ui->ui_home_screen_img_5, 0);
    lv_obj_set_pos(ui->ui_home_screen_img_5, 63, 210);
    lv_obj_set_size(ui->ui_home_screen_img_5, 30, 34);

    //Write style for ui_home_screen_img_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->ui_home_screen_img_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->ui_home_screen_img_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_home_screen_img_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->ui_home_screen_img_5, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of ui_home_screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->ui_home_screen);

    //Init events for screen.
    events_init_ui_home_screen(ui);
}
