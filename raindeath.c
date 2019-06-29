#include "game_console.h"
#include <stdlib.h>
extern char deathblock,**game_map;
extern char object;
extern int raindb;
db *head = NULL;
extern struct dimension map_size;
static raindbd* pre;
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
void del(raindbd * head){

}
void move_db(db * head){
    raindbd * temp = head->head;
    if (temp == NULL)
        return;
    int x = temp->head.x,y = temp->head.y;
    while(temp != NULL) {
        if (game_map[y + 1][x] == ' ' || game_map[y + 1][x] == object) {
            game_map[y][x] = ' ';
            game_map[y+1][x] = deathblock;
            temp->head.y++;
            temp = temp->next;
            pre = temp;
        }else{
            game_map[y][x] = ' ';
            debug_output(temp->head.y,temp->head.x);
            //del_di(temp);
            head->head = NULL;
        }
    }
}
void rain_db(void){
    if (raindb == 0){
        return;
    }
    if (head == NULL)
        random_gen(raindb,deathblock);
    move_db(head);
}