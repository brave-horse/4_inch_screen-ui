#ifndef CUSTOM_SCREEN_H
#define CUSTOM_SCREEN_H

#ifdef __cplusplus
extern "C" {
#endif

/* screen_5 灯光: 按亮度/色温刷两张灯光图透明度 + 两个标签(关灯时灯光图隐藏)。
 * 灯光公式集中在 screen5.c 这一份; 由 GUI Guider 的 slider 拖动 / 进屏 / 开关 事件调用
 * (事件的 include 框写 #include "screen.h")。 */
void screen_5_apply_light(void);

#ifdef __cplusplus
}
#endif

#endif /* CUSTOM_SCREEN_H */
