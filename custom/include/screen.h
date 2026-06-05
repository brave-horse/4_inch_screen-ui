#ifndef CUSTOM_SCREEN_H
#define CUSTOM_SCREEN_H

#ifdef __cplusplus
extern "C" {
#endif

/* 单屏控件改动(custom/screen): 用轮询在每次屏重建后, 把"只影响单个屏"的控件逻辑重新 apply/绑定。
 * 各自在 custom_init() 里调用一次。 */
void screen_1_custom_init(void);  /* screen_1: 色温灯开关(CT_on_off_1_img) 初始化为关 + 按下同步开关变量 */

#ifdef __cplusplus
}
#endif

#endif /* CUSTOM_SCREEN_H */
