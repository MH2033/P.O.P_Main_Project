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
int randomness;

void initialization(){
    hidecursor();
    randomness = time(0);
    if(point.symbol)
        random_gen(point.num, point.symbol);
}