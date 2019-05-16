#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_console.h"
char solidblock, deathblock, moveblock, wall, target, object;
char up, down, left, right, character, exit_key;
int time, raindb, attack;
struct rpoint point = {0, 0, 0};
struct opponent opp = {0, 0};
struct put dblock = {0, 0, 0};
int load_config(char *map, char *game){
    const char exps[18][15] = {"solidblock=", "deathblock=",
                               "moveblock=","wall=", "target=",
                               "object=", "up=", "down=","left=",
                               "right=", "character=", "exit=","time=",
                               "raindb=", "attack=", "rpoint=","opp=",
                               "put="};
    FILE *map_file, *game_file;
    map_file = fopen(map, "r");
    game_file = fopen(map, "r");
    if(game_file == NULL || map_file == NULL)
        return 1;
    load_map(map_file);
    fclose(map_file);
    return 0;
}