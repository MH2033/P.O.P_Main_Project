#include "game_console.h"
extern char up,down,left,right;
extern struct opponent opp;
extern int score[2];
void *move_computer(void *op){
    struct dimension *temp = (struct dimension *)op;
    if (FindCloseFood(*temp) == up)
        move_up(op,opp.rival,score,1);
    else if (FindCloseFood(*temp) == down)
        move_down(op,opp.rival,score,1);
    else if (FindCloseFood(*temp) == left)
        move_left(op,opp.rival,score,1);
    else if (FindCloseFood(*temp) == right)
        move_right(op,opp.rival,score,1);
}
