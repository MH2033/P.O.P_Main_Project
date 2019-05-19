#include <stdio.h>
#include <stdlib.h>
#include "../game_console.h"

char **game_map;
int load_map(FILE *map_file){
    struct dimension map_size = {0, 0};
    int c, i = 0, j = 0;
    while((c = getc(map_file)) != 'x')
        map_size.x = map_size.x * 10 + c - '0';
    while((c = getc(map_file)) != '\n')
        map_size.y = map_size.y * 10 + c - '0';
    game_map = (char **)malloc(sizeof(char *) * map_size.x);
    for(i = 0; i < map_size.x; i++){
        game_map[i] = (char *)malloc(sizeof(char) * map_size.y);
    }
    i = 0;
    while((c = getc(map_file)) != EOF){
        if(c != '\n'){
            game_map[i][j] = c;
            j++;
        }
        else {
            if(j != map_size.x)
                return 1;
            i++;
            j = 0;
        }
    }
    if(i != map_size.y - 1){
        return 1;
    }
    return 0;
}