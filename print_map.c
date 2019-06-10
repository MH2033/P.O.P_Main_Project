#include <stdio.h>
#include <stdlib.h>
#include "game_console.h"

extern char **game_map;
extern struct dimension map_size;

void print_map(){
    int i, j;
    for(i = 0; i < map_size.y; i++){
        for(j = 0; j < map_size.x; j++){
            putchar(game_map[i][j]);
        }
        putchar('\n');
    }
}