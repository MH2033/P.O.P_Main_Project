#include "headers.h"
extern int flagx_i,flagx_k,flagy_l,flagy_j;
struct dimension pos;
extern char **game_map;
extern char solidblock, deathblock, moveblock, wall, object;
extern char flag_last,up, down, left, right, character, Exit;
int c2;
extern struct opponent opp;
int A_I(int i,int j, struct dimension opp_pos) {
    int mx, my;
    if ((mx = i - opp_pos.y)< 0&&flagx_i ==0 && (game_map[opp_pos.y-1][opp_pos.x] == ' ' ||
    game_map[opp_pos.y-1][opp_pos.x]== opp.dest)) {
        c2 = up;
    } else if ((mx = i - opp_pos.y) > 0&& flagx_k == 0&& (game_map[opp_pos.y+1][opp_pos.x] == ' '
    || game_map[opp_pos.y+1][opp_pos.x] == opp.dest)) {
        c2 = down;
    } else if ((my = j - opp_pos.x) < 0&& flagy_j == 0&& (game_map[opp_pos.y][opp_pos.x-1] == ' '||
    game_map[opp_pos.y][opp_pos.x-1] == opp.dest)){
        c2 =left;
    } else if ((my = j - opp_pos.x) > 0&& flagy_l ==0&& (game_map[opp_pos.y][opp_pos.x+1] == ' '
    || game_map[opp_pos.y][opp_pos.x+1] == opp.dest)) {
        c2 = right;
    } else if(mx == 0&& flagx_i ==0 &&flag_last != up &&(game_map[opp_pos.y-1][opp_pos.x] == opp.dest
    || game_map[opp_pos.y-1][opp_pos.x] == ' ')){
        c2 =up;
    } else if(mx == 0&& flagx_k ==0 &&flag_last != down&& (game_map[opp_pos.y+1][opp_pos.x] == opp.dest
    || game_map[opp_pos.y+1][opp_pos.x] == ' ')){
        c2 =down;
    } else if(my == 0&& flagy_l ==0 &&flag_last != right&& (game_map[opp_pos.y][opp_pos.x+1] == ' '
    || game_map[opp_pos.y][opp_pos.x+1] == opp.dest)){
        c2 =right;
    } else if(my == 0&& flagy_j ==0 &&flag_last != left && (game_map[opp_pos.y][opp_pos.x-1] == ' '
    || game_map[opp_pos.y][opp_pos.x-1] == opp.dest)){
        c2 =left;
    }else if(flag_last != right && flagy_j ==0&&(game_map[opp_pos.y][opp_pos.x-1] == ' '
             || game_map[opp_pos.y][opp_pos.x-1] == opp.dest)){
        c2 = left;
    }else if(flag_last != right &&flagy_l == 0&&(game_map[opp_pos.y][opp_pos.x+1] == ' '||
             game_map[opp_pos.y][opp_pos.x+1] == opp.dest)){
        c2 = right;
    }else if(flag_last != down&&flagx_k == 0&&(game_map[opp_pos.y+1][opp_pos.x] == ' '
             || game_map[opp_pos.y+1][opp_pos.x] == opp.dest)){
        c2 = down;
    }else if(flag_last != up&&flagx_i == 0&&(game_map[opp_pos.y-1][opp_pos.x] == ' '
             || game_map[opp_pos.y-1][opp_pos.x] == opp.dest)){
        c2 = up;
    }else if(flag_last != right&&(game_map[opp_pos.y][opp_pos.x-1] == ' '
                                                 || game_map[opp_pos.y][opp_pos.x-1] == opp.dest)){
        c2 = left;
    }else if(flag_last != right&&(game_map[opp_pos.y][opp_pos.x+1] == ' '||
                                                 game_map[opp_pos.y][opp_pos.x+1] == opp.dest)){
        c2 = right;
    }else if(flag_last != down&&(game_map[opp_pos.y+1][opp_pos.x] == ' '
                                               || game_map[opp_pos.y+1][opp_pos.x] == opp.dest)){
        c2 = down;
    }else if(flag_last != up&&(game_map[opp_pos.y-1][opp_pos.x] == ' '
                                             || game_map[opp_pos.y-1][opp_pos.x] == opp.dest)){
        c2 = up;
    }
    return c2;
}