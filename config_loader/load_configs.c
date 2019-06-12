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
char map[100] = "\\map";
char game[100] = "\\game";
int load_config(char *directory){
    FILE *map_file, *game_file;
    strcat(directory,map);
    strcat(directory,game);
    map_file = fopen(map, "r");
    game_file = fopen(game, "r");
    if(game_file == NULL || map_file == NULL)
        return 1;
    if(load_map(map_file))
        return 1;
    fclose(map_file);
    if(load_settings(game_file))
        return 1;
    fclose(game_file);
    return 0;
}