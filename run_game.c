#include <conio.h>
#include <pthread.h>
#include <curses.h>
#include <string.h>
#include <dirent.h>
#include "core_functions/bass.h"
#include "game_console.h"
db* head;
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
char c = 0;
void run_game() {
    char  move_key = 0;
    register int i;
    struct dimension player_last_pos;
    struct opp_list *temp;
    HSTREAM move = BASS_StreamCreateFile(FALSE,"move.mp3", 0, 0, 0);
    pthread_t thread[100];
    t_limit = time_limit + 0.001;
    print_map();
    show_start_window();
    int flag = 0;
    while (c != Exit && t_limit > 0) {
        if (kbhit()) {
            c = getch();
            if(c == '\e')
                show_pause_window();
            else if(c == up || c == down || c == right || c == left) {
                if(c != move_key) {
                    move_key = c;
                    BASS_ChannelPlay(move, FALSE);
                }
            }
            else if(c == KEY_UP || c == KEY_DOWN || c == KEY_LEFT || c == KEY_RIGHT){
                //attack(c);
            }
        }
        player_last_pos.y = player_pos.y;
        player_last_pos.x = player_pos.x;
        move_player(move_key);
        if(c == dblock.key) {
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
        if (flag == 0)
            rain_db();
        flag = 0;
        print_map();
        delay(200);
        if(time_limit)
            t_limit -= 0.2;
    }

    chdir("..");
    chdir("..");
    endwin();
}
