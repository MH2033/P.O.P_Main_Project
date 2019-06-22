#include "game_console.h"
static int flagx_i,flagx_k,flagy_l,flagy_j;
struct dimension pos;
extern char **game_map;
extern char solidblock, deathblock, moveblock, wall, target, object;
extern char up, down, left, right, character, Exit;
int A_I(int i,int j, struct dimension pos) {
    int mx, my,c2;
    if ((mx = i - pos.y)< 0&&flagx_i ==0 && (game_map[pos.y-1][pos.x] == ' ' ||
    game_map[pos.y-1][pos.x]== target)) {
        c2 = up;
        flagx_k = 1;
        flagy_j = 0;
        flagy_l = 0;
    } else if ((mx = i - pos.y) > 0&& flagx_k == 0 && (game_map[pos.y+1][pos.x] == ' '
    || game_map[pos.y+1][pos.x] == target)) {
        c2 = down;
        flagx_i = 1;
        flagy_j = 0;
        flagy_l = 0;
    } else if ((my = j - pos.x) < 0&& flagy_j == 0 && (game_map[pos.y][pos.x-1] == ' '||
    game_map[pos.y][pos.x-1] == target)){
        c2 =left;
        flagx_i = 0;
        flagx_k = 0;
        flagy_l = 1;
    } else if ((my = j - pos.x) > 0&& flagy_l ==0 && (game_map[pos.y][pos.x+1] == ' '
    || game_map[pos.y][pos.x+1] == target)) {
        c2 = right;
        flagx_i = 0;
        flagx_k = 0;
        flagy_j = 1;
    } else if(mx == 0&& flagx_i ==0 && (game_map[pos.y-1][pos.x] == target
    || game_map[pos.y-1][pos.x] == ' ')){
        flagx_k = 1;
        flagy_j = 0;
        flagy_l = 0;
        c2 =up;
    } else if(mx == 0&& flagx_k ==0 && (game_map[pos.y+1][pos.x] == target
    || game_map[pos.y+1][pos.x] == ' ')){
        flagx_i = 1;
        flagy_j = 0;
        flagy_l = 0;
        c2 =down;
    } else if(my == 0&& flagy_l ==0 && (game_map[pos.y][pos.x+1] == ' '
    || game_map[pos.y][pos.x+1] == target)){
        flagy_j = 1;
        flagx_i = 0;
        flagx_k = 0;
        c2 =right;
    } else if(my == 0&& flagy_j ==0 && (game_map[pos.y][pos.x-1] == ' '
    || game_map[pos.y][pos.x-1] == target)){
        flagy_l = 1;
        flagx_i = 0;
        flagx_k = 0;
        c2 =left;
    }else if(game_map[pos.y][pos.x-1] == ' '
    || game_map[pos.y][pos.x-1] == target){
        c2 = left;
        flagy_j = 0;
        flagy_l = 1;
        flagx_i = 0;
        flagx_k = 0;
    }else if(game_map[pos.y][pos.x+1] == ' '||
    game_map[pos.y][pos.x+1] == target){
        c2 = right;
        flagy_j = 1;
        flagx_i = 0;
        flagx_k = 0;
        flagy_l = 0;
    }else if(game_map[pos.y+1][pos.x] == ' '
    || game_map[pos.y+1][pos.x] == target){
        flagx_i = 1;
        flagy_j = 0;
        flagy_l = 0;
        flagx_k = 0;
        c2 = down;
    }else if(game_map[pos.y-1][pos.x] == ' '
    || game_map[pos.y-1][pos.x] == target){
        flagx_i = 1;
        flagy_j = 0;
        flagy_l = 0;
        flagx_i = 0;
        c2 = down;
    }
    if((i - pos.y) == 0){
        flagy_j = 0;
        flagy_l = 0;
    }
    if((j - pos.x) == 0){
        flagx_i = 0;
        flagx_k = 0;
    }
    return c2;
}