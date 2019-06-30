#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include "game_console.h"
extern int score[];
struct rpoint point;
struct opponent opp;
extern char **game_map;
extern struct dimension map_size;
extern float t_limit;
extern int time_limit;
extern int global_counter;
extern char character, deathblock, solidblock, wall;
extern int c2,flagx_i,flagx_k,flagy_l,flagy_j;
void print_map(){
    register int i, j;
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(5, COLOR_BLUE, COLOR_BLACK);
    for(i = 0; i < map_size.y; i++){
        for(j = 0; j < map_size.x; j++) {
            if(game_map[i][j] == opp.rival) {
                attron(COLOR_PAIR(3));
                mvaddch(i, j, game_map[i][j]);
                attroff(COLOR_PAIR(3));
            }
            else if(game_map[i][j] == character){
                attron(COLOR_PAIR(1));
                mvaddch(i, j, game_map[i][j]);
                attroff(COLOR_PAIR(1));
            }
            else if(game_map[i][j] == deathblock){
                attron(COLOR_PAIR(3));
                mvaddch(i, j, game_map[i][j]);
                attroff(COLOR_PAIR(3));
            }
            else if(game_map[i][j] == solidblock || game_map[i][j] == wall){
                attron(COLOR_PAIR(5));
                mvaddch(i, j, game_map[i][j]);
                attroff(COLOR_PAIR(5));
            }
            else if(game_map[i][j] == point.symbol){
                attron(COLOR_PAIR(4));
                mvaddch(i, j, game_map[i][j]);
                attroff(COLOR_PAIR(4));
            }
            else{
                mvaddch(i, j, game_map[i][j]);
            }
        }
    }
    if(point.symbol)
        mvprintw(map_size.y+1, 0, "Score: %d", score[0]);
    if(time_limit)
        mvprintw(map_size.y+2, 0, "Remaining time: %0.2f", t_limit);
    refresh();
}