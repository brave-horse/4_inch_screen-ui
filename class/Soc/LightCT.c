#include <stdio.h>
#include <stdlib.h>
#include "LightCT.h"

static void lightct_apply(void *dev)
{
    LightCT *l = (LightCT *)dev;
    if (!Switch_IsOn(&l->sw)) {
        printf("  -> [CT灯 %s] 关\n", l->base.name);
        return;
    }
    printf("  -> [CT灯 %s] 亮度=%u%% 色温=%uK\n",
           l->base.name, Percent_Get(&l->bri), l->ct);
}

void LightCT_Init(LightCT *dev, const char *name, uint32_t id,
                  uint16_t bri, uint16_t ct)
{
    if (!dev) return;
    Object_Init(&dev->base, name, id);
    dev->base.apply = lightct_apply;
    Switch_Init(&dev->sw, false);
    Percent_Init(&dev->bri, bri);
    dev->ct = ct;
}

LightCT *LightCT_New(const char *name, uint32_t id,
                     uint16_t bri, uint16_t ct)
{
    LightCT *dev = (LightCT *)malloc(sizeof(LightCT));
    if (!dev) return NULL;
    LightCT_Init(dev, name, id, bri, ct);
    return dev;
}
