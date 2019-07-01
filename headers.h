#ifndef P_O_P_MAIN_PROJECT_HEADERS_H
#define P_O_P_MAIN_PROJECT_HEADERS_H

#include <stdio.h>

struct rpoint{
    char symbol;
    int score;
    int num;
};

struct opponent{
    char rival;
    char dest;
};

struct put{
    char key;
    char symbol;
    int limit;
};

struct dimension{
    int x;
    int y;
};
typedef struct raindbd{
    struct dimension head;
    struct raindbd *next;
}raindbd;
typedef struct db{
    raindbd *head;
    struct db *next;
}db;
struct file_name{
    char *file;
    struct file_name* next;
};

struct opp_list{
    struct dimension pos;
    struct opp_list *next;
};

int load_config(char *);
int load_map(FILE *);
int load_settings(FILE *);
void random_gen(int n,char b);
void initialization();
void move_up(struct dimension *pos,char obj,int score[],int i);
void move_down(struct dimension *pos,char obj,int score[],int i);
void move_right(struct dimension *pos,char obj, int score[],int i);
void move_left(struct dimension *pos,char obj,int score[],int i);
void move_player(char c);
void print_map();
void hidecursor();
void cd(char *dir);
void run_game();
void put_dblock(struct dimension);
void delay(int number_of_seconds);
char *What_in_it(void);
int A_I(int i,int j,struct dimension op);
int FindCloseFood(struct dimension op);
void *move_computer(void *);
void show_start_window();
void show_pause_window();
void game_over();
db* move_db(db *);
void debug_output(int i, int j);
void rain_db(void);
void clean_up();
void cleanup();
void att(int direction);
void *keyboard_handle(void *temp);
int show_main_menu();
void ingame_init();
void save_score(void);
void win(void);
void time_limit_reached();
#endif
