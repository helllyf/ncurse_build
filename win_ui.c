#include <string.h>
#include<ctype.h>
#include "ui.h"

/*界面窗口*/
WINDOW *win=NULL;               /* 框架窗口 */
WINDOW *title_win=NULL;         /* 标题窗口 */
WINDOW *main_win=NULL;          /* 主窗口   */
WINDOW *message_win=NULL;       /* 消息窗口 */

/**
 * function：ncurses   初始化窗口
 *           noecho(); 关闭回显         
 * parmater：无
 * return  ：无
 */
void init_win(void)
{
    /* 初始化虚拟窗口进入ncurses模式 */
    initscr();

    /*当cbreak模式被开启後，除了DELETE或CTRL等仍被视为特殊控制字元外一切输入的字元将立刻被一一读取。*/
    cbreak();
    noecho(); /*关闭回显*/
}

/**
 * function：ncurses   退出窗口        
 * parmater：无
 * return  ：无
 */
void exit_win(void)
{
    endwin();
}

/**
 * function：绘制主框架界面          
 * parmater：无
 * return  ：无
 */
void create_frame(void)
{
    win=newwin(24,80,0,0);         //框架窗口
    title_win=newwin(3,20,1,28);   //标题窗口
    main_win=newwin(14,78,4,1);    //主界面窗口
    message_win=newwin(4,78,19,1); //提示信息窗口

    /*当开启keypad後，可以使用键盘上的一些特殊字元，如上下左右等方向键*/
    keypad(main_win,true);
    keypad(message_win,true);

    box(win,0,0);                  //画大框架边框
    mvwprintw(win,0,25,"Mini BUG Management Systems");

    /*画横线*/
    mvwaddch(win,18,0,ACS_LTEE);
    mvwhline(win,18,1,0,78);
    mvwaddch(win,18,79,ACS_RTEE);
    mvwprintw(win,18,36,"Message");

    wrefresh(win);
}

/**
 * function：绘制标题窗口          
 * parmater：s：标题窗口的名字
 * return：无
 */
void create_title_window(char *s)
{
    wclear(title_win);
    box(title_win,0,0);
    mvwprintw(title_win,1,5,s);
    wrefresh(title_win);
}


/**
 * function：在消息窗口显示提示或警告消息
 * parmater：s：所要显示的信息的内容
 * return：无
 */
void show_message(char *s)
{
    wclear(message_win);
    mvwprintw(message_win,0,0,s);
    wrefresh(message_win);
}
 
 
/**
 * function：光标回退清空n格
 * parmater：
 * win：所在窗口
 * n：要回退的格数
 * return：无
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
 * function：删除字符串两边的空格（整合前两个函数）
 * parmater：
 * s：待处理的字符串
 * return：无
*/
void delete_space(char *str)
{
    int len = strlen(str);
    if(0==len) {
        return;
    }
    delete_leftspace(str);   //删除前空格
    delete_rightspace(str);  //删除后空格   
}


/**
 * function：登录提示界面       
 * parmater：无
 * return：无
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
