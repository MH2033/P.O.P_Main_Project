#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game_console.h"
extern char deathblock;
extern int randomness;
struct dimension map_size;
extern char **game_map;
extern db *head;
void random_gen(int n,char b){
    int counter1 = 0,ran_x,ran_y;
    srand(randomness);
    randomness++;
    if (deathblock == b) {
        db*temp1 = head;
        if (head == NULL) {
            head = (db *) malloc(sizeof(db));
            head->next = NULL;
            head->head= NULL;
            temp1 = head;
        }
        else {
            temp1 = head;
            while (temp1 == NULL)
                temp1 = temp1->next;
            temp1 = (db *) malloc(sizeof(db));
            temp1->next = NULL;
            temp1->head =NULL;
            head->next = temp1;
        }
        while (counter1 < n) {
            ran_x = (rand() % (map_size.x - 2)) + 1;
            if (game_map[1][ran_x] == ' ') {
                game_map[1][ran_x] = b;
                counter1++;
                raindbd *temp = temp1->head;
                if (temp == NULL) {
                    temp = (raindbd *) malloc(sizeof(raindbd));
                    temp->head.y = 1;
                    temp->head.x = ran_x;
                    temp->next = NULL;
                    temp1->head = temp;
                } else {
                    while (temp->next == NULL)
                        temp = temp->next;
                    temp->next = (raindbd *) malloc(sizeof(raindbd));
                    temp->next->next = NULL;
                    temp->next->head.y = 1;
                    temp->next->head.x = ran_x;
                }
            } else {
                srand(randomness);
                randomness++;
            }
            counter1++;
        }
    }else {
        while (counter1<n){
            ran_x = (rand() % (map_size.x - 2)) + 1;
            ran_y = (rand() % (map_size.y - 2)) + 1;
            if (game_map[ran_y][ran_x] == ' ') {
                game_map[ran_y][ran_x] = b;
                counter1++;
            } else {
                srand(randomness);
                randomness++;
            }
            counter1++;
        }
    }
}