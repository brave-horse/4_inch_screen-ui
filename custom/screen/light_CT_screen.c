/*********************
 *      INCLUDES
 *********************/
#include "lvgl.h"
#include "gui_guider.h"
#include "HWDataAccess.h"   
#include "screen.h"         
/* 注: 这些头在 make 构建里有 -I 路径; IDE 报"无法打开"是 c_cpp_properties 的 includePath
 *     没配, 不是编译错误。 */

/**********************
 *  GLOBAL FUNCTIONS
 **********************/

/* 按当前亮度/色温刷两张灯光图透明度 + 两个标签数字; 关灯时灯光图隐藏(0)。
 * light_CT_screen 的 slider 拖动 / 进屏(SCREEN_LOADED) / 开关 事件都调它 —— 灯光公式只此一份。
 * 由 GUI Guider 事件调用: 事件 include 框写 #include "screen.h", 代码里调 light_CT_screen_apply_light()。 */
void light_CT_screen_apply_light(void)
{
    lv_obj_t *slider1 = guider_ui.light_CT_screen_slider_1;
    lv_obj_t *slider2 = guider_ui.light_CT_screen_slider_2;
    if (!lv_obj_is_valid(slider1) || !lv_obj_is_valid(slider2)) {
        return;
    }

    int32_t  bri = lv_slider_get_value(slider1);
    int32_t  ct  = lv_slider_get_value(slider2);
    uint32_t ct_span  = LIGHTCT_COLOR_TEMP_MAX - LIGHTCT_COLOR_TEMP_MIN;
    uint32_t tnum     = (uint32_t)(ct - LIGHTCT_COLOR_TEMP_MIN);
    uint32_t o_white  = (uint32_t)bri * tnum             * LV_OPA_COVER / ((uint32_t)LIGHTCT_BRIGHTNESS_MAX * ct_span);
    uint32_t o_orange = (uint32_t)bri * (ct_span - tnum) * LV_OPA_COVER / ((uint32_t)LIGHTCT_BRIGHTNESS_MAX * ct_span);

    if (!HWInterface.LightCT.switch_status) {   /* 关灯: 两张灯光图隐藏 */
        o_white  = LV_OPA_TRANSP;
        o_orange = LV_OPA_TRANSP;
    }

    lv_obj_set_style_img_opa(guider_ui.light_CT_screen_dev_white_img,  (lv_opa_t)o_white,  LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(guider_ui.light_CT_screen_dev_orange_img, (lv_opa_t)o_orange, LV_PART_MAIN | LV_STATE_DEFAULT);

    char buf[32];
    lv_snprintf(buf, sizeof(buf), "亮 度 | %d%%", (int)bri);
    lv_label_set_text(guider_ui.light_CT_screen_label_1, buf);
    lv_snprintf(buf, sizeof(buf), "色 温 | %dK", (int)ct);
    lv_label_set_text(guider_ui.light_CT_screen_label_2, buf);
}
