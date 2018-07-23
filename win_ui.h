#ifndef _WIN_UI_H_ 
#define _WIN_UI_H_ 

#include <ncurses.h>
#include <locale.h>

/* 初始化窗口 */
void init_win(void);
/* 退出窗口 */
void exit_win(void);
/* 绘制主框架界面  */
void create_frame(void);
/* 绘制标题窗口  */
void create_title_window(char *s);
/* 在消息窗口显示提示或警告消息 */
void show_message(char *s);
/* 光标回退清空n格 */
void goback_n(WINDOW *win_tmp,int n);
/* 删除字符串两边的空格 */
void delete_space(char *str);
/* 登录提示界面 */
void user_login(void);

#endif /* _WIN_UI_H_ */


