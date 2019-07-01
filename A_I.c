#include "headers.h"
struct dimension pos;
extern char **game_map;
extern char solidblock, deathblock, moveblock, wall, object;
extern char up, down, left, right, character, Exit;
extern struct opponent opp;
int A_I(int i,int j, struct dimension opp_pos) {
    int mx, my,c2;
    static int flagx_i,flagx_k,flagy_l,flagy_j;
    int x_p_y = opp_pos.y ;
    int  x_p_x = opp_pos.x;
    if (((mx = i - x_p_y) < 0)&&(flagx_i ==0) && (game_map[x_p_y-1][x_p_x] == ' ' || game_map[x_p_y-1][x_p_x] == opp.dest)) {
        c2 = up;
        flagx_k = 1;
        flagy_j = 0;
        flagy_l = 0;
    } else if (((my = j - x_p_x) > 0&& flagy_l ==0) && (game_map[x_p_y][x_p_x+1] == ' ' || game_map[x_p_y][x_p_x+1] == opp.dest)) {
        c2 = right;
        flagx_i = 0;
        flagx_k = 0;
        flagy_j = 1;
    } else if ((((mx = i - x_p_y) > 0)&& (flagx_k == 0)) && (game_map[x_p_y+1][x_p_x] == ' ' || game_map[x_p_y+1][x_p_x] == opp.dest)) {
        c2 = down;
        flagx_i = 1;
        flagy_j = 0;
        flagy_l = 0;
    } else if (((my = j - x_p_x) < 0&& flagy_j == 0) && (game_map[x_p_y][x_p_x-1] == ' ' || game_map[x_p_y][x_p_x-1] == opp.dest)){
        c2 =left;
        flagx_i = 0;
        flagx_k = 0;
        flagy_l = 1;
    } else if((mx == 0&& flagx_i ==0 )&& (game_map[x_p_y-1][x_p_x] == ' ' || game_map[x_p_y-1][x_p_x] == opp.dest)){
        flagx_k = 1;
        flagy_j = 0;
        flagy_l = 0;
        c2 =up;
    } else if((my == 0&& flagy_j ==0) && (game_map[x_p_y][x_p_x-1] == ' ' || game_map[x_p_y][x_p_x-1] == opp.dest)){
        flagy_l = 1;
        flagx_i = 0;
        flagx_k = 0;
        c2 =left;
    } else if((mx == 0&& flagx_k ==0) && (game_map[x_p_y+1][x_p_x] == ' ' || game_map[x_p_y+1][x_p_x] == opp.dest)){
        flagx_i = 1;
        flagy_j = 0;
        flagy_l = 0;
        c2 =down;
    } else if((my == 0&& flagy_l ==0) && (game_map[x_p_y][x_p_x+1] == ' ' || game_map[x_p_y][x_p_x+1] == opp.dest)){
        flagy_j = 1;
        flagx_i = 0;
        flagx_k = 0;
        c2 =right;
    }else if(flagy_j==0 &&(game_map[x_p_y][x_p_x-1] == ' ' || game_map[x_p_y][x_p_x-1] == opp.dest)){
        c2 = left;
        flagy_j = 0;
        flagy_l = 1;
        flagx_i = 0;
        flagx_k = 0;
    }else if(flagx_k == 0 &&(game_map[x_p_y+1][x_p_x] == ' ' || game_map[x_p_y+1][x_p_x] == opp.dest)){
        flagx_i = 1;
        flagy_j = 0;
        flagy_l = 0;
        flagx_k = 0;
        c2 = down;
    }else if(flagy_l== 0 &&(game_map[x_p_y][x_p_x+1] == ' ' || game_map[x_p_y][x_p_x+1] == opp.dest)){
        c2 = right;
        flagy_j = 1;
        flagx_i = 0;
        flagx_k = 0;
        flagy_l = 0;
    }else if(flagx_i == 0 &&(game_map[x_p_y-1][x_p_x] == ' ' || game_map[x_p_y-1][x_p_x] == opp.dest)){
        flagx_k = 1;
        flagy_j = 0;
        flagy_l = 0;
        flagx_i = 0;
        c2 = up;
    }else if(game_map[x_p_y][x_p_x-1] == ' ' || game_map[x_p_y][x_p_x-1] == opp.dest){
        c2 = left;
        flagy_j = 0;
        flagy_l = 1;
        flagx_i = 0;
        flagx_k = 0;
    }else if(game_map[x_p_y+1][x_p_x] == ' ' || game_map[x_p_y+1][x_p_x] == opp.dest){
        flagx_i = 1;
        flagy_j = 0;
        flagy_l = 0;
        flagx_k = 0;
        c2 = down;
    }else if(game_map[x_p_y][x_p_x+1] == ' ' || game_map[x_p_y][x_p_x+1] == opp.dest){
        c2 = right;
        flagy_j = 1;
        flagx_i = 0;
        flagx_k = 0;
        flagy_l = 0;
    }else if(game_map[x_p_y-1][x_p_x] == ' ' || game_map[x_p_y-1][x_p_x] == opp.dest){
        flagx_k = 1;
        flagy_j = 0;
        flagy_l = 0;
        flagx_i = 0;
        c2 = up;
    }
    debug_output(opp_pos.y,opp_pos.x);
    return c2;
}