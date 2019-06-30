#include <conio.h>
#include <curses.h>
#include <pthread.h>
#include "game_console.h"
#include "core_functions/bass.h"
extern int c, move_key;
extern char up, down, left, right, character, Exit;
void *keyboard_handle(void *temp){
    HSTREAM move = BASS_StreamCreateFile(FALSE,"move.mp3", 0, 0, 0);
    while(1) {
        if (kbhit()) {
            c = getch();
            if(c == Exit || c == '\e')
                pthread_exit(0);
            else if (c == up || c == down || c == right || c == left) {
                if (c != move_key) {
                    move_key = c;
                    BASS_ChannelPlay(move, FALSE);
                    move_player(move_key);
                }
            } else if (c == KEY_UP || c == KEY_DOWN || c == KEY_LEFT || c == KEY_RIGHT) {
                att(c);
            }
            refresh();
        }
    }
}