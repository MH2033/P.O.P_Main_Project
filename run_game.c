#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <pthread.h>
#include "game_console.h"
int score[2];
extern char solidblock, deathblock, moveblock, wall, target, object;
extern char up, down, left, right, character, Exit;
extern int time_limit, raindb, attack;
extern struct rpoint point;
extern struct opponent opp;
extern struct put dblock;
extern char **game_map;
extern struct dimension player_pos;
extern struct opp_list *head_op;

void run_game() {
    char c = 0, move_key = 0, i;
    struct dimension player_last_pos;
    struct opp_list *temp;
    float t_limit;
    pthread_t thread[100];
    t_limit = time_limit + 0.001;
    while (c != Exit && t_limit > 0) {
        system("cls");
        if (kbhit()) {
            c = getch();
            if(c == up || c == down || c == right || c == left)
                move_key = c;
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
        //pthread_join(thread[i], NULL);
        i = 0;
        print_map();
        delay(200);
        if(time_limit)
            t_limit -= 0.2;
    }
}