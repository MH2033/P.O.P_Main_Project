#include <math.h>
#include <curses.h>
#include "headers.h"
extern struct opponent opp;
extern char **game_map;
extern struct dimension map_size;
int FindCloseFood(struct dimension op) {
    register int i, j;
    int best_cdotx = -1, best_cdoty = -1, best_dist = 100000;
    int new_dist;
    for (i = 0; i < map_size.y; i++) {
        for (j = 0; j < map_size.x; j++) {
            if (game_map[i][j] == opp.dest) {
                new_dist = pow((i - op.y), 2) + pow((j - op.x), 2);
                if (new_dist < best_dist)
                {
                    best_dist = new_dist;
                    best_cdotx = i;
                    best_cdoty = j;
                }
//                if (firstdot) {
//                    cdotx = i;
//                    cdoty = j;
//                    firstdot = 0;
//                }
//                } else {
//                    dist1 = (pow((cdotx - op.y), 2) + pow((cdoty - op.x), 2));
//                    dist2 = (pow((i - op.y), 2) + pow((j - op.x), 2));
//                    if (dist2 < dist1) {
//                        cdotx = i;
//                        cdoty = j;
//                    }
//                }

            }
        }
    }
    return A_I(best_cdotx, best_cdoty,op);
}