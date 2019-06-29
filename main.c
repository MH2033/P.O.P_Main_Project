#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>
#include "game_console.h"
int main(int argc, char *argv[]) {
    int c;
    while(1) {
        if (c = load_config(What_in_it())) {
            printf("Error: Wrong settings err code:%d", c);
            getchar();
            getchar();
            return 0;
        }
        initialization();
        run_game();
        clean_up();
    }
    _Exit(0);
}
