#include "HWDataAccess.h"
#include "LightCT.h"
#include "CurtainMotor.h"

static LightCT      g_light_ct;
static LightCT      g_led_strip;
static CurtainMotor g_curtain[CURTAIN_COUNT_MAX];
static uint8_t      g_curtain_cnt;

static uint16_t clamp_to(uint16_t v, uint16_t lo, uint16_t hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

/* ═══════════ 色温灯 ═══════════ */

static void impl_LightCT_SetOnOff(bool btn_status)
{
    Switch_Set(&g_light_ct.sw, btn_status);
    HWInterface.LightCT.switch_status = btn_status;
}

static void impl_LightCT_SetBrightness(uint16_t bri)
{
    bri = clamp_to(bri, LIGHTCT_BRIGHTNESS_MIN, LIGHTCT_BRIGHTNESS_MAX);
    Percent_Set(&g_light_ct.bri, bri);
    HWInterface.LightCT.brightness = bri;
}

static void impl_LightCT_SetColorTemp(uint16_t ct)
{
    ct = clamp_to(ct, LIGHTCT_COLOR_TEMP_MIN, LIGHTCT_COLOR_TEMP_MAX);
    g_light_ct.ct = ct;
    HWInterface.LightCT.color_temp = ct;
}

static void impl_LightCT_Apply(void)
{
    uint16_t bri = HWInterface.LightCT.switch_status
                   ? HWInterface.LightCT.brightness : 0;
    Percent_Set(&g_light_ct.bri, bri);
    if (g_light_ct.base.apply)
        g_light_ct.base.apply(&g_light_ct);
}

/* ═══════════ LED灯带 ═══════════ */

static void impl_LEDStrip_SetOnOff(bool btn_status)
{
    Switch_Set(&g_led_strip.sw, btn_status);
    HWInterface.LEDStrip.switch_status = btn_status;
}

static void impl_LEDStrip_SetBrightness(uint16_t bri)
{
    bri = clamp_to(bri, LIGHTCT_BRIGHTNESS_MIN, LIGHTCT_BRIGHTNESS_MAX);
    Percent_Set(&g_led_strip.bri, bri);
    HWInterface.LEDStrip.brightness = bri;
}

static void impl_LEDStrip_SetColorTemp(uint16_t ct)
{
    ct = clamp_to(ct, LIGHTCT_COLOR_TEMP_MIN, LIGHTCT_COLOR_TEMP_MAX);
    g_led_strip.ct = ct;
    HWInterface.LEDStrip.color_temp = ct;
}

static void impl_LEDStrip_Apply(void)
{
    uint16_t bri = HWInterface.LEDStrip.switch_status
                   ? HWInterface.LEDStrip.brightness : 0;
    Percent_Set(&g_led_strip.bri, bri);
    if (g_led_strip.base.apply)
        g_led_strip.base.apply(&g_led_strip);
}

/* ═══════════ 窗帘 ═══════════ */

static void impl_Curtain_SetOnOff(uint8_t idx, bool btn_status)
{
    if (idx >= g_curtain_cnt) return;
    Switch_Set(&g_curtain[idx].sw, btn_status);
    if (idx == 0)
        HWInterface.Curtain.switch_status = btn_status;
}

static void impl_Curtain_SetPos(uint8_t idx, uint16_t pos)
{
    if (idx >= g_curtain_cnt) return;
    pos = clamp_to(pos, CURTAIN_POS_MIN, CURTAIN_POS_MAX);
    Percent_Set(&g_curtain[idx].pos, pos);
    if (idx == 0)
        HWInterface.Curtain.position = pos;
}

static void impl_Curtain_Apply(uint8_t idx)
{
    if (idx >= g_curtain_cnt) return;
    uint16_t pos = Switch_IsOn(&g_curtain[idx].sw)
                   ? Percent_Get(&g_curtain[idx].pos) : 0;
    Percent_Set(&g_curtain[idx].pos, pos);
    if (g_curtain[idx].base.apply)
        g_curtain[idx].base.apply(&g_curtain[idx]);
}

/* ═══════════ 全局实例 ═══════════ */

HW_InterfaceTypeDef HWInterface = {
    .LightCT = {
        .switch_status = false,
        .brightness    = 50,
        .color_temp    = 4600,
        .SetOnOff      = impl_LightCT_SetOnOff,
        .SetBrightness = impl_LightCT_SetBrightness,
        .SetColorTemp  = impl_LightCT_SetColorTemp,
        .Apply         = impl_LightCT_Apply,
    },
    .LEDStrip = {
        .switch_status = false,
        .brightness    = 50,
        .color_temp    = 4600,
        .SetOnOff      = impl_LEDStrip_SetOnOff,
        .SetBrightness = impl_LEDStrip_SetBrightness,
        .SetColorTemp  = impl_LEDStrip_SetColorTemp,
        .Apply         = impl_LEDStrip_Apply,
    },
    .Curtain = {
        .switch_status = false,
        .position      = 50,
        .SetOnOff      = impl_Curtain_SetOnOff,
        .SetPos        = impl_Curtain_SetPos,
        .Apply         = impl_Curtain_Apply,
    },
};

void HW_Init(void)
{
    LightCT_Init(&g_light_ct,  "CT主灯", 1, 50, 4600);
    LightCT_Init(&g_led_strip, "LED灯带", 2, 50, 4600);
    g_curtain_cnt = 1;
    CurtainMotor_Init(&g_curtain[0], "窗帘", 10, 50);
}
