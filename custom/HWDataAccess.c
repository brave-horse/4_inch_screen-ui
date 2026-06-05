/**
 *  @file   HWDataAccess.c
 *  @brief  硬件中间层实现, 当前: 色温灯(LightCT)。
 *
 *  @note   位置说明见 include/HWDataAccess.h 文件头: 暂从 demo_ui/Fuc 移到 custom 下,
 *          让 GUI-Guider 模拟器(只编 custom+generated)也能链接到 HWInterface。
 */

#include <stdio.h>
#include "HWDataAccess.h"


/***************************
 *  色温灯 LightCT Functions
 ***************************/

/** 把 value 限制到 [min_val, max_val]。 */
static uint16_t LightCT_Clamp(uint16_t value, uint16_t min_val, uint16_t max_val)
{
    if (value < min_val) {
        return min_val;
    }
    if (value > max_val) {
        return max_val;
    }
    return value;
}

/** 色温灯硬件初始化(HW_Light_CT 关时为空操作)。 */
void HW_LightCT_Init(void)
{
#if HW_Light_CT
    LightCT_Init();
#endif
}

/**
 * 开关灯(UI 调用): 有变化则置 changed。
 * @param on true 开, false 关
 */
void HW_LightCT_SetOnOff(bool on)
{
    if (HWInterface.LightCT.switch_status != on) {
        HWInterface.LightCT.switch_status = on;
        HWInterface.LightCT.changed = 1;
    }
}

/**
 * 设置亮度(UI 调用): clamp 后缓存, 有变化则置 changed。
 * @param brightness 亮度(%), LIGHTCT_BRIGHTNESS_MIN..MAX
 */
void HW_LightCT_SetBrightness(uint16_t brightness)
{
    brightness = LightCT_Clamp(brightness, LIGHTCT_BRIGHTNESS_MIN, LIGHTCT_BRIGHTNESS_MAX);
    if (HWInterface.LightCT.brightness != brightness) {
        HWInterface.LightCT.brightness = brightness;
        HWInterface.LightCT.changed = 1;
    }
}

/**
 * 设置色温(UI 调用): clamp 后缓存, 有变化则置 changed。
 * @param color_temp 色温(K), LIGHTCT_COLOR_TEMP_MIN..MAX
 */
void HW_LightCT_SetColorTemp(uint16_t color_temp)
{
    color_temp = LightCT_Clamp(color_temp, LIGHTCT_COLOR_TEMP_MIN, LIGHTCT_COLOR_TEMP_MAX);
    if (HWInterface.LightCT.color_temp != color_temp) {
        HWInterface.LightCT.color_temp = color_temp;
        HWInterface.LightCT.changed = 1;
    }
}

/** 把缓存的开关/亮度/色温下发硬件(任务调用); 无硬件时打印占位。关灯按亮度 0 下发。 */
void HW_LightCT_Apply(void)
{
    uint16_t brightness = HWInterface.LightCT.switch_status ? HWInterface.LightCT.brightness : 0;
#if HW_Light_CT
    LightCT_Set(brightness, HWInterface.LightCT.color_temp);
#else
    printf("[LightCT] -> HW  on=%d  brightness=%d%%  color_temp=%dK\n",
           HWInterface.LightCT.switch_status, brightness, HWInterface.LightCT.color_temp);
#endif
}


/***************************
 *  External Variables
 ***************************/
HW_InterfaceTypeDef HWInterface = {
    .LightCT = {
        .switch_status = true,   //开关: 默认关
        .brightness = 50,
        .color_temp = 4600,
        .changed = 0,        //是否变化
        .Init = HW_LightCT_Init,
        .SetOnOff = HW_LightCT_SetOnOff,
        .SetBrightness = HW_LightCT_SetBrightness,
        .SetColorTemp = HW_LightCT_SetColorTemp,
        .Apply = HW_LightCT_Apply,
    },
};
