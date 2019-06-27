#include <time.h>
#include <curses.h>
#include "game_console.h"
#include "core_functions/bass.h"

extern char solidblock, deathblock, moveblock, wall, target, object;
extern char up, down, left, right, character, Exit;
extern int time_limit, raindb, attack;
extern struct rpoint point;
extern struct opponent opp;
extern struct put dblock;
extern struct dimension map_size;
extern char **game_map;
int randomness;

void initialization(){
    //Terminal initializations
        initscr();
        resize_term(map_size.y, map_size.x+1);
        start_color();
        use_default_colors();
        curs_set(0);
        cbreak();
        noecho();
        clear();
    //
    //Sound initialization
        BASS_Init(-1, 44100, 0, 0, NULL);
        BASS_SetVolume(0.4);
    randomness = time(0);
    if(point.symbol)
        random_gen(point.num, point.symbol);
}