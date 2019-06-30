#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>
#include "game_console.h"
int main(int argc, char *argv[]) {
    int c;
    initialization();
    while(1) {
        show_main_menu();
        if (c = load_config(What_in_it())) {
            printf("Error: Wrong settings err code:%d", c);
            getchar();
            getchar();
            return 0;
        }
        ingame_init();
        run_game();
        cleanup();
    }
    _Exit(0);
}
