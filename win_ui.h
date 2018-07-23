#ifndef _WIN_UI_H_ 
#define _WIN_UI_H_ 

#include <ncurses.h>
#include <locale.h>

/* ��ʼ������ */
void init_win(void);
/* �˳����� */
void exit_win(void);
/* ��������ܽ���  */
void create_frame(void);
/* ���Ʊ��ⴰ��  */
void create_title_window(char *s);
/* ����Ϣ������ʾ��ʾ�򾯸���Ϣ */
void show_message(char *s);
/* ���������n�� */
void goback_n(WINDOW *win_tmp,int n);
/* ɾ���ַ������ߵĿո� */
void delete_space(char *str);
/* ��¼��ʾ���� */
void user_login(void);

#endif /* _WIN_UI_H_ */


