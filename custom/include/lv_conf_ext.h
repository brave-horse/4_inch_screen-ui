/*
* Copyright 2023 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

/*
 * lv_conf_ext.h for custom lvconf file.
 * Created on: Feb 8, 2023
 * example :
 *	#undef LV_FONT_FMT_TXT_LARGE
 *  #define LV_FONT_FMT_TXT_LARGE 1
 */

#ifndef LV_CONF_EXT_H
#define LV_CONF_EXT_H


/* common code  begin  */

/* 重绘区域可视化诊断：开启后每次刷屏会用半透明红色高亮被重绘的区域，
 * 用于排查"哪里在持续触发重绘"。**调试用，问题查清后记得关掉**。 */
#undef LV_USE_REFR_DEBUG
#define LV_USE_REFR_DEBUG 0

/* common code end */


#if LV_USE_GUIDER_SIMULATOR
/* code for simulator begin  */


/* code for simulator end */
#else
/* code for board begin */


/* code for board end */
#endif



#endif  /* LV_CONF_EXT_H */
