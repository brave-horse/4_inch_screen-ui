/**
 *  @file       HWDataAccess.h
 *  @brief      硬件中间层: UI 与 硬件/APP 层之间的数据中转, 解耦 UI 与底层驱动。
 *  @details    界面层通过本文件的接口读写硬件数据/下发控制, 不关心底层实现细节。
 *              各模块用 HW_USE_* 宏开关; 无硬件(纯调 UI)时把 HW_USE_HARDWARE 置 0,
 *              UI 代码不用改。当前只实现色温灯(LightCT), 其余模块后续按需补。
 *
 *  @note       暂存位置: 本中间层原在 demo_ui/Fuc/(Inc+Soc), 因 GUI-Guider 模拟器工程
 *              只编译 GUI_app/custom + generated(见 custom/custom.mk, 头文件 -I 仅 custom/include),
 *              暂移到 custom 下让模拟器也能编译: .h 放 custom/include, .c 放 custom 根。
 *              嵌入式构建(board/wl83/Makefile)同样会编 custom/*.c, 故只能留这一份, 不能在 Fuc 再留一份(否则重复符号)。
 */


#ifndef HWDATAACCESS_H
#define HWDATAACCESS_H

#ifdef __cplusplus
extern "C" {
#endif


/***************************
 *  Hardware Define
 ***************************/

#define HW_USE_HARDWARE 1

#if HW_USE_HARDWARE
  #define HW_Light_CT   0
#endif


/***************************
 *  Includes
 ***************************/

#include "stdint.h"
#include <stdbool.h>

#if HW_Light_CT
  #include "lightct.h"
#endif


/***************************
 *  TypeDefs
 ***************************/

#define LIGHTCT_BRIGHTNESS_MIN   0
#define LIGHTCT_BRIGHTNESS_MAX   100
#define LIGHTCT_COLOR_TEMP_MIN   2700
#define LIGHTCT_COLOR_TEMP_MAX   6500

/**
  * @brief  HW 色温灯(LightCT) Interface definition
  */
typedef struct
{
    bool     switch_status;            // 开关: true 开, false 关(关时按亮度 0 下发, 缓存亮度保留)
    uint16_t brightness;    // 亮度设定值(缓存): LIGHTCT_BRIGHTNESS_MIN..MAX (%)
    uint16_t color_temp;    // 色温设定值(缓存): LIGHTCT_COLOR_TEMP_MIN..MAX (K)
    uint8_t  changed;       // UI 改过未下发=1, 任务下发后清 0

    void (*Init)(void);
    void (*SetOnOff)(bool on);
    void (*SetBrightness)(uint16_t brightness);
    void (*SetColorTemp)(uint16_t color_temp);
    void (*Apply)(void);
} HW_LightCT_InterfaceTypeDef;

/**
  * @brief  Hardware Interface structure definition
  */
typedef struct
{
    HW_LightCT_InterfaceTypeDef LightCT;
} HW_InterfaceTypeDef;


/***************************
 *  External Variables
 ***************************/
extern HW_InterfaceTypeDef HWInterface;


#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*HWDATAACCESS_H*/
