/* screen5.c —— 已清空, 待重写。
 *
 * 原 screen_5 灯光/滑块逻辑(轮询 + apply_light + 防卡修复)已全部删除。
 * 为保证工程可编译, 同时去掉了:
 *   - custom.c 里对 screen_custom_init() 的调用;
 *   - screen.h 里 screen_custom_init() 的声明。
 * 重做时若仍要一个"建屏入口", 告诉我入口函数名, 我再把调用/声明接回去。
 */
