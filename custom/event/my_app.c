#include "my_app.h"
#include "lvgl.h"

static lv_ui *s_ui;
static my_app_event_cb_t s_event_cb;
static void *s_event_user_data;

static bool obj_alive(lv_obj_t *obj)
{
    return obj && lv_obj_is_valid(obj);
}

static void home_btn_2_clicked(lv_event_t *e)
{
    LV_UNUSED(e);

    if (s_event_cb) {
        s_event_cb(MY_APP_EVENT_HOME_BTN_2_CLICKED, s_event_user_data);
    }
}

void my_app_set_event_cb(my_app_event_cb_t cb, void *user_data)
{
    s_event_cb = cb;
    s_event_user_data = user_data;
}

void my_app_refresh_home_date(const char *date, const char *week)
{
    if (!s_ui) {
        return;
    }

    if (date && obj_alive(s_ui->screen_label_1)) {
        lv_label_set_text(s_ui->screen_label_1, date);
    }
    if (week && obj_alive(s_ui->screen_label_2)) {
        lv_label_set_text(s_ui->screen_label_2, week);
    }
}

void my_app_refresh_home_button_text(unsigned char index, const char *text)
{
    lv_obj_t *label = NULL;

    if (!s_ui || !text) {
        return;
    }

    switch (index) {
    case 1:
        label = s_ui->screen_btn_1_label;
        break;
    case 2:
        label = s_ui->screen_btn_2_label;
        break;
    case 3:
        label = s_ui->screen_btn_3_label;
        break;
    default:
        return;
    }

    if (obj_alive(label)) {
        lv_label_set_text(label, text);
    }
}

void my_app_refresh_screen5_slider_value(unsigned char index, int value)
{
    lv_obj_t *slider = NULL;

    if (!s_ui) {
        return;
    }

    switch (index) {
    case 1:
        slider = s_ui->screen_5_slider_1;
        break;
    case 2:
        slider = s_ui->screen_5_slider_2;
        break;
    default:
        return;
    }

    if (obj_alive(slider)) {
        lv_slider_set_value(slider, value, LV_ANIM_OFF);
    }
}

/* event 层骨架：把 generated 控件的 UI 事件桥接到上层 App 业务(对应需求文档 custom/event)。
 *
 * 设计约定：
 *   - App/Service 业务层不直接操作 LVGL 控件，统一经由本层；
 *   - 本层只做"事件转发 + 对外刷新接口"，不写复杂业务逻辑(那是 App/Service 的事)。
 *
 * 接入示例：
 *   static void on_screen_btn_1_clicked(lv_event_t *e) {
 *       LV_UNUSED(e);
 *       // 这里调 App/Service 层的业务函数，例如 app_router_goto(APP_MENU);
 *   }
 *   void my_app_event_init(lv_ui *ui) {
 *       if (ui && ui->screen_btn_1) {
 *           lv_obj_add_event_cb(ui->screen_btn_1, on_screen_btn_1_clicked, LV_EVENT_CLICKED, NULL);
 *       }
 *   }
 */
void my_app_event_init(lv_ui *ui)
{
    if (!ui) {
        return;
    }

    s_ui = ui;

    if (obj_alive(ui->screen_btn_2)) {
        lv_obj_add_event_cb(ui->screen_btn_2, home_btn_2_clicked, LV_EVENT_CLICKED, NULL);
    }
}
