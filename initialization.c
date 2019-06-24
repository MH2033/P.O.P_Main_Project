#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game_console.h"

extern char solidblock, deathblock, moveblock, wall, target, object;
extern char up, down, left, right, character, Exit;
extern int time_limit, raindb, attack;
extern struct rpoint point;
extern struct opponent opp;
extern struct put dblock;
extern struct dimension map_size;
extern char **game_map;
extern char **buffer;
int randomness;

void initialization(){
    register int i, j;
    char arg[100];
    sprintf(arg, "MODE %d,%d", map_size.x+1, map_size.y+1);
    hidecursor();
    system(arg);
    randomness = time(0);
    if(point.symbol)
        random_gen(point.num, point.symbol);
    system("cls");
    for(i = 0; i < map_size.y; i++){
        for(j = 0; j < map_size.x; j++){
            putchar(game_map[i][j]);
            buffer[i][j] = game_map[i][j];
        }
        putchar('\n');
    }
}