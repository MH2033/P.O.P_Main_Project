#include <conio.h>
#include <pthread.h>
#include <curses.h>
#include <string.h>
#include <dirent.h>
#include "core_functions/bass.h"
#include "game_console.h"
#include <dirent.h>
int score[2];
extern char solidblock, deathblock, moveblock, wall, target, object;
extern char up, down, left, right, character, Exit;
extern int time_limit, raindb, attack;
float t_limit;
extern struct rpoint point;
extern struct opponent opp;
extern struct put dblock;
extern char **game_map;
extern struct dimension player_pos;
extern struct dimension map_size;
extern struct opp_list *head_op;
int c = 0;
int move_key = 0;
void run_game() {
    c = 0;
    register int i;
    struct dimension player_last_pos;
    struct opp_list *temp;
    pthread_t thread[100], keyboard_thread;
    t_limit = time_limit + 0.001;
    print_map();
    show_start_window();
    pthread_create(&keyboard_thread, NULL, keyboard_handle, NULL);
    while (c != Exit && t_limit > 0) {
        player_last_pos.y = player_pos.y;
        player_last_pos.x = player_pos.x;
        move_player(move_key);
        if (c == '\e') {
            show_pause_window();
            if(c == Exit)
                break;
            pthread_create(&keyboard_thread, NULL, keyboard_handle, NULL);
        }
        if(c == dblock.key) {
            if(player_last_pos.y != player_pos.y || player_last_pos.x != player_pos.x)
                put_dblock(player_last_pos);
            c = 0;
        }
        i = 0;
        temp = head_op;
        while(temp != NULL){
            pthread_create(&thread[i], NULL, move_computer, &(temp -> pos));
            temp = temp -> next;
            i++;
        }
        while(i > 0) {
            pthread_join(thread[i], NULL);
            i--;
        }
        rain_db();
        print_map();
        delay(150);
        if(time_limit)
            t_limit -= 0.2;
    }
    pthread_join(keyboard_thread, NULL);
    chdir("..");
    chdir("..");
    endwin();
}
