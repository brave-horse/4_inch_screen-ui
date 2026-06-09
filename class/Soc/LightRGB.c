#include <stdio.h>
#include <stdlib.h>
#include "LightRGB.h"

static void lightrgb_apply(void *dev)
{
    LightRGB *l = (LightRGB *)dev;
    if (!Switch_IsOn(&l->sw)) {
        printf("  -> [RGB灯 %s] 关\n", l->base.name);
        return;
    }
    printf("  -> [RGB灯 %s] 亮度=%u%% RGB=(%u,%u,%u)\n",
           l->base.name, Percent_Get(&l->bri), l->r, l->g, l->b);
}

void LightRGB_Init(LightRGB *dev, const char *name, uint32_t id, uint16_t bri)
{
    if (!dev) return;
    Object_Init(&dev->base, name, id);
    dev->base.apply = lightrgb_apply;
    Switch_Init(&dev->sw, false);
    Percent_Init(&dev->bri, bri);
    dev->r = 255;
    dev->g = 255;
    dev->b = 255;
}

LightRGB *LightRGB_New(const char *name, uint32_t id, uint16_t bri)
{
    LightRGB *dev = (LightRGB *)malloc(sizeof(LightRGB));
    if (!dev) return NULL;
    LightRGB_Init(dev, name, id, bri);
    return dev;
}
