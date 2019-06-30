#include <curses.h>
#include "core_functions/bass.h"
#include "game_console.h"
extern int c;
extern struct dimension map_size;
void show_pause_window(){
    struct dimension win_size;
    char mesg1[] = "Paused";
    char mesg2[] =  "Press any key to continue";
    win_size.x = 2*map_size.x/3;
    win_size.y = map_size.y/3+1;
    WINDOW *pause_win = newwin(win_size.y, win_size.x ,map_size.y/3, map_size.x/5 - 1);
    box(pause_win, ' ', ' ');
    mvwhline(pause_win, 0,0,'!',win_size.x);
    mvwhline(pause_win, win_size.y-1,0,'!',win_size.x);
    mvwvline(pause_win,0, 0, '!', win_size.y);
    mvwvline(pause_win,0, win_size.x-1, '!', win_size.y);
    mvwprintw(pause_win, 1,(win_size.x-strlen(mesg1))/2,"%s",mesg1);
    mvwprintw(pause_win, 2,(win_size.x-strlen(mesg2))/2,"%s",mesg2);
    wrefresh(pause_win);
    getch();
    c = 0;
    endwin();
    clear();
    refresh();
}