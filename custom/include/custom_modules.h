#ifndef CUSTOM_MODULES_H
#define CUSTOM_MODULES_H

#ifdef __cplusplus
extern "C" {
#endif

/* custom 层各模块的聚合头，仅供 custom.c 使用，不要被 generated 引用。
 * 新增模块时在这里加一行对应的头文件即可。 */
#include "img.h"          /* assert/ : 图片 DDR 预解码 + 拦截解码器 */
#include "scr_guard.h"    /* rule/   : 屏指针守卫(防野指针) */
#include "scr_noscroll.h" /* rule/   : 指定屏禁滚(防原地重绘/吞手势) */
#include "screen.h"       /* screen/ : 单屏控件改动(screen_5 灯光: 亮度/色温→图片透明度+标签) */
#include "pulldown.h"     /* widget/ : 主屏顶部下拉面板(单面板) */
#include "my_app.h"       /* event/  : UI 事件桥接到 App 业务 */

#ifdef __cplusplus
}
#endif

#endif /* CUSTOM_MODULES_H */
