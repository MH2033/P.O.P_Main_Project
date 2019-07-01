#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include "headers.h"
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
extern struct put dblock;
extern WINDOW *game_window;
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
                wattron(game_window, COLOR_PAIR(3));
                mvwaddch(game_window, i, j, game_map[i][j]);
                wattroff(game_window, COLOR_PAIR(3));
            }
            else if(game_map[i][j] == character){
                wattron(game_window, COLOR_PAIR(1));
                mvwaddch(game_window, i, j, game_map[i][j]);
                wattroff(game_window, COLOR_PAIR(1));
            }
            else if(game_map[i][j] == deathblock){
                wattron(game_window, COLOR_PAIR(3));
                mvwaddch(game_window, i, j, game_map[i][j]);
                wattroff(game_window, COLOR_PAIR(3));
            }
            else if(game_map[i][j] == solidblock || game_map[i][j] == wall){
                wattron(game_window, COLOR_PAIR(5));
                mvwaddch(game_window, i, j, game_map[i][j]);
                wattroff(game_window, COLOR_PAIR(5));
            }
            else if(game_map[i][j] == point.symbol){
                wattron(game_window, COLOR_PAIR(4));
                mvwaddch(game_window, i, j, game_map[i][j]);
                wattroff(game_window, COLOR_PAIR(4));
            }
            else{
                mvwaddch(game_window, i, j, game_map[i][j]);
            }
        }
    }
    if (dblock.limit){
        mvwprintw(game_window, map_size.y, 0, "remaining db: %d", dblock.limit);
    }
    if(point.symbol)
        mvwprintw(game_window, map_size.y+1, 0, "Score: %d", score[0]);
    if(time_limit)
        mvwprintw(game_window, map_size.y+2, 0, "Remaining time: %0.2f", t_limit);
    wrefresh(game_window);
    refresh();
}