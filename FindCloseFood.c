#include <math.h>
#include "game_console.h"
extern struct opponent opp;
extern char **game_map;
extern struct dimension map_size;
int FindCloseFood(struct dimension op) {
    register int i, j;
    int cdotx, cdoty, firstdot = 1;
    double dist1, dist2;
    for (i = 0; i < map_size.y; i++) {
        for (j = 0; j < map_size.x; j++) {
            if (game_map[i][j] == opp.dest) {
                if (firstdot) {
                    cdotx = i;
                    cdoty = j;
                    firstdot = 0;
                } else {
                    dist1 = sqrt(pow((cdotx - op.y), 2) + pow((cdoty - op.x), 2));
                    dist2 = sqrt(pow((i - op.y), 2) + pow((j - op.x), 2));
                    if (dist2 < dist1) {
                        cdotx = i;
                        cdoty = j;
                    }
                }
            }
        }
    }
    return A_I(cdotx,cdoty,op);
}