#ifndef CUSTOM_SCREEN_H
#define CUSTOM_SCREEN_H

#ifdef __cplusplus
extern "C" {
#endif

/* 单屏控件改动(custom/screen): 用轮询在每次屏重建后, 把"只影响单个屏"的控件微调重新 apply。
 * 目前: screen_5 的 slider_1(隐藏旋钮 + 指示条直角)。
 * 在 custom_init() 里调用一次。 */
void screen_custom_init(void);

#ifdef __cplusplus
}
#endif

#endif /* CUSTOM_SCREEN_H */
