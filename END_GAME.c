#include "game_console.h"
#include <windows.h>
#include <curses.h>
extern struct rpoint point;
extern int global_counter;
extern int score[];
struct opponent opp;
extern char Exit;
extern int c;
extern struct dimension map_size;
extern WINDOW *game_window;
void game_over(void){
    int i = 1, ch;
    WINDOW *game_over_window;
    struct dimension win_size;
    char temp[100];
    char mesg[] = "Game over!";
    win_size.x = 2*map_size.x/3;
    win_size.y = map_size.y/3+1;
    game_over_window = newwin(win_size.y, win_size.x ,map_size.y/3, map_size.x/5 - 1);
    keypad(game_over_window, TRUE );
    box(game_over_window, 0, 0);
    wattron(game_over_window, COLOR_PAIR(3));
    mvwprintw(game_over_window, 0, (win_size.x-strlen(mesg))/2, "%s", mesg);
    wattroff(game_over_window, COLOR_PAIR(3));
    if(point.symbol){
       sprintf(temp, "Your score is: %d", score[0]);
       mvwprintw(game_over_window, i, (win_size.x-strlen(temp))/2, "%s", temp);
    }
    wrefresh(game_over_window);
    i = 1;
    while(1) {
        ch = getch();
        mvwprintw(game_over_window, i + 1, (win_size.x - strlen(mesg)) / 2, "%s", mesg);
        switch (ch) {
            case KEY_UP:
                i--;
                i = (i < 1) ? 2 : i;
                break;
            case KEY_DOWN:
                i++;
                i = (i > 3) ? 1 : i;
                break;
        }
        wattron(game_over_window, A_STANDOUT);
        mvwprintw(game_over_window, i + 1, (win_size.x - strlen(mesg)) / 2, "%s", mesg);
        wattroff(game_over_window, A_STANDOUT);
        wrefresh(game_over_window);
    }
}
void win(void){
    clear();
    printw("\tYOU WIN THE GAME");
    if (point.symbol != 0){
        printw("\nYOUR SCORE IS : %d",score[0]);
        if(opp.dest == point.symbol){
            for(int i = 1; i < global_counter; i++)
                printw("\nA\\I %d score: %d",i,score[i]);
        }
    }
    refresh();
    printw("\nplease enter key to continue...");
    getch();
}