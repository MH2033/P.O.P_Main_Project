#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "game_console.h"
extern int score[];
struct rpoint point;
struct opponent opp;
extern char **game_map;
extern char **buffer;
extern struct dimension map_size;
extern float t_limit;
extern int time_limit;
extern int global_counter;
extern int c2,flagx_i,flagx_k,flagy_l,flagy_j;
struct opp_list *head_op;
void print_map(){
    int i, j;
    COORD pos;
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    for(i = 0; i < map_size.y; i++){
        for(j = 0; j < map_size.x; j++){
            if(game_map[i][j] != buffer[i][j]) {
                pos.X = j;
                pos.Y = i;
                SetConsoleCursorPosition(output, pos);
                putchar(game_map[i][j]);
                buffer[i][j] = game_map[i][j];
            }
        }
    }
    /*printf("%c\n",c2);
    printf("i:%d\nk:%d\nl:%d\nj:%d\n  %c\n%c    %c\n  %c",flagx_i,flagx_k,flagy_l,flagy_j
            ,game_map[head_op->pos.y-1][(head_op->pos.x)]
            ,game_map[head_op->pos.y][(head_op->pos.x)-1]
            ,game_map[head_op->pos.y][(head_op->pos.x)+1]
            ,game_map[head_op->pos.y+1][(head_op->pos.x)]);
    if (time_limit) {
        printf("\ntime : %.2f", t_limit);
    }
    if (point.symbol != 0){
        printf("\nYOUR SCORE IS : %d",score[0]);
        if(opp.dest == point.symbol){
            for(i = 1; i < 2; i++)
                printf("\nA\\I %d score: %d",i,score[i]);
        }
    }*/
}