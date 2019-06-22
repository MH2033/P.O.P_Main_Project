#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game_console.h"

extern int randomness;
struct dimension map_size;
extern char **game_map;

void random_gen(int n,char b){
    int counter1 = 0,ran_x,ran_y;
    srand(randomness);
    randomness++;
    while(counter1 < n){
        ran_x = (rand() % (map_size.x - 2)) + 1;
        ran_y = (rand() % (map_size.y - 2)) + 1;
        if (game_map[ran_y][ran_x] == ' ') {
            game_map[ran_y][ran_x] = b;
            counter1++;
        }
        else {
            srand(randomness);
            randomness++;
        }
    }
}