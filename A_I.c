#include "headers.h"
struct dimension pos;
extern char **game_map;
extern char solidblock, deathblock, moveblock, wall, object;
extern char up, down, left, right, character, Exit;
extern struct opponent opp;
int A_I(int i,int j, struct need ops) {
    int mx, my,c2;
    int x_p_y = ops.ops.y;
    int  x_p_x = ops.ops.x;
    if (((mx = i - x_p_y) < 0)&&(ops.opp_s.flagx_k ==0) && (game_map[x_p_y-1][x_p_x] == ' ' || game_map[x_p_y-1][x_p_x] == opp.dest)) {
        c2 = up;
        ops.opp_s.flagx_k = 1;
        ops.opp_s.flagy_j =0;
        ops.opp_s.flagy_l =0;
    } else if (((my = j - x_p_x) > 0&& ops.opp_s.flagy_l ==0) && (game_map[x_p_y][x_p_x+1] == ' ' || game_map[x_p_y][x_p_x+1] == opp.dest)) {
        c2 = right;
        ops.opp_s.flagx_k= 0;
        ops.opp_s.flagx_k =0;
        ops.opp_s.flagy_j = 1;
    } else if ((((mx = i - x_p_y) > 0)&& (ops.opp_s.flagx_k == 0)) && (game_map[x_p_y+1][x_p_x] == ' ' || game_map[x_p_y+1][x_p_x] == opp.dest)) {
        c2 = down;
        ops.opp_s.flagx_k = 1;
        ops.opp_s.flagy_j = 0;
        ops.opp_s.flagy_l = 0;
    } else if (((my = j - x_p_x) < 0&& ops.opp_s.flagy_j == 0) && (game_map[x_p_y][x_p_x-1] == ' ' || game_map[x_p_y][x_p_x-1] == opp.dest)){
        c2 =left;
        ops.opp_s.flagx_k = 0;
        ops.opp_s.flagx_k = 0;
        ops.opp_s.flagy_l = 1;
    } else if((mx == 0&& ops.opp_s.flagx_k ==0 )&& (game_map[x_p_y-1][x_p_x] == ' ' || game_map[x_p_y-1][x_p_x] == opp.dest)){
        ops.opp_s.flagx_k = 1;
        ops.opp_s.flagy_j = 0;
        ops.opp_s.flagy_l = 0;
        c2 =up;
    } else if((my == 0&& ops.opp_s.flagy_j ==0) && (game_map[x_p_y][x_p_x-1] == ' ' || game_map[x_p_y][x_p_x-1] == opp.dest)){
        ops.opp_s.flagy_l = 1;
        ops.opp_s.flagx_k = 0;
        ops.opp_s.flagx_k = 0;
        c2 =left;
    } else if((mx == 0&& ops.opp_s.flagx_k ==0) && (game_map[x_p_y+1][x_p_x] == ' ' || game_map[x_p_y+1][x_p_x] == opp.dest)){
        ops.opp_s.flagx_k = 1;
        ops.opp_s.flagy_j = 0;
        ops.opp_s.flagy_l = 0;
        c2 =down;
    } else if((my == 0&& ops.opp_s.flagy_l ==0) && (game_map[x_p_y][x_p_x+1] == ' ' || game_map[x_p_y][x_p_x+1] == opp.dest)){
        ops.opp_s.flagy_j = 1;
        ops.opp_s.flagx_k = 0;
        ops.opp_s.flagx_k = 0;
        c2 =right;
    }else if(ops.opp_s.flagy_j==0 &&(game_map[x_p_y][x_p_x-1] == ' ' || game_map[x_p_y][x_p_x-1] == opp.dest)){
        c2 = left;
        ops.opp_s.flagy_j = 0;
        ops.opp_s.flagy_l = 1;
        ops.opp_s.flagx_k = 0;
        ops.opp_s.flagx_k = 0;
    }else if(ops.opp_s.flagx_k == 0 &&(game_map[x_p_y+1][x_p_x] == ' ' || game_map[x_p_y+1][x_p_x] == opp.dest)){
        ops.opp_s.flagx_k = 1;
        ops.opp_s.flagy_j = 0;
        ops.opp_s.flagy_l = 0;
        ops.opp_s.flagx_k = 0;
        c2 = down;
    }else if(ops.opp_s.flagy_l== 0 &&(game_map[x_p_y][x_p_x+1] == ' ' || game_map[x_p_y][x_p_x+1] == opp.dest)){
        c2 = right;
        ops.opp_s.flagy_j = 1;
        ops.opp_s.flagx_k = 0;
        ops.opp_s.flagx_k = 0;
        ops.opp_s.flagy_l = 0;
    }else if(ops.opp_s.flagx_k == 0 &&(game_map[x_p_y-1][x_p_x] == ' ' || game_map[x_p_y-1][x_p_x] == opp.dest)){
        ops.opp_s.flagx_k = 1;
        ops.opp_s.flagy_j = 0;
        ops.opp_s.flagy_l = 0;
        ops.opp_s.flagx_k = 0;
        c2 = up;
    }else if(game_map[x_p_y][x_p_x-1] == ' ' || game_map[x_p_y][x_p_x-1] == opp.dest){
        c2 = left;
        ops.opp_s.flagy_j = 0;
        ops.opp_s.flagy_l = 1;
        ops.opp_s.flagx_k = 0;
        ops.opp_s.flagx_k = 0;
    }else if(game_map[x_p_y+1][x_p_x] == ' ' || game_map[x_p_y+1][x_p_x] == opp.dest){
        ops.opp_s.flagx_k = 1;
        ops.opp_s.flagy_j = 0;
        ops.opp_s.flagy_l = 0;
        ops.opp_s.flagx_k = 0;
        c2 = down;
    }else if(game_map[x_p_y][x_p_x+1] == ' ' || game_map[x_p_y][x_p_x+1] == opp.dest){
        c2 = right;
        ops.opp_s.flagy_j = 1;
        ops.opp_s.flagx_k = 0;
        ops.opp_s.flagx_k = 0;
        ops.opp_s.flagy_l = 0;
    }else if(game_map[x_p_y-1][x_p_x] == ' ' || game_map[x_p_y-1][x_p_x] == opp.dest){
        ops.opp_s.flagx_k = 1;
        ops.opp_s.flagy_j = 0;
        ops.opp_s.flagy_l = 0;
        ops.opp_s.flagx_k = 0;
        c2 = up;
    }
    return c2;
}