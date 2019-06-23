#include "game_console.h"
#include <windows.h>
extern struct rpoint point;
extern int global_counter;
extern int score[];
struct opponent opp;
void game_over(void){
    system("cls");
    printf("\t\t\tGAME OVER");
    if (point.symbol != 0){
        printf("\tYOUR SCORE IS : %d",score[0]);
        if(opp.dest == point.symbol){
            for(int i = 1; i < global_counter; i++)
            printf("\nA\\I %d score: %d",i,score[i]);
        }
    }
    cd("..");
    cd("..");
}
void win(void){
    system("cls");
    printf("\t\t\tYOU WIN THE GAME");
    if (point.symbol != 0){
        printf("\nYOUR SCORE IS : %d",score[0]);
        if(opp.dest == point.symbol){
            for(int i = 1; i < global_counter; i++)
                printf("\nA\\I %d score: %d",i,score[i]);
        }
    }
}