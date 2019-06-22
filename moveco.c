#include "game_console.h"
static int flagx_i,flagx_k,flagy_l,flagy_j;
struct dimension pos;
extern char **game_map;
extern char solidblock, deathblock, moveblock, wall, object;
extern char up, down, left, right, character, Exit;
extern struct opponent opp;
int A_I(int i,int j, struct dimension opp_pos) {
    int mx, my,c2;
    if ((mx = i - opp_pos.y)< 0&&flagx_i ==0 && (game_map[opp_pos.y-1][opp_pos.x] == ' ' ||
    game_map[opp_pos.y-1][opp_pos.x]== opp.dest)) {
        c2 = up;
        flagx_k = 1;
        flagy_j = 0;
        flagy_l = 0;
    } else if ((mx = i - opp_pos.y) > 0&& flagx_k == 0 && (game_map[opp_pos.y+1][opp_pos.x] == ' '
    || game_map[opp_pos.y+1][opp_pos.x] == opp.dest)) {
        c2 = down;
        flagx_i = 1;
        flagy_j = 0;
        flagy_l = 0;
    } else if ((my = j - opp_pos.x) < 0&& flagy_j == 0 && (game_map[opp_pos.y][opp_pos.x-1] == ' '||
    game_map[opp_pos.y][opp_pos.x-1] == opp.dest)){
        c2 =left;
        flagx_i = 0;
        flagx_k = 0;
        flagy_l = 1;
    } else if ((my = j - opp_pos.x) > 0&& flagy_l ==0 && (game_map[opp_pos.y][opp_pos.x+1] == ' '
    || game_map[opp_pos.y][opp_pos.x+1] == opp.dest)) {
        c2 = right;
        flagx_i = 0;
        flagx_k = 0;
        flagy_j = 1;
    } else if(mx == 0&& flagx_i ==0 && (game_map[opp_pos.y-1][opp_pos.x] == opp.dest
    || game_map[opp_pos.y-1][opp_pos.x] == ' ')){
        flagx_k = 1;
        flagy_j = 0;
        flagy_l = 0;
        c2 =up;
    } else if(mx == 0&& flagx_k ==0 && (game_map[opp_pos.y+1][opp_pos.x] == opp.dest
    || game_map[opp_pos.y+1][opp_pos.x] == ' ')){
        flagx_i = 1;
        flagy_j = 0;
        flagy_l = 0;
        c2 =down;
    } else if(my == 0&& flagy_l ==0 && (game_map[opp_pos.y][opp_pos.x+1] == ' '
    || game_map[opp_pos.y][opp_pos.x+1] == opp.dest)){
        flagy_j = 1;
        flagx_i = 0;
        flagx_k = 0;
        c2 =right;
    } else if(my == 0&& flagy_j ==0 && (game_map[opp_pos.y][opp_pos.x-1] == ' '
    || game_map[opp_pos.y][opp_pos.x-1] == opp.dest)){
        flagy_l = 1;
        flagx_i = 0;
        flagx_k = 0;
        c2 =left;
    }else if(game_map[opp_pos.y][opp_pos.x-1] == ' '
    || game_map[opp_pos.y][opp_pos.x-1] == opp.dest){
        c2 = left;
        flagy_j = 0;
        flagy_l = 1;
        flagx_i = 0;
        flagx_k = 0;
    }else if(game_map[opp_pos.y][opp_pos.x+1] == ' '||
    game_map[opp_pos.y][opp_pos.x+1] == opp.dest){
        c2 = right;
        flagy_j = 1;
        flagx_i = 0;
        flagx_k = 0;
        flagy_l = 0;
    }else if(game_map[opp_pos.y+1][opp_pos.x] == ' '
    || game_map[opp_pos.y+1][opp_pos.x] == opp.dest){
        flagx_i = 1;
        flagy_j = 0;
        flagy_l = 0;
        flagx_k = 0;
        c2 = down;
    }else if(game_map[opp_pos.y-1][opp_pos.x] == ' '
    || game_map[opp_pos.y-1][opp_pos.x] == opp.dest){
        flagx_i = 1;
        flagy_j = 0;
        flagy_l = 0;
        flagx_i = 0;
        c2 = down;
    }
    if((i - opp_pos.y) == 0){
        flagy_j = 0;
        flagy_l = 0;
    }
    if((j - opp_pos.x) == 0){
        flagx_i = 0;
        flagx_k = 0;
    }
    return c2;
}