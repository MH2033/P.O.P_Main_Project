#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "game_console.h"
int score[2];
extern char solidblock, deathblock, moveblock, wall, target, object;
extern char up, down, left, right, character, Exit;
extern int time_limit, raindb, attack;
extern struct rpoint point;
extern struct opponent opp;
extern struct put dblock;
extern char **game_map;
extern struct dimension player_pos;

void run_game() {
    char c = 0;
    float t_limit;
    t_limit = time_limit + 0.001;
    while (c != Exit && t_limit > 0) {
        system("cls");
        if (kbhit())
            c = getch();
        move_player(c);
        print_map();
        delay(200);
        if(time_limit)
            t_limit -= 0.2;
    }
}