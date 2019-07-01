#include <stdlib.h>
#include "game_console.h"

extern char solidblock, deathblock, moveblock, wall, target, object;
extern char up, down, left, right, character, Exit;
extern int time_limit, raindb, attack;
extern struct rpoint point;
extern struct opponent opp;
extern struct put dblock;
extern char **game_map;
int lose_flag;

void move_up(struct dimension *pos, char obj, int score[], int i) {
    if (obj == character) {
        if (game_map[pos->y][pos->x] == obj) {
            if (game_map[pos->y - 1][pos->x] == ' ') {
                game_map[pos->y][pos->x] = ' ';
                game_map[pos->y - 1][pos->x] = obj;
                pos->y = pos->y - 1;
            } else if (game_map[pos->y - 1][pos->x] == point.symbol) {
                score[i] += point.score;
                game_map[pos->y - 1][pos->x] = ' ';
                random_gen(1, point.symbol);
                game_map[pos->y][pos->x] = ' ';
                game_map[pos->y - 1][pos->x] = obj;
                pos->y = pos->y - 1;
            } else if (game_map[pos->y - 1][pos->x] == deathblock) {
                lose_flag = 1;

            } else if(game_map[pos->y - 1][pos->x] == moveblock){
                if(game_map[pos->y-2][pos->x] == ' '){
                    game_map[pos->y-2][pos->x] = moveblock;
                    game_map[pos->y-1][pos->x] = obj;
                    game_map[pos->y][pos->x] = ' ';
                    pos->y = pos->y - 1;
                }
            } else if(game_map[pos->y - 1][pos->x] == object) {
                if (game_map[pos->y - 2][pos->x] == ' ') {
                    game_map[pos->y - 2][pos->x] = object;
                    game_map[pos->y - 1][pos->x] = obj;
                    game_map[pos->y][pos->x] = ' ';
                    pos->y = pos->y - 1;
                }
                else if (game_map[pos->y - 2][pos->x] == target) {
                    game_map[pos->y - 2][pos->x] = object;
                    game_map[pos->y - 1][pos->x] = obj;
                    game_map[pos->y][pos->x] = ' ';
                    pos->y = pos->y - 1;
                    //show_winning_message();
                }
            }
        }
    } else if (obj == opp.rival) {
        if (game_map[pos->y][pos->x] == obj) {
            if (opp.dest == point.symbol) {
                if (game_map[pos->y - 1][pos->x] == ' ') {
                    game_map[pos->y][pos->x] = ' ';
                    game_map[pos->y - 1][pos->x] = obj;
                    pos->y = pos->y - 1;
                } else if (game_map[pos->y - 1][pos->x] == point.symbol) {
                    score[i] += point.score;
                    game_map[pos->y - 1][pos->x] = ' ';
                    random_gen(1, point.symbol);
                    game_map[pos->y][pos->x] = ' ';
                    game_map[pos->y - 1][pos->x] = obj;
                    pos->y = pos->y - 1;
                } else if (game_map[pos->y - 1][pos->x] == deathblock) {
                    //
                }
            }
        }
    }
}
void move_down(struct dimension *pos,char obj,int score[],int i) {
    if (obj == character) {
        if (game_map[pos->y][pos->x] == obj) {
            if (game_map[pos->y + 1][pos->x] == ' ') {
                game_map[pos->y][pos->x] = ' ';
                game_map[pos->y + 1][pos->x] = obj;
                pos->y = pos->y + 1;
            } else if (game_map[pos->y + 1][pos->x] == point.symbol) {
                score[i] += point.score;
                game_map[pos->y + 1][pos->x] = ' ';
                random_gen(1, point.symbol);
                game_map[pos->y][pos->x] = ' ';
                game_map[pos->y + 1][pos->x] = obj;
                pos->y = pos->y + 1;
            } else if (game_map[pos->y + 1][pos->x] == deathblock) {
                lose_flag = 1;

            } else if(game_map[pos->y + 1][pos->x] == moveblock){
                if(game_map[pos->y+2][pos->x] == ' '){
                    game_map[pos->y+2][pos->x] = moveblock;
                    game_map[pos->y+1][pos->x] = obj;
                    game_map[pos->y][pos->x] = ' ';
                    pos->y = pos->y + 1;
                }
            } else if(game_map[pos->y + 1][pos->x] == object){
                if(game_map[pos->y+2][pos->x] == ' '){
                    game_map[pos->y+2][pos->x] = object;
                    game_map[pos->y+1][pos->x] = obj;
                    game_map[pos->y][pos->x] = ' ';
                    pos->y = pos->y + 1;
                }
                else if(game_map[pos->y+2][pos->x] == target){
                    game_map[pos->y+2][pos->x] = object;
                    game_map[pos->y+1][pos->x] = obj;
                    game_map[pos->y][pos->x] = ' ';
                    pos->y = pos->y + 1;
                    //show_winning_message();
                }
            }
        }
    } else if (obj == opp.rival) {
        if (game_map[pos->y][pos->x] == obj) {
            if (opp.dest == point.symbol) {
                if (game_map[pos->y][pos->x] == obj) {
                    if (game_map[pos->y + 1][pos->x] == ' ') {
                        game_map[pos->y][pos->x] = ' ';
                        game_map[pos->y + 1][pos->x] = obj;
                        pos->y = pos->y + 1;
                    } else if (game_map[pos->y + 1][pos->x] == point.symbol) {
                        score[i] += point.score;
                        game_map[pos->y + 1][pos->x] = ' ';
                        random_gen(1, point.symbol);
                        game_map[pos->y][pos->x] = ' ';
                        game_map[pos->y + 1][pos->x] = obj;
                        pos->y = pos->y + 1;
                    } else if (game_map[pos->y + 1][pos->x] == deathblock) {
                        //
                    }
                }
            }
        }
    }
}
void move_right(struct dimension *pos,char obj, int score[],int i) {
    if (obj == character) {
        if (game_map[pos->y][pos->x] == obj) {
            if (game_map[pos->y][pos->x + 1] == ' ') {
                game_map[pos->y][pos->x] = ' ';
                game_map[pos->y][pos->x + 1] = obj;
                pos->x = pos->x + 1;
            } else if (game_map[pos->y][pos->x + 1] == point.symbol) {
                score[i] += point.score;
                game_map[pos->y][pos->x + 1] = ' ';
                random_gen(1, point.symbol);
                game_map[pos->y][pos->x] = ' ';
                game_map[pos->y][pos->x + 1] = obj;
                pos->x = pos->x + 1;
            } else if (game_map[pos->y][pos->x + 1] == deathblock) {
                lose_flag = 1;

            } else if(game_map[pos->y][pos->x+1] == moveblock){
                if(game_map[pos->y][pos->x+2] == ' '){
                    game_map[pos->y][pos->x+2] = moveblock;
                    game_map[pos->y][pos->x+1] = obj;
                    game_map[pos->y][pos->x] = ' ';
                    pos->x = pos->x+1;
                }
            } else if(game_map[pos->y][pos->x+1] == object){
                if(game_map[pos->y][pos->x+2] == ' '){
                    game_map[pos->y][pos->x+2] = object;
                    game_map[pos->y][pos->x+1] = obj;
                    game_map[pos->y][pos->x] = ' ';
                    pos->x = pos->x+1;
                }
                else if(game_map[pos->y][pos->x+2] == target){
                    game_map[pos->y][pos->x+2] = object;
                    game_map[pos->y][pos->x+1] = obj;
                    game_map[pos->y][pos->x] = ' ';
                    pos->x = pos->x+1;
                    //show_winning_message();
                }
            }
        }
    } else if (obj == opp.rival) {
        if (game_map[pos->y][pos->x] == obj) {
            if (opp.dest == point.symbol) {
                if (game_map[pos->y][pos->x] == obj) {
                    if (game_map[pos->y][pos->x + 1] == ' ') {
                        game_map[pos->y][pos->x] = ' ';
                        game_map[pos->y][pos->x + 1] = obj;
                        pos->x = pos->x + 1;
                    } else if (game_map[pos->y][pos->x + 1] == point.symbol) {
                        score[i] += point.score;
                        game_map[pos->y][pos->x + 1] = ' ';
                        random_gen(1, point.symbol);
                        game_map[pos->y][pos->x] = ' ';
                        game_map[pos->y][pos->x + 1] = obj;
                        pos->x = pos->x + 1;
                    } else if (game_map[pos->y][pos->x + 1] == deathblock) {
                        //
                    }
                }
            }
        }
    }
}
void move_left(struct dimension *pos, char obj,int score[],int i) {
    if (obj == character) {
        if (game_map[pos->y][pos->x] == obj) {
            if (game_map[pos->y][pos->x - 1] == ' ') {
                game_map[pos->y][pos->x] = ' ';
                game_map[pos->y][pos->x - 1] = obj;
                pos->x = pos->x - 1;
            } else if (game_map[pos->y][pos->x - 1] == point.symbol) {
                score[i] += point.score;
                game_map[pos->y][pos->x - 1] = ' ';
                random_gen(1, point.symbol);
                game_map[pos->y][pos->x] = ' ';
                game_map[pos->y][pos->x - 1] = obj;
                pos->x = pos->x - 1;
            } else if (game_map[pos->y][pos->x - 1] == deathblock) {
                lose_flag = 1;

            } else if(game_map[pos->y][pos->x-1] == moveblock){
                if(game_map[pos->y][pos->x-2] == ' '){
                    game_map[pos->y][pos->x-2] = moveblock;
                    game_map[pos->y][pos->x-1] = obj;
                    game_map[pos->y][pos->x] = ' ';
                    pos->x = pos->x-1;
                }
            } else if(game_map[pos->y][pos->x-1] == object){
                if(game_map[pos->y][pos->x-2] == ' '){
                    game_map[pos->y][pos->x-2] = object;
                    game_map[pos->y][pos->x-1] = obj;
                    game_map[pos->y][pos->x] = ' ';
                    pos->x = pos->x-1;
                }
                else if(game_map[pos->y][pos->x-2] == target){
                    game_map[pos->y][pos->x-2] = object;
                    game_map[pos->y][pos->x-1] = obj;
                    game_map[pos->y][pos->x] = ' ';
                    pos->x = pos->x-1;
                    //show_winning_message();
                }
            }
        }
    } else if (obj == opp.rival) {
        if (game_map[pos->y][pos->x] == obj) {
            if (opp.dest == point.symbol) {
                if (game_map[pos->y][pos->x] == obj) {
                    if (game_map[pos->y][pos->x - 1] == ' ') {
                        game_map[pos->y][pos->x] = ' ';
                        game_map[pos->y][pos->x - 1] = obj;
                        pos->x = pos->x - 1;
                    } else if (game_map[pos->y][pos->x - 1] == point.symbol) {
                        score[i] += point.score;
                        game_map[pos->y][pos->x - 1] = ' ';
                        random_gen(1, point.symbol);
                        game_map[pos->y][pos->x] = ' ';
                        game_map[pos->y][pos->x - 1] = obj;
                        pos->x = pos->x - 1;
                    } else if (game_map[pos->y][pos->x - 1] == deathblock) {
                        //
                    }
                }
            }
        }
    }
}