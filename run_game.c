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

void run_game(){
    char c = 0;
    if(time_limit) {
        while (c != Exit && time_limit > 0) {
            system("cls");
            if (kbhit())
                c = getch();
            move_player(c);
            print_map();
            delay(200);
        }
    }
    else{
        while (c != Exit) {
            system("cls");
            if (kbhit())
                c = getch();
            move_player(c);
            print_map();
            delay(200);
        }
    }
}