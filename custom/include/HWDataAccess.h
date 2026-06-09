#ifndef HWDATAACCESS_H
#define HWDATAACCESS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"
#include <stdbool.h>

#define LIGHTCT_BRIGHTNESS_MIN   0
#define LIGHTCT_BRIGHTNESS_MAX   100
#define LIGHTCT_COLOR_TEMP_MIN   2700
#define LIGHTCT_COLOR_TEMP_MAX   6500

#define CURTAIN_COUNT_MAX        10
#define CURTAIN_POS_MIN          0
#define CURTAIN_POS_MAX          100

typedef struct
{
    bool     switch_status;
    uint16_t brightness;
    uint16_t color_temp;

    void (*SetOnOff)(bool on);
    void (*SetBrightness)(uint16_t brightness);
    void (*SetColorTemp)(uint16_t color_temp);
    void (*Apply)(void);
} HW_LightCT_InterfaceTypeDef;

typedef struct
{
    bool     switch_status;
    uint16_t brightness;
    uint16_t color_temp;

    void (*SetOnOff)(bool on);
    void (*SetBrightness)(uint16_t brightness);
    void (*SetColorTemp)(uint16_t color_temp);
    void (*Apply)(void);
} HW_LEDStrip_InterfaceTypeDef;

typedef struct
{
    bool     switch_status;
    uint16_t position;

    void (*SetOnOff)(uint8_t idx, bool on);
    void (*SetPos)(uint8_t idx, uint16_t pos);
    void (*Apply)(uint8_t idx);
} HW_Curtain_InterfaceTypeDef;

typedef struct
{
    HW_LightCT_InterfaceTypeDef  LightCT;
    HW_LEDStrip_InterfaceTypeDef LEDStrip;
    HW_Curtain_InterfaceTypeDef  Curtain;
} HW_InterfaceTypeDef;

extern HW_InterfaceTypeDef HWInterface;

void HW_Init(void);

#ifdef __cplusplus
}
#endif

#endif
