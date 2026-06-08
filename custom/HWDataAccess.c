#include "HWDataAccess.h"
#include "LightCT.h"
#include "Curtain.h"

static LightCT  g_light_ct;
static Curtain  g_curtain[CURTAIN_COUNT_MAX];
static uint8_t  g_curtain_cnt;   /* 已初始化的窗帘数 */

static uint16_t clamp_to(uint16_t v, uint16_t lo, uint16_t hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

/* ═══════════ 色温灯 ═══════════ */

static void impl_LightCT_Init(void)
{
    LightCT_Init(&g_light_ct, "CT主灯", 1, 4600, 50);
    HWInterface.LightCT.switch_status = Light_IsOn(&g_light_ct.base);
    HWInterface.LightCT.brightness    = Light_GetBrightness(&g_light_ct.base);
    HWInterface.LightCT.color_temp    = LightCT_GetColorTemp(&g_light_ct);
    HWInterface.LightCT.changed       = 1;   /* 首轮必然下发 */
}

static void impl_LightCT_SetOnOff(bool on)
{
    if (Light_IsOn(&g_light_ct.base) != on) {
        Light_SetOn(&g_light_ct.base, on);
        HWInterface.LightCT.switch_status = on;
        HWInterface.LightCT.changed = 1;
    }
}

static void impl_LightCT_SetBrightness(uint16_t bri)
{
    bri = clamp_to(bri, LIGHTCT_BRIGHTNESS_MIN, LIGHTCT_BRIGHTNESS_MAX);
    if (Light_GetBrightness(&g_light_ct.base) != bri) {
        Light_SetBrightness(&g_light_ct.base, bri);
        HWInterface.LightCT.brightness = bri;
        HWInterface.LightCT.changed = 1;
    }
}

static void impl_LightCT_SetColorTemp(uint16_t ct)
{
    ct = clamp_to(ct, LIGHTCT_COLOR_TEMP_MIN, LIGHTCT_COLOR_TEMP_MAX);
    if (LightCT_GetColorTemp(&g_light_ct) != ct) {
        LightCT_SetColorTemp(&g_light_ct, ct);
        HWInterface.LightCT.color_temp = ct;
        HWInterface.LightCT.changed = 1;
    }
}

static void impl_LightCT_Apply(void)
{
    uint16_t bri = HWInterface.LightCT.switch_status
                   ? HWInterface.LightCT.brightness : 0;
    Light_SetBrightness(&g_light_ct.base, bri);
    Light_Apply(&g_light_ct.base);
    HWInterface.LightCT.changed = 0;
}

/* ═══════════ 窗帘 ═══════════ */

static void impl_Curtain_Init(uint8_t idx)
{
    if (idx >= g_curtain_cnt) return;
    Curtain_Init(&g_curtain[idx], "窗帘", 10 + idx, 50);
    if (idx == 0) {
        HWInterface.Curtain.switch_status = Curtain_IsOn(&g_curtain[0]);
        HWInterface.Curtain.position      = Curtain_GetPos(&g_curtain[0]);
        HWInterface.Curtain.changed       = 1;
    }
}

static void impl_Curtain_SetOnOff(uint8_t idx, bool on)
{
    if (idx >= g_curtain_cnt) return;
    if (Curtain_IsOn(&g_curtain[idx]) != on) {
        Curtain_SetOn(&g_curtain[idx], on);
        if (idx == 0) {
            HWInterface.Curtain.switch_status = on;
            HWInterface.Curtain.changed = 1;
        }
    }
}

static void impl_Curtain_SetPos(uint8_t idx, uint16_t pos)
{
    if (idx >= g_curtain_cnt) return;
    pos = clamp_to(pos, CURTAIN_POS_MIN, CURTAIN_POS_MAX);
    if (Curtain_GetPos(&g_curtain[idx]) != pos) {
        Curtain_SetPos(&g_curtain[idx], pos);
        if (idx == 0) {
            HWInterface.Curtain.position = pos;
            HWInterface.Curtain.changed = 1;
        }
    }
}

static void impl_Curtain_Apply(uint8_t idx)
{
    if (idx >= g_curtain_cnt) return;
    uint16_t pos = Curtain_IsOn(&g_curtain[idx])
                   ? Curtain_GetPos(&g_curtain[idx]) : 0;
    Curtain_SetPos(&g_curtain[idx], pos);
    Curtain_Apply(&g_curtain[idx]);
    if (idx == 0) {
        HWInterface.Curtain.changed = 0;
    }
}

/* ═══════════ 全局实例 ═══════════ */

HW_InterfaceTypeDef HWInterface = {
    .LightCT = {
        .switch_status = false,
        .brightness    = 50,
        .color_temp    = 4600,
        .changed       = 1,
        .Init          = impl_LightCT_Init,
        .SetOnOff      = impl_LightCT_SetOnOff,
        .SetBrightness = impl_LightCT_SetBrightness,
        .SetColorTemp  = impl_LightCT_SetColorTemp,
        .Apply         = impl_LightCT_Apply,
    },
    .Curtain = {
        .switch_status = false,
        .position      = 50,
        .changed       = 1,
        .Init          = impl_Curtain_Init,
        .SetOnOff      = impl_Curtain_SetOnOff,
        .SetPos        = impl_Curtain_SetPos,
        .Apply         = impl_Curtain_Apply,
    },
};

void HW_Init(void)
{
    /* 色温灯: 1 个 */
    impl_LightCT_Init();

    /* 窗帘: 1 路(改 CURTAIN_COUNT_MAX 和此处 for 上限即可扩展) */
    g_curtain_cnt = 1;
    impl_Curtain_Init(0);
}
