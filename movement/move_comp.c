#include "game_console.h"
extern char up,down,left,right;
extern struct opponent opp;
extern int score[2];
void move_computer(struct dimension *op){
    if (FindCloseFood(*op) == up)
        move_up(op,opp.rival,score,1);
    else if (FindCloseFood(*op) == down)
        move_down(op,opp.rival,score,1);
    else if (FindCloseFood(*op) == left)
        move_left(op,opp.rival,score,1);
    else if (FindCloseFood(*op) == right)
        move_right(op,opp.rival,score,1);
}
