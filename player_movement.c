#include <stdlib.h>
#include "game_console.h"

extern char solidblock, deathblock, moveblock, wall, target, object;
extern char up, down, left, right, character, Exit;
extern int time_limit, raindb, attack;
extern struct rpoint point;
extern struct opponent opp;
extern struct put dblock;
extern char **game_map;

void move_up(int x ,int y,char obj,int score[],int i){
    if (game_map[x][y] == obj) {
        if (game_map[x - 1][y] == ' ') {
            game_map[x][y] = ' ';
            game_map[x - 1][y] = obj;
        } else if (game_map[x - 1][y] == point.symbol) {
            score[i] += point.score;
            game_map[x - 1][y] = ' ';
            random_gen(1,point.symbol);
            game_map[x][y] = ' ';
            game_map[x - 1][y] = obj;
        }
        else if (game_map[x - 1][y] == 5) {
            score[i] += 5;
            game_map[x - 1][y] = ' ';
            //rand1(1,5);
            game_map[x][y] = ' ';
            game_map[x - 1][y] = obj;
        }
    }
}
void move_down(int x ,int y,char obj,int score[],int i){
    if (game_map[x][y] == obj) {
        if (game_map[x +1][y] == ' ') {
            game_map[x][y] = 0;
            game_map[x + 1][y] = obj;
        } else if (game_map[x + 1][y] == point.symbol) {
            score[i] += point.score;
            game_map[x + 1][y] = ' ';
            random_gen(1, point.symbol);
            game_map[x][y] = ' ';
            game_map[x + 1][y] = obj;
        }
        else if (game_map[x + 1][y] == 5) {
            score[i] += 5;
            game_map[x + 1][y] = ' ';
            //rand1(1,5);
            game_map[x][y] = ' ';
            game_map[x + 1][y] = obj;
        }
    }
}
void move_right(int x ,int y,char obj, int score[],int i) {
    if (game_map[x][y] == obj) {
        if (game_map[x][y +1] == ' ') {
            game_map[x][y] = ' ';
            game_map[x][y +1] = obj;
        } else if (game_map[x][y +1] == point.symbol) {
            score[i] += point.score;
            game_map[x][y + 1] = ' ';
            random_gen(1, point.symbol);
            game_map[x][y] = ' ';
            game_map[x][y +1] = obj;
        }
        else if (game_map[x][y +1]== 5) {
            score[i] += 5;
            game_map[x][y +1] = ' ';
            //rand1(1,5);
            game_map[x][y] = ' ';
            game_map[x][y +1] = obj;
        }
    }
}
void move_left(int x ,int y,char obj,int score[],int i) {
    if (game_map[x][y] == obj) {
        if (game_map[x][y -1] == ' ') {
            game_map[x][y] = ' ';
            game_map[x][y - 1] = obj;
        } else if (game_map[x][y -1] == point.symbol) {
            score[i] += point.score;
            game_map[x][y - 1] = ' ';
            random_gen(1, point.symbol);
            game_map[x][y] = ' ';
            game_map[x][y -1] = obj;
        }
        else if (game_map[x][y -1]== 5) {
            score[i] += 5;
            game_map[x][y -1] = ' ';
            //rand1(1,5);
            game_map[x][y] = ' ';
            game_map[x][y -1] = obj;
        }
    }
}