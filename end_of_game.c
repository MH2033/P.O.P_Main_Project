#include "headers.h"
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
    char mesg[] = "Game Over!";
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
       i++;
    }
    wattron(game_over_window, A_STANDOUT);
    mvwprintw(game_over_window, i+1, (win_size.x-strlen("Return to main menu"))/2, "%s", "Return to main menu");
    wattroff(game_over_window, A_STANDOUT);
    wrefresh(game_over_window);
    while(getch()!= '\n');
    delwin(game_over_window);
}
void win(void){
    WINDOW *win_window;
    struct dimension win_size;
    char mesg[] = "Winner Winner Chicken Dinner!";
    win_size.x = 2*map_size.x/3;
    win_size.y = map_size.y/3+1;
    win_window = newwin(win_size.y, win_size.x ,map_size.y/3, map_size.x/5 - 1);
    keypad(win_window, TRUE );
    box(win_window, 0, 0);
    wattron(win_window, COLOR_PAIR(2));
    mvwprintw(win_window, 0, (win_size.x-strlen(mesg))/2, "%s", mesg);
    wattroff(win_window, COLOR_PAIR(2));
    wattron(win_window, A_STANDOUT);
    mvwprintw(win_window, win_size.y/2, (win_size.x-strlen("Return to main menu"))/2, "%s", "Return to main menu");
    wattroff(win_window, A_STANDOUT);
    wrefresh(win_window);
    while(getch()!= '\n');
    delwin(win_window);
}

void time_limit_reached(){
    WINDOW *time_window;
    struct dimension win_size;
    char mesg[] = "Time Limit Reached!";
    win_size.x = 2*map_size.x/3;
    win_size.y = map_size.y/3+1;
    time_window = newwin(win_size.y, win_size.x ,map_size.y/3, map_size.x/5 - 1);
    keypad(time_window, TRUE );
    box(time_window, 0, 0);
    wattron(time_window, COLOR_PAIR(3));
    mvwprintw(time_window, 0, (win_size.x-strlen(mesg))/2, "%s", mesg);
    wattroff(time_window, COLOR_PAIR(3));
    wattron(time_window, A_STANDOUT);
    mvwprintw(time_window, win_size.y/2, (win_size.x-strlen("Return to main menu"))/2, "%s", "Return to main menu");
    wattroff(time_window, A_STANDOUT);
    wrefresh(time_window);
    while(getch()!= '\n');
    delwin(time_window);
}