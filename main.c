#include <stdio.h>
#include "game_console.h"
int main(int argc, char *argv[]) {
    if(load_config("map.txt", "game_map.txt")) {
        printf("Error: Wrong settings");
        return 0;
    }
    initialization();
    print_map();
    return 0;
}