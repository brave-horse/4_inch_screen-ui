/*
* Copyright 2023 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lvgl.h"
#include "custom.h"
#include "custom_modules.h"

/*********************
 *      DEFINES
 *********************/

/* ───────── 调试开关：定位"界面切换卡死"问题 ─────────
 * 当前默认全部为 0 = 回到"空 custom"基线，先编译确认恢复正常(不卡)。
 * 然后按顺序逐个改成 1、各自单独编译烧录测试，复现卡死即锁定元凶，告诉我我针对性修：
 *   第1步: 只开 EN_SCR_GUARD
 *   第2步: 只开 EN_IMG
 *   第3步: 只开 EN_SCR_NOSCROLL
 * (每次只开一个，其余保持 0) */
#define EN_SCR_GUARD     1   /* rule/scr_guard.c   : 屏指针守卫 + 数字时钟野指针守护(修来回切屏卡死) */
#define EN_IMG           1   /* assert/img.c       : 图片 DDR 预解码 + 注册拦截解码器 */
#define EN_SCR_NOSCROLL  1   /* rule/scr_noscroll.c: 主屏禁滚 */

/**********************
 *  GLOBAL FUNCTIONS
 **********************/

/* custom 层总入口：由 app_main.c 的 jl_gui_init() 在 setup_ui/events_init 之后调用一次。
 * 这里只做"编排"——把各模块初始化拉起来，具体逻辑都在各自模块里：
 *   assert/img.c        图片 DDR 预解码 + 拦截解码器
 *   rule/scr_guard.c    屏指针守卫(防野指针)
 *   rule/scr_noscroll.c 指定屏禁滚(防原地重绘/吞手势)
 *   event/my_app.c      UI 事件桥接到 App 业务
 */
void custom_init(lv_ui *ui)
{
    printf("[custom] init: guard=%d img=%d noscroll=%d\n",
           EN_SCR_GUARD, EN_IMG, EN_SCR_NOSCROLL);

#if EN_SCR_GUARD
    /* 先装屏指针守卫，保证后续模块读 guider_ui.screen_* 永不变野。 */
    scr_guard_init();
#endif

#if EN_IMG
    /* 图片 DDR 预解码 + 拦截解码器。 */
    custom_img_init(ui);
#endif

#if EN_SCR_NOSCROLL
    /* 主屏禁滚。 */
    scr_noscroll_init(ui);
#endif

    /* 跨屏控件：主屏顶部下拉面板（用 GUI-Guider 画的 ui_home_screen_cont_1）。 */
    pulldown_init(ui);

    

    /* event 层：把 UI 事件桥接到 App 业务（当前为空骨架，无副作用）。 */
    my_app_event_init(ui);
}
