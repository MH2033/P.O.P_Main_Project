#include "game_console.h"
#include <pthread.h>
extern char up,down,left,right;
extern struct opponent opp;
extern int score[2];
int flagx_k ,flagy_j ,flagy_l ,flagx_i;
char flag_last;
extern pthread_mutex_t lock;
void *move_computer(void *op){
    if (flagx_i == 1)
        flag_last = down;
    else if (flagx_k == 1)
        flag_last = up;
    else if (flagy_l ==1)
        flag_last = left;
    else if (flagy_j == 1)
        flag_last == right;
    if (FindCloseFood(*(struct dimension *)op) == up) {
        move_up(op, opp.rival, score, 1);
        flagx_k = 1;
        flagy_j = 0;
        flagy_l = 0;
        flagx_i = 0;
    }
    else if (FindCloseFood(*(struct dimension *)op) == down) {
        move_down(op, opp.rival, score, 1);
        flagx_k = 0;
        flagy_j = 0;
        flagy_l = 0;
        flagx_i = 1;
    }
    else if (FindCloseFood(*(struct dimension *)op) == left) {
        move_left(op, opp.rival, score, 1);
        flagx_k = 0;
        flagy_j = 0;
        flagy_l = 1;
        flagx_i = 0;
    }
    else if (FindCloseFood(*(struct dimension *)op) == right) {
        move_right(op, opp.rival, score, 1);
        flagx_k = 0;
        flagy_j = 1;
        flagy_l = 0;
        flagx_i = 0;
    }
    return NULL;
}
