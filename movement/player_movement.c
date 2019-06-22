#include <stdlib.h>
#include "game_console.h"

extern char solidblock, deathblock, moveblock, wall, target, object;
extern char up, down, left, right, character, Exit;
extern int time_limit, raindb, attack;
extern struct rpoint point;
extern struct opponent opp;
extern struct put dblock;
extern char **game_map;
extern struct dimension player_pos;

void move_up(int x ,int y,char obj,int score[],int i) {
    if (obj == character) {
        if (game_map[y][x] == obj) {
            if (game_map[y - 1][x] == ' ') {
                game_map[y][x] = ' ';
                game_map[y - 1][x] = obj;
                player_pos.y = y - 1;
            } else if (game_map[y - 1][x] == point.symbol) {
                score[i] += point.score;
                game_map[y - 1][x] = ' ';
                random_gen(1, point.symbol);
                game_map[y][x] = ' ';
                game_map[y - 1][x] = obj;
                player_pos.y = y - 1;
            } else if (game_map[y - 1][x] == deathblock || game_map) {
                //game_over();
            }
        }
    }
}
void move_down(int x ,int y,char obj,int score[],int i){
    if(obj == character) {
        if (game_map[y][x] == obj) {
            if (game_map[y + 1][x] == ' ') {
                game_map[y][x] = ' ';
                game_map[y + 1][x] = obj;
                player_pos.y = y + 1;
            } else if (game_map[y + 1][x] == point.symbol) {
                score[i] += point.score;
                game_map[y + 1][x] = ' ';
                random_gen(1, point.symbol);
                game_map[y][x] = ' ';
                game_map[y + 1][x] = obj;
                player_pos.y = y + 1;
            } else if (game_map[y + 1][x] == deathblock) {
                //game_over();
            }
        }
    }
}
void move_right(int x ,int y,char obj, int score[],int i) {
    if(obj == character) {
        if (game_map[y][x] == obj) {
            if (game_map[y][x + 1] == ' ') {
                game_map[y][x] = ' ';
                game_map[y][x + 1] = obj;
                player_pos.x = x + 1;
            } else if (game_map[y][x + 1] == point.symbol) {
                score[i] += point.score;
                game_map[y][x + 1] = ' ';
                random_gen(1, point.symbol);
                game_map[y][x] = ' ';
                game_map[y][x + 1] = obj;
                player_pos.x = x + 1;
            } else if (game_map[y][x + 1] == deathblock) {
                //game_over();
            }
        }
    }
}
void move_left(int x ,int y,char obj,int score[],int i) {
    if(obj == character) {
        if (game_map[y][x] == obj) {
            if (game_map[y][x - 1] == ' ') {
                game_map[y][x] = ' ';
                game_map[y][x - 1] = obj;
                player_pos.x = x - 1;
            } else if (game_map[y][x - 1] == point.symbol) {
                score[i] += point.score;
                game_map[y][x - 1] = ' ';
                random_gen(1, point.symbol);
                game_map[y][x] = ' ';
                game_map[y][x - 1] = obj;
                player_pos.x = x - 1;
            } else if (game_map[y][x - 1] == deathblock) {
                //game_over();
            }
        }
    }
}