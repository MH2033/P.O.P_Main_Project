#include "headers.h"
extern char character;
extern char deathblock;
extern char **game_map;
void crash(raindbd* head){
    raindbd* temp = head;
    int x = temp->head.x,y = temp->head.y;
    if (game_map[y][x] == character){
        game_over();
    }
}