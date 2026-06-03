#ifndef __CUSTOM_IMG_H_
#define __CUSTOM_IMG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "gui_guider.h"

/* 把图片控件的 src 设成预解码好的 DDR dsc(而不是 SD 文件路径)。
 * name 用纯文件名(如 "1.jpg")；找不到对应预解码项时回退到 SD 路径(慢路径兜底)。 */
void custom_img_set_src(lv_obj_t *img, const char *name);

/* 开机调用一次：把资源图全部预解码进 DDR + 注册拦截解码器 + 给主屏挂内存图。
 * 之后任何屏用 SD 文件路径引用这些图都会命中 DDR buffer，走纯 DMA blit，不再重解码。 */
void custom_img_init(lv_ui *ui);

#ifdef __cplusplus
}
#endif

#endif /* __CUSTOM_IMG_H_ */
