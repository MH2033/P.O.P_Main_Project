#include <conio.h>
#include <pthread.h>
#include <curses.h>
#include <string.h>
#include "core_functions/bass.h"
#include "game_console.h"
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

void run_game() {
    char c = 0, move_key = 0;
    register int i;
    struct dimension player_last_pos;
    struct opp_list *temp;
    char mesg1[] = "Paused";
    char mesg2[] =  "Press any key to continue";
    char mesg3[] = "Game starts in";
    char mesg4[] = "3";
    struct dimension win_size;
    HSTREAM move = BASS_StreamCreateFile(FALSE,"move.mp3", 0, 0, 0);
    win_size.x = 2*map_size.x/3;
    win_size.y = map_size.y/3+1;
    WINDOW *pause_win = newwin(win_size.y, win_size.x ,map_size.y/3, map_size.x/5 - 1);
    pthread_t thread[100];
    t_limit = time_limit + 0.001;
    show_start_window();
    while (c != Exit && t_limit > 0) {
        if (kbhit()) {
            c = getch();
            if(c == '\e'){
                box(pause_win, ' ', ' ');
                mvwhline(pause_win, 0,0,'!',win_size.x);
                mvwhline(pause_win, win_size.y-1,0,'!',win_size.x);
                mvwvline(pause_win,0, 0, '!', win_size.y);
                mvwvline(pause_win,0, win_size.x-1, '!', win_size.y);
                mvwprintw(pause_win, 1,(win_size.x-strlen(mesg1))/2,"%s",mesg1);
                mvwprintw(pause_win, 2,(win_size.x-strlen(mesg2))/2,"%s",mesg2);
                wrefresh(pause_win);
                c = getch();
                endwin();
                clear();
                refresh();
            }
            if(c == up || c == down || c == right || c == left) {
                move_key = c;
                BASS_ChannelPlay(move, FALSE);
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
        //move_computer(&(head_op -> pos));
        //move_computer(&(head_op -> next -> pos));
        //move_computer(&(head_op -> next -> next -> pos));
        while(i > 0) {
            pthread_join(thread[i], NULL);
            i--;
        }
        print_map();
        delay(200);
        if(time_limit)
            t_limit -= 0.2;
    }
}