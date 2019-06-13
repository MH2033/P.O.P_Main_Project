#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../game_console.h"

char solidblock, deathblock, moveblock, wall, target, object;
char up, down, left, right, character, Exit;
int time_limit, raindb, attack;
struct rpoint point = {0, 0, 0};
struct opponent opp = {0, 0};
struct put dblock = {0, 0, 0};
char map[100] = "map.txt";
char game[100] = "game.txt";
int load_config(char *directory){
    FILE *map_file, *game_file;
    cd(directory);
    map_file = fopen(map, "r");
    game_file = fopen(game, "r");
    if(game_file == NULL || map_file == NULL) {
        return 1;
    }
    if(load_settings(game_file))
        return 1;
    fclose(game_file);
    if(load_map(map_file))
        return 1;
    fclose(map_file);
    return 0;
}