#ifndef LIGHTCT_H
#define LIGHTCT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"
#include "object.h"
#include "Switch.h"
#include "Percent.h"

/* 色温灯 = Object + Switch + 亮度 + 色温 */
typedef struct {
    Object   base;       /* name + id + apply */
    Switch   sw;         /* 开关 */
    Percent  bri;        /* 亮度 0~100 */
    uint16_t ct;         /* 色温 K */
} LightCT;

void     LightCT_Init(LightCT *dev, const char *name, uint32_t id,
                      uint16_t bri, uint16_t ct);
LightCT *LightCT_New(const char *name, uint32_t id,
                      uint16_t bri, uint16_t ct);

#ifdef __cplusplus
}
#endif

#endif
