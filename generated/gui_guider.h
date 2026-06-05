/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *ui_home_screen;
	bool ui_home_screen_del;
	lv_obj_t *ui_home_screen_img_1;
	lv_obj_t *ui_home_screen_digital_clock_1;
	lv_obj_t *ui_home_screen_label_1;
	lv_obj_t *ui_home_screen_label_2;
	lv_obj_t *ui_home_screen_btn_1;
	lv_obj_t *ui_home_screen_btn_1_label;
	lv_obj_t *ui_home_screen_btn_2;
	lv_obj_t *ui_home_screen_btn_2_label;
	lv_obj_t *ui_home_screen_btn_3;
	lv_obj_t *ui_home_screen_btn_3_label;
	lv_obj_t *ui_home_screen_cont_1;
	lv_obj_t *device_management_screen;
	bool device_management_screen_del;
	lv_obj_t *device_management_screen_tabview_1;
	lv_obj_t *device_management_screen_tabview_1_tab_1;
	lv_obj_t *device_management_screen_cont_1;
	lv_obj_t *device_management_screen_Light_CT_on_off_1_img;
	lv_obj_t *device_management_screen_Light_CT_on_off_1_img_label;
	lv_obj_t *device_management_screen_small_dev_on_img;
	lv_obj_t *device_management_screen_small_dev_off_img;
	lv_obj_t *device_management_screen_label_2;
	lv_obj_t *device_management_screen_btn_4;
	lv_obj_t *device_management_screen_btn_4_label;
	lv_obj_t *device_management_screen_btn_3;
	lv_obj_t *device_management_screen_btn_3_label;
	lv_obj_t *device_management_screen_btn_6;
	lv_obj_t *device_management_screen_btn_6_label;
	lv_obj_t *device_management_screen_btn_5;
	lv_obj_t *device_management_screen_btn_5_label;
	lv_obj_t *device_management_screen_btn_8;
	lv_obj_t *device_management_screen_btn_8_label;
	lv_obj_t *device_management_screen_btn_7;
	lv_obj_t *device_management_screen_btn_7_label;
	lv_obj_t *device_management_screen_btn_9;
	lv_obj_t *device_management_screen_btn_9_label;
	lv_obj_t *device_management_screen_btn_10;
	lv_obj_t *device_management_screen_btn_10_label;
	lv_obj_t *device_management_screen_cont_2;
	lv_obj_t *device_management_screen_label_1;
	lv_obj_t *light_scence_screen;
	bool light_scence_screen_del;
	lv_obj_t *light_scence_screen_tabview_1;
	lv_obj_t *light_scence_screen_tabview_1_tab_1;
	lv_obj_t *light_scence_screen_btn_10;
	lv_obj_t *light_scence_screen_btn_10_label;
	lv_obj_t *light_scence_screen_btn_9;
	lv_obj_t *light_scence_screen_btn_9_label;
	lv_obj_t *light_scence_screen_btn_8;
	lv_obj_t *light_scence_screen_btn_8_label;
	lv_obj_t *light_scence_screen_btn_7;
	lv_obj_t *light_scence_screen_btn_7_label;
	lv_obj_t *light_scence_screen_btn_6;
	lv_obj_t *light_scence_screen_btn_6_label;
	lv_obj_t *light_scence_screen_btn_5;
	lv_obj_t *light_scence_screen_btn_5_label;
	lv_obj_t *light_scence_screen_btn_4;
	lv_obj_t *light_scence_screen_btn_4_label;
	lv_obj_t *light_scence_screen_btn_3;
	lv_obj_t *light_scence_screen_btn_3_label;
	lv_obj_t *light_scence_screen_btn_2;
	lv_obj_t *light_scence_screen_btn_2_label;
	lv_obj_t *light_scence_screen_btn_1;
	lv_obj_t *light_scence_screen_btn_1_label;
	lv_obj_t *light_scence_screen_label_1;
	lv_obj_t *curtain_scene_screen;
	bool curtain_scene_screen_del;
	lv_obj_t *curtain_scene_screen_tabview_1;
	lv_obj_t *curtain_scene_screen_tabview_1_tab_1;
	lv_obj_t *curtain_scene_screen_btn_10;
	lv_obj_t *curtain_scene_screen_btn_10_label;
	lv_obj_t *curtain_scene_screen_btn_9;
	lv_obj_t *curtain_scene_screen_btn_9_label;
	lv_obj_t *curtain_scene_screen_btn_8;
	lv_obj_t *curtain_scene_screen_btn_8_label;
	lv_obj_t *curtain_scene_screen_btn_7;
	lv_obj_t *curtain_scene_screen_btn_7_label;
	lv_obj_t *curtain_scene_screen_btn_6;
	lv_obj_t *curtain_scene_screen_btn_6_label;
	lv_obj_t *curtain_scene_screen_btn_5;
	lv_obj_t *curtain_scene_screen_btn_5_label;
	lv_obj_t *curtain_scene_screen_btn_4;
	lv_obj_t *curtain_scene_screen_btn_4_label;
	lv_obj_t *curtain_scene_screen_btn_3;
	lv_obj_t *curtain_scene_screen_btn_3_label;
	lv_obj_t *curtain_scene_screen_btn_2;
	lv_obj_t *curtain_scene_screen_btn_2_label;
	lv_obj_t *curtain_scene_screen_btn_1;
	lv_obj_t *curtain_scene_screen_btn_1_label;
	lv_obj_t *curtain_scene_screen_label_1;
	lv_obj_t *setting_screen;
	bool setting_screen_del;
	lv_obj_t *setting_screen_tabview_1;
	lv_obj_t *setting_screen_tabview_1_tab_1;
	lv_obj_t *setting_screen_list_1;
	lv_obj_t *setting_screen_list_1_item0;
	lv_obj_t *setting_screen_list_1_item1;
	lv_obj_t *setting_screen_list_1_item2;
	lv_obj_t *setting_screen_list_1_item3;
	lv_obj_t *setting_screen_list_1_item4;
	lv_obj_t *setting_screen_list_1_item5;
	lv_obj_t *setting_screen_list_1_item6;
	lv_obj_t *setting_screen_btn_1;
	lv_obj_t *setting_screen_btn_1_label;
	lv_obj_t *light_CT_screen;
	bool light_CT_screen_del;
	lv_obj_t *light_CT_screen_tabview_1;
	lv_obj_t *light_CT_screen_tabview_1_tab_1;
	lv_obj_t *light_CT_screen_cont_1;
	lv_obj_t *light_CT_screen_label_2;
	lv_obj_t *light_CT_screen_slider_2;
	lv_obj_t *light_CT_screen_slider_1;
	lv_obj_t *light_CT_screen_label_1;
	lv_obj_t *light_CT_screen_dev_shell_img;
	lv_obj_t *light_CT_screen_dev_white_lid;
	lv_obj_t *light_CT_screen_dev_orange_img;
	lv_obj_t *light_CT_screen_dev_white_img;
	lv_obj_t *light_CT_screen_imgbtn_1;
	lv_obj_t *light_CT_screen_imgbtn_1_label;
	lv_obj_t *light_CT_screen_btn_1;
	lv_obj_t *light_CT_screen_btn_1_label;
	lv_obj_t *light_CT_screen_on_off_2_img;
	lv_obj_t *light_CT_screen_on_off_2_img_label;
	lv_obj_t *screen_6;
	bool screen_6_del;
	lv_obj_t *screen_6_btn_1;
	lv_obj_t *screen_6_btn_1_label;
	lv_obj_t *screen_6_btn_2;
	lv_obj_t *screen_6_btn_2_label;
	lv_obj_t *screen_6_btn_3;
	lv_obj_t *screen_6_btn_3_label;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_ui_home_screen(lv_ui *ui);
void setup_scr_device_management_screen(lv_ui *ui);
void setup_scr_light_scence_screen(lv_ui *ui);
void setup_scr_curtain_scene_screen(lv_ui *ui);
void setup_scr_setting_screen(lv_ui *ui);
void setup_scr_light_CT_screen(lv_ui *ui);
void setup_scr_screen_6(lv_ui *ui);

LV_IMG_DECLARE(_ct_bar_600x70);
LV_IMG_DECLARE(_dev_shell_alpha_100x100);
LV_IMG_DECLARE(_dev_white_lid_alpha_174x27);
LV_IMG_DECLARE(_dev_orange_alpha_280x80);
LV_IMG_DECLARE(_dev_white_alpha_280x80);
LV_IMG_DECLARE(_scene_btn_alpha_48x48);
LV_IMG_DECLARE(_scene_btn_close_alpha_48x48);
LV_IMG_DECLARE(_onoff_off_alpha_48x48);
LV_IMG_DECLARE(_onoff_on_alpha_48x48);

LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_30)
LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_16)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_12)
LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_20)
LV_FONT_DECLARE(lv_font_montserratMedium_16)


#ifdef __cplusplus
}
#endif
#endif
