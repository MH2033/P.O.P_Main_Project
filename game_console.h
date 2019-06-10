#ifndef P_O_P_MAIN_PROJECT_GAME_CONSOLE_H
#define P_O_P_MAIN_PROJECT_GAME_CONSOLE_H
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

int load_config(char*, char*);
int load_map(FILE *);
int load_settings(FILE *);
void random_gen(int n,char b);
void initialization();
void print_map();
void hidecursor();

#endif
