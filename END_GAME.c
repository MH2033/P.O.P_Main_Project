#include "game_console.h"
#include <windows.h>
#include <dirent.h>
#include <curses.h>
extern struct rpoint point;
extern int global_counter;
extern int score[];
struct opponent opp;
extern char Exit;
extern char c;
void game_over(void){
    clear();
    c = Exit;
    printw("\t\t\tGAME OVER");
    if (point.symbol != 0){
        printf("\tYOUR SCORE IS : %d",score[0]);
        if(opp.dest == point.symbol){
            for(int i = 1; i < global_counter; i++)
            printw("\nA\\I %d score: %d",i,score[i]);
        }
    }
    printw("\nplease enter key to continue...");
    refresh();
    getchar();
    getchar();
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
    getch();
}