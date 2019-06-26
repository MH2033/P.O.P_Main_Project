#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include "game_console.h"

extern char solidblock, deathblock, moveblock, wall, target, object;
extern char up, down, left, right, character, Exit;
extern int time_limit, raindb, attack;
extern struct rpoint point;
extern struct opponent opp;
extern struct put dblock;
extern struct dimension map_size;
extern char **game_map;
int randomness;

void initialization(){
    char arg[100];
    sprintf(arg, "MODE %d,%d", map_size.x+1, map_size.y);
    //Terminal initializations
        system(arg);
        initscr();
        start_color();
        use_default_colors();
        curs_set(0);
        cbreak();
        noecho();
        clear();
    //
    randomness = time(0);
    if(point.symbol)
        random_gen(point.num, point.symbol);
}