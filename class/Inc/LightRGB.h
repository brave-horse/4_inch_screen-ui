#ifndef LIGHTRGB_H
#define LIGHTRGB_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"
#include "object.h"
#include "Switch.h"
#include "Percent.h"

/* RGB灯 = Object + Switch + 亮度 + RGB */
typedef struct {
    Object   base;       /* name + id + apply */
    Switch   sw;         /* 开关 */
    Percent  bri;        /* 亮度 0~100 */
    uint8_t  r, g, b;    /* RGB 0~255 */
} LightRGB;

void     LightRGB_Init(LightRGB *dev, const char *name, uint32_t id,
                       uint16_t bri);
LightRGB *LightRGB_New(const char *name, uint32_t id, uint16_t bri);

#ifdef __cplusplus
}
#endif

#endif
