#include <stdio.h>
#include "game_console.h"
int main(int argc, char *argv[]) {
    if(load_config("map.txt", "game.txt")) {
        printf("Error: Can't open files");
        return 0;
    }
    return 0;
}