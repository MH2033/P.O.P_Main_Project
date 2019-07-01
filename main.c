#include <stdlib.h>
#include <curses.h>
#include <unistd.h>
#include "game_console.h"
int main(int argc, char *argv[]) {
    int c;
    initialization();
    init_pair(3, COLOR_RED, COLOR_BLACK);
    while(1) {
        show_main_menu();
        if ((c = load_config(What_in_it()))) {
            clear();
            attron(COLOR_PAIR(3));
            printw("Error: corrupted game files error code: %d", c);
            printw("\nPress any key to return...");
            attroff(COLOR_PAIR(3));
            getch();
            chdir("..");
            chdir("..");
            cleanup();
            continue;
        }
        ingame_init();
        run_game();
        cleanup();
    }
}
