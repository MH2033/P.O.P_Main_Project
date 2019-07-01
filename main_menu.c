#include <curses.h>
#include <string.h>
#include <stdlib.h>
#include "game_console.h"
extern struct dimension default_term_size;
WINDOW *game_menu;
void show_main_menu(){
    char mesg[5][20] = {"Retro Game Console", "Play", "Scoreboard", "Settings", "Exit"};
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    curs_set(0);
    noecho();
    cbreak();
    clear();
    WINDOW *main_menu = newwin(2*default_term_size.y/3, 2*default_term_size.x/3, default_term_size.y/5 - 1, default_term_size.x/5-4);
    game_menu = newwin(2*default_term_size.y/3, 2*default_term_size.x/3, default_term_size.y/5 - 1, default_term_size.x/5-4);
    keypad(main_menu, TRUE);
    touchwin(stdscr);
    refresh();
    box(main_menu, 0, 0);
    wattron(main_menu, COLOR_PAIR(1));
    mvwprintw(main_menu, 0,(2*default_term_size.x/3-strlen(mesg[0]))/2,"%s",mesg[0]);
    wattroff(main_menu, COLOR_PAIR(1));
    int ch = 0, i = 0;
    for(i=1; i<5; i++) {
        if(i == 1)
            wattron(main_menu, A_STANDOUT);
        else
            wattroff(main_menu, A_STANDOUT);
        mvwprintw(main_menu, 2*(i+1), (2*default_term_size.x/3-strlen(mesg[i]))/2, "%s", mesg[i]);
    }
    wrefresh(main_menu);
    i = 1;
    while(1) {
        ch = getch();
        mvwprintw(main_menu, 2*(i + 1), (2 * default_term_size.x / 3 - strlen(mesg[i])) / 2, "%s", mesg[i]);
        switch (ch) {
            case KEY_UP:
                i--;
                i = (i < 1) ? 4 : i;
                break;
            case KEY_DOWN:
                i++;
                i = (i > 4) ? 1 : i;
                break;
        }
        wattron(main_menu, A_STANDOUT);
        mvwprintw(main_menu, 2*(i + 1), (2 * default_term_size.x / 3 - strlen(mesg[i])) / 2, "%s", mesg[i]);
        wattroff(main_menu, A_STANDOUT);
        wrefresh(main_menu);
        if(ch == '\n' && i == 1)
            break;
        else if(ch == '\n' && i == 4)
            _Exit(0);
    }
    delwin(main_menu);

}