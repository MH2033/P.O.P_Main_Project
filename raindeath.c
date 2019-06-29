#include "game_console.h"
#include <stdlib.h>
extern char deathblock,**game_map;
extern char object;
extern int raindb;
db *head = NULL;
extern struct dimension map_size;
static raindbd* pre;
void del(raindbd * head){

}
void move_db(raindbd * head){
    raindbd * temp = head;
    if (temp == NULL)
        return;
    int x = temp->head.x,y = temp->head.y;
    if (game_map[y+1][x] == ' ' ||game_map[y+1][x] == object) {
        temp->head.y++;
        game_map[y+1][x] = deathblock;
        game_map[y][x] = ' ';
        pre = temp;
        move_db(temp->next);
    }else{
        debug_output(head->head.y,head->head.x);
        game_map[y][x] = ' ';
        del(temp);
        move_db(temp->next);
    }
}
void rain_db(void){
    if (raindb == 0){
        return;
    }
    if (head == NULL)
        random_gen(raindb,deathblock);
    move_db(head->head);
}
void del_di(raindbd * head){
    if (head == NULL)
        return;
    if (head->next ==NULL){
        free(head);
        pre->next = NULL;
        return;
    }
    pre->next = head->next;
    free(head);
    head = NULL;
}