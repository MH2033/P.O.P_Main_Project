#include "game_console.h"
#include <curses.h>
extern struct rpoint point;
extern int global_counter;
extern int score[];
extern  int c;
extern char Exit;
struct opponent opp;
void game_over(void){
    clear();
    c = Exit;
    printw("\t\t\tGAME OVER");
    if (point.symbol != 0){
        printw("\n\tYOUR SCORE IS : %d",score[0]);
        if(opp.dest == point.symbol){
            for(int i = 1; i < global_counter; i++)
            printw("\nA\\I %d score: %d",i,score[i]);
        }
    }
    refresh();
    getch();
    cd("..");
    cd("..");
}
void win(void){
    printf("\t\t\tYOU WIN THE GAME");
    if (point.symbol != 0){
        printf("\nYOUR SCORE IS : %d",score[0]);
        if(opp.dest == point.symbol){
            for(int i = 1; i < global_counter; i++)
                printf("\nA\\I %d score: %d",i,score[i]);
        }
    }
}