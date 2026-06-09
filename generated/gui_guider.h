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
	lv_obj_t *device_management_screen_sdev_on;
	lv_obj_t *device_management_screen_small_dev_off_img;
	lv_obj_t *device_management_screen_label_2;
	lv_obj_t *device_management_screen_cont_2;
	lv_obj_t *device_management_screen_sLEDStripOn;
	lv_obj_t *device_management_screen_sLEDStripOff;
	lv_obj_t *device_management_screen_sLSimgbtn;
	lv_obj_t *device_management_screen_sLSimgbtn_label;
	lv_obj_t *device_management_screen_label_3;
	lv_obj_t *device_management_screen_cont_3;
	lv_obj_t *device_management_screen_sMagLightOn;
	lv_obj_t *device_management_screen_sMagLightOff;
	lv_obj_t *device_management_screen_sMagimgbtn;
	lv_obj_t *device_management_screen_sMagimgbtn_label;
	lv_obj_t *device_management_screen_label_4;
	lv_obj_t *device_management_screen_cont_4;
	lv_obj_t *device_management_screen_sRGBLightOn;
	lv_obj_t *device_management_screen_sRGBLightOff;
	lv_obj_t *device_management_screen_sRGBLightBtn;
	lv_obj_t *device_management_screen_sRGBLightBtn_label;
	lv_obj_t *device_management_screen_label_5;
	lv_obj_t *device_management_screen_cont_5;
	lv_obj_t *device_management_screen_sFabricCurtainOn;
	lv_obj_t *device_management_screen_sFabricCurtianOff;
	lv_obj_t *device_management_screen_label_6;
	lv_obj_t *device_management_screen_sFabricCurClose;
	lv_obj_t *device_management_screen_sFabricCurOpen;
	lv_obj_t *device_management_screen_cont_6;
	lv_obj_t *device_management_screen_sSheersOn;
	lv_obj_t *device_management_screen_sSheersOff;
	lv_obj_t *device_management_screen_label_7;
	lv_obj_t *device_management_screen_sSheerOpen;
	lv_obj_t *device_management_screen_sSheerClose;
	lv_obj_t *device_management_screen_cont_7;
	lv_obj_t *device_management_screen_sRollBlindOn;
	lv_obj_t *device_management_screen_sRollBlindOff;
	lv_obj_t *device_management_screen_label_8;
	lv_obj_t *device_management_screen_sRollBlindDown;
	lv_obj_t *device_management_screen_sRollBlindUp;
	lv_obj_t *device_management_screen_cont_8;
	lv_obj_t *device_management_screen_sDreamOn;
	lv_obj_t *device_management_screen_sDreamOff;
	lv_obj_t *device_management_screen_label_10;
	lv_obj_t *device_management_screen_sDreamClose;
	lv_obj_t *device_management_screen_sDreamOpen;
	lv_obj_t *device_management_screen_cont_9;
	lv_obj_t *device_management_screen_img_12;
	lv_obj_t *device_management_screen_imgbtn_6;
	lv_obj_t *device_management_screen_imgbtn_6_label;
	lv_obj_t *device_management_screen_label_9;
	lv_obj_t *device_management_screen_cont_10;
	lv_obj_t *device_management_screen_img_18;
	lv_obj_t *device_management_screen_img_17;
	lv_obj_t *device_management_screen_imgbtn_9;
	lv_obj_t *device_management_screen_imgbtn_9_label;
	lv_obj_t *device_management_screen_label_12;
	lv_obj_t *device_management_screen_cont_11;
	lv_obj_t *device_management_screen_sDryRackdown;
	lv_obj_t *device_management_screen_sDryRackup;
	lv_obj_t *device_management_screen_label_11;
	lv_obj_t *device_management_screen_sDryRackDown;
	lv_obj_t *device_management_screen_sDryRackUp;
	lv_obj_t *device_management_screen_cont_12;
	lv_obj_t *device_management_screen_img_22;
	lv_obj_t *device_management_screen_img_21;
	lv_obj_t *device_management_screen_imgbtn_11;
	lv_obj_t *device_management_screen_imgbtn_11_label;
	lv_obj_t *device_management_screen_label_14;
	lv_obj_t *device_management_screen_cont_13;
	lv_obj_t *device_management_screen_img_20;
	lv_obj_t *device_management_screen_img_19;
	lv_obj_t *device_management_screen_imgbtn_10;
	lv_obj_t *device_management_screen_imgbtn_10_label;
	lv_obj_t *device_management_screen_label_13;
	lv_obj_t *device_management_screen_label_1;
	lv_obj_t *device_management_screen_label_15;
	lv_obj_t *device_management_screen_label_16;
	lv_obj_t *device_management_screen_img_23;
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
	lv_obj_t *light_CT_screen_ct_bar;
	lv_obj_t *light_CT_screen_slider_2;
	lv_obj_t *light_CT_screen_slider_1;
	lv_obj_t *light_CT_screen_label_1;
	lv_obj_t *light_CT_screen_dev_shell_img;
	lv_obj_t *light_CT_screen_white_lid;
	lv_obj_t *light_CT_screen_dev_orange_img;
	lv_obj_t *light_CT_screen_dev_white_img;
	lv_obj_t *light_CT_screen_imgbtn_1;
	lv_obj_t *light_CT_screen_imgbtn_1_label;
	lv_obj_t *light_CT_screen_btn_1;
	lv_obj_t *light_CT_screen_btn_1_label;
	lv_obj_t *light_CT_screen_on_off_2_img;
	lv_obj_t *light_CT_screen_on_off_2_img_label;
	lv_obj_t *LedStrip;
	bool LedStrip_del;
	lv_obj_t *LedStrip_tabview_1;
	lv_obj_t *LedStrip_tabview_1_tab_1;
	lv_obj_t *LedStrip_cont_1;
	lv_obj_t *LedStrip_label_2;
	lv_obj_t *LedStrip_ct_bar;
	lv_obj_t *LedStrip_slider_2;
	lv_obj_t *LedStrip_slider_1;
	lv_obj_t *LedStrip_label_1;
	lv_obj_t *LedStrip_imgbtn_1;
	lv_obj_t *LedStrip_imgbtn_1_label;
	lv_obj_t *LedStrip_btn_1;
	lv_obj_t *LedStrip_btn_1_label;
	lv_obj_t *LedStrip_on_off_2_img;
	lv_obj_t *LedStrip_on_off_2_img_label;
	lv_obj_t *LedStrip_LSOn;
	lv_obj_t *LedStrip_LSOff;
	lv_obj_t *MagLight;
	bool MagLight_del;
	lv_obj_t *MagLight_tabview_1;
	lv_obj_t *MagLight_tabview_1_tab_1;
	lv_obj_t *MagLight_cont_1;
	lv_obj_t *MagLight_label_2;
	lv_obj_t *MagLight_ct_bar;
	lv_obj_t *MagLight_slider_2;
	lv_obj_t *MagLight_slider_1;
	lv_obj_t *MagLight_label_1;
	lv_obj_t *MagLight_imgbtn_1;
	lv_obj_t *MagLight_imgbtn_1_label;
	lv_obj_t *MagLight_btn_1;
	lv_obj_t *MagLight_btn_1_label;
	lv_obj_t *MagLight_on_off_2_img;
	lv_obj_t *MagLight_on_off_2_img_label;
	lv_obj_t *MagLight_MagPole;
	lv_obj_t *MagLight_Orange;
	lv_obj_t *MagLight_white;
	lv_obj_t *RGBLight;
	bool RGBLight_del;
	lv_obj_t *RGBLight_tabview_1;
	lv_obj_t *RGBLight_tabview_1_tab_1;
	lv_obj_t *RGBLight_cont_1;
	lv_obj_t *RGBLight_label_2;
	lv_obj_t *RGBLight_ct_bar;
	lv_obj_t *RGBLight_slider_2;
	lv_obj_t *RGBLight_slider_1;
	lv_obj_t *RGBLight_label_1;
	lv_obj_t *RGBLight_imgbtn_1;
	lv_obj_t *RGBLight_imgbtn_1_label;
	lv_obj_t *RGBLight_btn_1;
	lv_obj_t *RGBLight_btn_1_label;
	lv_obj_t *RGBLight_on_off_2_img;
	lv_obj_t *RGBLight_on_off_2_img_label;
	lv_obj_t *RGBLight_RGBCover;
	lv_obj_t *RGBLight_Blue;
	lv_obj_t *RGBLight_Red;
	lv_obj_t *RGBLight_Green;
	lv_obj_t *FabricCurtian;
	bool FabricCurtian_del;
	lv_obj_t *FabricCurtian_tabview_1;
	lv_obj_t *FabricCurtian_tabview_1_tab_1;
	lv_obj_t *FabricCurtian_cont_1;
	lv_obj_t *FabricCurtian_btn_1;
	lv_obj_t *FabricCurtian_btn_1_label;
	lv_obj_t *FabricCurtian_FabCurtianOpen;
	lv_obj_t *FabricCurtian_FabCurtianClose;
	lv_obj_t *FabricCurtian_FabCurtianPause;
	lv_obj_t *FabricCurtian_FabCurtianBg1;
	lv_obj_t *FabricCurtian_FabCurtianBg3;
	lv_obj_t *FabricCurtian_FabCurtianBg2;
	lv_obj_t *FabricCurtian_FabCurtianLeft;
	lv_obj_t *FabricCurtian_FabCurtianright;
	lv_obj_t *FabricCurtian_cont_2;
	lv_obj_t *FabricCurtian_cont_3;
	lv_obj_t *FabricCurtian_FabCurtianPull2;
	lv_obj_t *FabricCurtian_FabCurtianPull1;
	lv_obj_t *FabricCurtian_FabCurtianPole;
	lv_obj_t *FabricCurtian_label_1;
	lv_obj_t *Sheers;
	bool Sheers_del;
	lv_obj_t *Sheers_tabview_1;
	lv_obj_t *Sheers_tabview_1_tab_1;
	lv_obj_t *Sheers_cont_1;
	lv_obj_t *Sheers_btn_1;
	lv_obj_t *Sheers_btn_1_label;
	lv_obj_t *Sheers_FabCurtianOpen;
	lv_obj_t *Sheers_FabCurtianClose;
	lv_obj_t *Sheers_FabCurtianPause;
	lv_obj_t *Sheers_FabCurtianBg1;
	lv_obj_t *Sheers_FabCurtianBg3;
	lv_obj_t *Sheers_FabCurtianBg2;
	lv_obj_t *Sheers_FabCurtianLeft;
	lv_obj_t *Sheers_FabCurtianright;
	lv_obj_t *Sheers_cont_2;
	lv_obj_t *Sheers_cont_3;
	lv_obj_t *Sheers_FabCurtianPull2;
	lv_obj_t *Sheers_FabCurtianPull1;
	lv_obj_t *Sheers_FabCurtianPole;
	lv_obj_t *RollBlind;
	bool RollBlind_del;
	lv_obj_t *RollBlind_tabview_1;
	lv_obj_t *RollBlind_tabview_1_tab_1;
	lv_obj_t *RollBlind_cont_1;
	lv_obj_t *RollBlind_FabCurtianOpen;
	lv_obj_t *RollBlind_FabCurtianClose;
	lv_obj_t *RollBlind_cont_2;
	lv_obj_t *RollBlind_FabCurtianPause;
	lv_obj_t *RollBlind_FabCurtianBg1;
	lv_obj_t *RollBlind_FabCurtianBg3;
	lv_obj_t *RollBlind_FabCurtianBg2;
	lv_obj_t *RollBlind_FabCurtianLeft;
	lv_obj_t *RollBlind_cont_3;
	lv_obj_t *RollBlind_cont_4;
	lv_obj_t *RollBlind_FabCurtianPull1;
	lv_obj_t *RollBlind_RollBlindPole;
	lv_obj_t *RollBlind_btn_1;
	lv_obj_t *RollBlind_btn_1_label;
	lv_obj_t *Dream;
	bool Dream_del;
	lv_obj_t *Dream_tabview_1;
	lv_obj_t *Dream_tabview_1_tab_1;
	lv_obj_t *Dream_cont_1;
	lv_obj_t *Dream_btn_1;
	lv_obj_t *Dream_btn_1_label;
	lv_obj_t *Dream_FabCurtianOpen;
	lv_obj_t *Dream_FabCurtianClose;
	lv_obj_t *Dream_FabCurtianPause;
	lv_obj_t *Dream_FabCurtianBg1;
	lv_obj_t *Dream_FabCurtianBg3;
	lv_obj_t *Dream_FabCurtianBg2;
	lv_obj_t *Dream_FabCurtianLeft;
	lv_obj_t *Dream_FabCurtianright;
	lv_obj_t *Dream_FabCurtianPull2;
	lv_obj_t *Dream_FabCurtianPull1;
	lv_obj_t *Dream_FabCurtianPole;
	lv_obj_t *Dream_slider_1;
	lv_obj_t *Dream_label_1;
	lv_obj_t *Dream_label_2;
	lv_obj_t *Dream_label_3;
	lv_obj_t *Dream_label_4;
	lv_obj_t *AirCondition;
	bool AirCondition_del;
	lv_obj_t *AirCondition_tabview_1;
	lv_obj_t *AirCondition_tabview_1_tab_1;
	lv_obj_t *AirCondition_cont_1;
	lv_obj_t *AirCondition_btn_1;
	lv_obj_t *AirCondition_btn_1_label;
	lv_obj_t *AirCondition_ACDry;
	lv_obj_t *AirCondition_ACSpeedAuto;
	lv_obj_t *AirCondition_FabCurtianLeft;
	lv_obj_t *AirCondition_AcSpd1;
	lv_obj_t *AirCondition_ACBtn;
	lv_obj_t *AirCondition_ACBtn_label;
	lv_obj_t *AirCondition_ACSpeed1;
	lv_obj_t *AirCondition_ACSpeed2;
	lv_obj_t *AirCondition_ACSpeed3;
	lv_obj_t *AirCondition_ACSpeed4;
	lv_obj_t *AirCondition_AcCool;
	lv_obj_t *AirCondition_ACFan;
	lv_obj_t *AirCondition_ACHot;
	lv_obj_t *AirCondition_AcSpd2;
	lv_obj_t *AirCondition_AcSpd3;
	lv_obj_t *Music;
	bool Music_del;
	lv_obj_t *Music_tabview_1;
	lv_obj_t *Music_tabview_1_tab_1;
	lv_obj_t *Music_cont_1;
	lv_obj_t *Music_btn_1;
	lv_obj_t *Music_btn_1_label;
	lv_obj_t *Music_FabCurtianOpen;
	lv_obj_t *Music_FabCurtianClose;
	lv_obj_t *Music_cont_2;
	lv_obj_t *Music_FabCurtianPause;
	lv_obj_t *Music_FabCurtianBg1;
	lv_obj_t *Music_FabCurtianBg3;
	lv_obj_t *Music_FabCurtianBg2;
	lv_obj_t *Music_FabCurtianLeft;
	lv_obj_t *Music_FabCurtianPull1;
	lv_obj_t *Music_RollBlindPole;
	lv_obj_t *DryRack;
	bool DryRack_del;
	lv_obj_t *DryRack_tabview_1;
	lv_obj_t *DryRack_tabview_1_tab_1;
	lv_obj_t *DryRack_cont_1;
	lv_obj_t *DryRack_btn_1;
	lv_obj_t *DryRack_btn_1_label;
	lv_obj_t *DryRack_FabCurtianOpen;
	lv_obj_t *DryRack_FabCurtianClose;
	lv_obj_t *DryRack_FabCurtianPause;
	lv_obj_t *DryRack_img_1;
	lv_obj_t *DryRack_imgbtn_1;
	lv_obj_t *DryRack_imgbtn_1_label;
	lv_obj_t *DryRack_img_2;
	lv_obj_t *DryRack_label_1;
	lv_obj_t *DryRack_RollBlindPole;
	lv_obj_t *FanLight;
	bool FanLight_del;
	lv_obj_t *FanLight_tabview_1;
	lv_obj_t *FanLight_tabview_1_tab_1;
	lv_obj_t *FanLight_cont_1;
	lv_obj_t *FanLight_btn_1;
	lv_obj_t *FanLight_btn_1_label;
	lv_obj_t *FanLight_FabCurtianOpen;
	lv_obj_t *FanLight_FabCurtianClose;
	lv_obj_t *FanLight_cont_2;
	lv_obj_t *FanLight_FabCurtianPause;
	lv_obj_t *FanLight_FabCurtianBg1;
	lv_obj_t *FanLight_FabCurtianBg3;
	lv_obj_t *FanLight_FabCurtianBg2;
	lv_obj_t *FanLight_FabCurtianLeft;
	lv_obj_t *FanLight_FabCurtianPull1;
	lv_obj_t *FanLight_RollBlindPole;
	lv_obj_t *Heater;
	bool Heater_del;
	lv_obj_t *Heater_tabview_1;
	lv_obj_t *Heater_tabview_1_tab_1;
	lv_obj_t *Heater_cont_1;
	lv_obj_t *Heater_btn_1;
	lv_obj_t *Heater_btn_1_label;
	lv_obj_t *Heater_FabCurtianOpen;
	lv_obj_t *Heater_FabCurtianClose;
	lv_obj_t *Heater_cont_2;
	lv_obj_t *Heater_FabCurtianPause;
	lv_obj_t *Heater_FabCurtianBg1;
	lv_obj_t *Heater_FabCurtianBg3;
	lv_obj_t *Heater_FabCurtianBg2;
	lv_obj_t *Heater_FabCurtianLeft;
	lv_obj_t *Heater_FabCurtianPull1;
	lv_obj_t *Heater_RollBlindPole;
	lv_obj_t *screen_1;
	bool screen_1_del;
	lv_obj_t *screen_1_tabview_1;
	lv_obj_t *screen_1_tabview_1_tab_1;
	lv_obj_t *screen_1_cont_1;
	lv_obj_t *screen_1_label_2;
	lv_obj_t *screen_1_ct_bar;
	lv_obj_t *screen_1_slider_2;
	lv_obj_t *screen_1_slider_1;
	lv_obj_t *screen_1_label_1;
	lv_obj_t *screen_1_imgbtn_1;
	lv_obj_t *screen_1_imgbtn_1_label;
	lv_obj_t *screen_1_btn_1;
	lv_obj_t *screen_1_btn_1_label;
	lv_obj_t *screen_1_on_off_2_img;
	lv_obj_t *screen_1_on_off_2_img_label;
	lv_obj_t *screen_1_Orange;
	lv_obj_t *screen_1_white;
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
void setup_scr_setting_screen(lv_ui *ui);
void setup_scr_light_CT_screen(lv_ui *ui);
void setup_scr_LedStrip(lv_ui *ui);
void setup_scr_MagLight(lv_ui *ui);
void setup_scr_RGBLight(lv_ui *ui);
void setup_scr_FabricCurtian(lv_ui *ui);
void setup_scr_Sheers(lv_ui *ui);
void setup_scr_RollBlind(lv_ui *ui);
void setup_scr_Dream(lv_ui *ui);
void setup_scr_AirCondition(lv_ui *ui);
void setup_scr_Music(lv_ui *ui);
void setup_scr_DryRack(lv_ui *ui);
void setup_scr_FanLight(lv_ui *ui);
void setup_scr_Heater(lv_ui *ui);
void setup_scr_screen_1(lv_ui *ui);
LV_IMG_DECLARE(_sLedStripOn_alpha_65x43);
LV_IMG_DECLARE(_sLedStripOff_alpha_65x43);
LV_IMG_DECLARE(_sLedStripOn_alpha_65x43);
LV_IMG_DECLARE(_sLedStripOff_alpha_65x43);
LV_IMG_DECLARE(_sLedStripOn_alpha_65x43);
LV_IMG_DECLARE(_sLedStripOff_alpha_65x43);
LV_IMG_DECLARE(_MagPole_alpha_453x13);
LV_IMG_DECLARE(_RollBlindUp_alpha_94x95);
LV_IMG_DECLARE(_RollBlindDown_alpha_94x95);
LV_IMG_DECLARE(_FabCurtianPause_alpha_95x95);
LV_IMG_DECLARE(_FabCurtianBg1_alpha_62x60);
LV_IMG_DECLARE(_FabCurtianBg3_alpha_42x14);
LV_IMG_DECLARE(_FabCurtianBg2_alpha_34x73);
LV_IMG_DECLARE(_RollBlindCloth_alpha_435x353);
LV_IMG_DECLARE(_CurtainPull_alpha_39x39);
LV_IMG_DECLARE(_RollBlindPole_alpha_462x26);
LV_IMG_DECLARE(_RollBlindUp_alpha_94x95);
LV_IMG_DECLARE(_RollBlindDown_alpha_94x95);
LV_IMG_DECLARE(_FabCurtianPause_alpha_109x110);
LV_IMG_DECLARE(_FabCurtianBg1_alpha_62x60);
LV_IMG_DECLARE(_FabCurtianBg3_alpha_42x14);
LV_IMG_DECLARE(_FabCurtianBg2_alpha_34x73);
LV_IMG_DECLARE(_RollBlindCloth_alpha_435x353);
LV_IMG_DECLARE(_CurtainPull_alpha_39x39);
LV_IMG_DECLARE(_RollBlindPole_alpha_462x26);
LV_IMG_DECLARE(_RollBlindUp_alpha_94x95);
LV_IMG_DECLARE(_RollBlindDown_alpha_94x95);
LV_IMG_DECLARE(_FabCurtianPause_alpha_109x110);
LV_IMG_DECLARE(_FabCurtianBg1_alpha_62x60);
LV_IMG_DECLARE(_FabCurtianBg3_alpha_42x14);
LV_IMG_DECLARE(_FabCurtianBg2_alpha_34x73);
LV_IMG_DECLARE(_RollBlindCloth_alpha_435x353);
LV_IMG_DECLARE(_CurtainPull_alpha_39x39);
LV_IMG_DECLARE(_RollBlindPole_alpha_462x26);

LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_30)
LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_16)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_12)
LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_20)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_24)


#ifdef __cplusplus
}
#endif
#endif
