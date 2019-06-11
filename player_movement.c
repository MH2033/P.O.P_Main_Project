#include <stdlib.h>
#include "game_console.h"

extern char solidblock, deathblock, moveblock, wall, target, object;
extern char up, down, left, right, character, Exit;
extern int time_limit, raindb, attack;
extern struct rpoint point;
extern struct opponent opp;
extern struct put dblock;
extern int TX[2],TY[2];
extern char **game_map;

void move_up(int x_p_x ,int x_p_y,char obj,int score[],int i){
    if (game_map[x_p_x][x_p_y] == obj) {
        if (game_map[x_p_x - 1][x_p_y] == ' ') {
            game_map[x_p_x][x_p_y] = ' ';
            game_map[x_p_x - 1][x_p_y] = obj;
        } else if (game_map[x_p_x - 1][x_p_y] == point.symbol) {
            score[i] += point.score;
            game_map[x_p_x - 1][x_p_y] = ' ';
            random_gen(1,point.symbol);
            game_map[x_p_x][x_p_y] = ' ';
            game_map[x_p_x - 1][x_p_y] = obj;
        }
        else if (game_map[x_p_x - 1][x_p_y] == 5) {
            score[i] += 5;
            game_map[x_p_x - 1][x_p_y] = ' ';
            rand1(1,5);
            game_map[x_p_x][x_p_y] = ' ';
            game_map[x_p_x - 1][x_p_y] = obj;
        }else if(game_map[x_p_x - 1][x_p_y] == 6){
            game_map [x_p_x - 1][x_p_y] = ' ';
            game_map [x_p_x][x_p_y] = ' ';
            for (int j = 0; j < 2; j++) {
                if(game_map[TX[j]][TY[j]] == 6){
                    game_map[TX[j]][TY[j]] = ' ';
                    x_p_x = TX[j];
                    x_p_y = TY[j];
                    rand1(2,6);
                }
            }
            game_map[x_p_x][x_p_y] = ' ';
            game_map[x_p_x][x_p_y] = obj;
        }
    }
}
void move_down(int x_p_x ,int x_p_y,char obj,int score[],int i){
    if (game_map[x_p_x][x_p_y] == obj) {
        if (game_map[x_p_x +1][x_p_y] == ' ') {
            game_map[x_p_x][x_p_y] = 0;
            game_map[x_p_x + 1][x_p_y] = obj;
        } else if (game_map[x_p_x + 1][x_p_y] == point.symbol) {
            score[i] += point.score;
            game_map[x_p_x + 1][x_p_y] = ' ';
            random_gen(1, point.symbol);
            game_map[x_p_x][x_p_y] = ' ';
            game_map[x_p_x + 1][x_p_y] = obj;
        }
        else if (game_map[x_p_x + 1][x_p_y] == 5) {
            score[i] += 5;
            game_map[x_p_x + 1][x_p_y] = ' ';
            rand1(1,5);
            game_map[x_p_x][x_p_y] = ' ';
            game_map[x_p_x + 1][x_p_y] = obj;
        }else if(game_map[x_p_x + 1][x_p_y] == 6){
            game_map [x_p_x + 1][x_p_y] = ' ';
            game_map [x_p_x][x_p_y] = ' ';
            for (int j = 0; j < 2; j++) {
                if(game_map[TX[j]][TY[j]] == 6){
                    game_map[TX[j]][TY[j]] = ' ';
                    x_p_x = TX[j];
                    x_p_y = TY[j];
                }
            }
            rand1(2,6);
            game_map[x_p_x][x_p_y] = ' ';
            game_map[x_p_x][x_p_y] = obj;
        }
    }
}
void move_right(int x_p_x ,int x_p_y,char obj, int score[],int i) {
    if (game_map[x_p_x][x_p_y] == obj) {
        if (game_map[x_p_x][x_p_y +1] == ' ') {
            game_map[x_p_x][x_p_y] = ' ';
            game_map[x_p_x][x_p_y +1] = obj;
        } else if (game_map[x_p_x][x_p_y +1] == point.symbol) {
            score[i] += point.score;
            game_map[x_p_x][x_p_y + 1] = ' ';
            random_gen(1, point.symbol);
            game_map[x_p_x][x_p_y] = ' ';
            game_map[x_p_x][x_p_y +1] = obj;
        }
        else if (game_map[x_p_x][x_p_y +1]== 5) {
            score[i] += 5;
            game_map[x_p_x][x_p_y +1] = ' ';
            rand1(1,5);
            game_map[x_p_x][x_p_y] = ' ';
            game_map[x_p_x][x_p_y +1] = obj;
        }else if(game_map[x_p_x][x_p_y + 1] == 6){
            game_map [x_p_x][x_p_y + 1] = ' ';
            game_map [x_p_x][x_p_y] = ' ';
            for (int j = 0; j < 2; j++) {
                if(game_map[TX[j]][TY[j]] == 6){
                    game_map[TX[j]][TY[j]] = ' ';
                    x_p_x = TX[j];
                    x_p_y = TY[j];
                    rand1(2,6);
                }
            }
            game_map[x_p_x][x_p_y] = ' ';
            game_map[x_p_x][x_p_y] = obj;
        }
    }
}
void move_left(int x_p_x ,int x_p_y,char obj,int score[],int i) {
    if (game_map[x_p_x][x_p_y] == obj) {
        if (game_map[x_p_x][x_p_y -1] == ' ') {
            game_map[x_p_x][x_p_y] = ' ';
            game_map[x_p_x][x_p_y - 1] = obj;
        } else if (game_map[x_p_x][x_p_y -1] == point.symbol) {
            score[i] += point.score;
            game_map[x_p_x][x_p_y - 1] = ' ';
            random_gen(1, point.symbol);
            game_map[x_p_x][x_p_y] = ' ';
            game_map[x_p_x][x_p_y -1] = obj;
        }
        else if (game_map[x_p_x][x_p_y -1]== 5) {
            score[i] += 5;
            game_map[x_p_x][x_p_y -1] = ' ';
            rand1(1,5);
            game_map[x_p_x][x_p_y] = ' ';
            game_map[x_p_x][x_p_y -1] = obj;
        }else if(game_map[x_p_x][x_p_y -1] == 6){
            game_map [x_p_x][x_p_y -1 ] = ' ';
            game_map [x_p_x][x_p_y] = ' ';
            for (int j = 0; j < 2; j++) {
                if(game_map[TX[j]][TY[j]] == 6){
                    game_map[TX[j]][TY[j]] = ' ';
                    x_p_x = TX[j];
                    x_p_y = TY[j];
                    rand1(2,6);
                }
            }
            game_map[x_p_x][x_p_y] = 0;
            game_map[x_p_x][x_p_y] = obj;
        }
    }
}