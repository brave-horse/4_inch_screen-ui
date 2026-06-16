#include "lvgl.h"
#include "gui_guider.h"
#include "Home.h"

/* GUI-Guider 给每个 lv_img 默认塞 CLICKABLE, 会吃掉首页整屏左滑手势(进设备管理).
 * 首页每次被 auto_del 重建都会重新加上, 故在 Screen Loaded 里每次清一遍. */
void home_on_screen_load(void)
{
    lv_obj_clear_flag(guider_ui.ui_home_screen_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(guider_ui.ui_home_screen_img_2, LV_OBJ_FLAG_CLICKABLE);



}
