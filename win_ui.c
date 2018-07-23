#include <string.h>
#include<ctype.h>
#include "ui.h"

/*���洰��*/
WINDOW *win=NULL;               /* ��ܴ��� */
WINDOW *title_win=NULL;         /* ���ⴰ�� */
WINDOW *main_win=NULL;          /* ������   */
WINDOW *message_win=NULL;       /* ��Ϣ���� */

/**
 * function��ncurses   ��ʼ������
 *           noecho(); �رջ���         
 * parmater����
 * return  ����
 */
void init_win(void)
{
    /* ��ʼ�����ⴰ�ڽ���ncursesģʽ */
    initscr();

    /*��cbreakģʽ�������ᣬ����DELETE��CTRL���Ա���Ϊ���������Ԫ��һ���������Ԫ�����̱�һһ��ȡ��*/
    cbreak();
    noecho(); /*�رջ���*/
}

/**
 * function��ncurses   �˳�����        
 * parmater����
 * return  ����
 */
void exit_win(void)
{
    endwin();
}

/**
 * function����������ܽ���          
 * parmater����
 * return  ����
 */
void create_frame(void)
{
    win=newwin(24,80,0,0);         //��ܴ���
    title_win=newwin(3,20,1,28);   //���ⴰ��
    main_win=newwin(14,78,4,1);    //�����洰��
    message_win=newwin(4,78,19,1); //��ʾ��Ϣ����

    /*������keypad�ᣬ����ʹ�ü����ϵ�һЩ������Ԫ�����������ҵȷ����*/
    keypad(main_win,true);
    keypad(message_win,true);

    box(win,0,0);                  //�����ܱ߿�
    mvwprintw(win,0,25,"Mini BUG Management Systems");

    /*������*/
    mvwaddch(win,18,0,ACS_LTEE);
    mvwhline(win,18,1,0,78);
    mvwaddch(win,18,79,ACS_RTEE);
    mvwprintw(win,18,36,"Message");

    wrefresh(win);
}

/**
 * function�����Ʊ��ⴰ��          
 * parmater��s�����ⴰ�ڵ�����
 * return����
 */
void create_title_window(char *s)
{
    wclear(title_win);
    box(title_win,0,0);
    mvwprintw(title_win,1,5,s);
    wrefresh(title_win);
}


/**
 * function������Ϣ������ʾ��ʾ�򾯸���Ϣ
 * parmater��s����Ҫ��ʾ����Ϣ������
 * return����
 */
void show_message(char *s)
{
    wclear(message_win);
    mvwprintw(message_win,0,0,s);
    wrefresh(message_win);
}
 
 
/**
 * function�����������n��
 * parmater��
 * win�����ڴ���
 * n��Ҫ���˵ĸ���
 * return����
 */
void goback_n(WINDOW *win_tmp,int n)
{
    while(n--) {
        getyx(win_tmp,row,col);
        mvwprintw(win_tmp,row,col-1," ");
        wmove(win_tmp,row,col-1);
    }
    wrefresh(win_tmp);
}

/**
 * function��ɾ���ַ������ߵĿո�����ǰ����������
 * parmater��
 * s����������ַ���
 * return����
*/
void delete_space(char *str)
{
    int len = strlen(str);
    if(0==len) {
        return;
    }
    delete_leftspace(str);   //ɾ��ǰ�ո�
    delete_rightspace(str);  //ɾ����ո�   
}


/**
 * function����¼��ʾ����       
 * parmater����
 * return����
 */
void user_login(void)
{
    wrefresh(main_win);
    mvwprintw(main_win,1,13,"UserName:");
    mvwprintw(main_win,1,40,"[The max length of username is 10]");
    mvwprintw(main_win,3,13,"Password:");
    mvwprintw(main_win,3,40,"[The  length of password is 6]");
    
    wrefresh(main_win);
}
