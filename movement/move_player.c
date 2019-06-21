#include "game_console.h"

extern char up, down, left, right, character, Exit;
extern struct dimension player_pos;
extern int score[2];
void move_player(char c){
    if(c == up)
        move_up(player_pos.x, player_pos.y, character, score, 0);
    else if(c == down)
        move_down(player_pos.x, player_pos.y, character, score, 0);
    else if(c == right)
        move_right(player_pos.x, player_pos.y, character, score, 0);
    else if(c == left)
        move_left(player_pos.x, player_pos.y, character, score, 0);
}