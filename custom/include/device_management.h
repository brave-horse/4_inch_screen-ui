#ifndef DEVICE_MANAGEMENT_H
#define DEVICE_MANAGEMENT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

/* 设备槽位索引 */
enum {
    DEV_SLOT_CT_LIGHT = 0,   /* cont_1: 色温灯 */
    DEV_SLOT_LEDSTRIP,        /* cont_2: LED灯带 */
    DEV_SLOT_CURTAIN,         /* cont_3: 窗帘 */
    DEV_SLOT_COUNT
};

/* SCREEN_LOADED 事件里调用: 从中间层读所有设备状态, 刷新 UI */
void dev_mgmt_on_load(void);

/* CT灯开关(VALUE_CHANGED)事件里调用: 读 CHECKED → 写中间层 → 刷指示器 */
void dev_mgmt_ct_on_toggle(void);

#ifdef __cplusplus
}
#endif

#endif
