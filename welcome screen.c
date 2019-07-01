#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "game_console.h"
extern WINDOW *game_menu;
char list[100][100];
extern struct dimension default_term_size;
int save_file_name_to_list(struct file_name *head, int counter){
    if (head == NULL){
        strcpy(list[counter], "Back");
        return counter;
    }
    strcpy(list[counter], head->file);
    counter++;
    save_file_name_to_list(head->next, counter);
}
struct file_name* add_file(struct file_name * head ,char * filename ){
    if (head == NULL) {
        struct file_name *Students = (struct file_name *) malloc(sizeof(struct file_name));
        Students->file  =(char *) malloc(sizeof(char)* strlen(filename));
        strcpy(Students->file,filename);
        Students->next = NULL;
        return Students;
    } else {
        head->next = add_file(head->next,filename);
        return head;
    }
}
char * findpass(struct file_name * head, int number){
    if (number == 1){
        return head->file;
    }
    return findpass(head->next,number-1);
}
char* What_in_it(void){
    int counter;
    char mesg[15] = "Select a game";
    int ch, i = 1;
    int id;
    char * name_file = (char *)malloc(sizeof(char)*100);
    struct dirent * dn;
    int count = 0;
    struct file_name* head = NULL;
    DIR *dirct = opendir("game file");
    while ((dn = (readdir(dirct)) )!= NULL){
        if ( count > 1 )
            head = add_file(head , dn->d_name);
        count++;
    }
    closedir(dirct);
    box(game_menu, 0, 0);
    wattron(game_menu, COLOR_PAIR(1));
    mvwprintw(game_menu, 0,(2*default_term_size.x/3-strlen(mesg))/2,"%s",mesg);
    wattroff(game_menu, COLOR_PAIR(1));
    wrefresh(game_menu);
    counter = save_file_name_to_list(head, 1);
    for(i = 1; i <= counter; i++){
        if(i == 1)
            wattron(game_menu, A_STANDOUT);
        else
            wattroff(game_menu, A_STANDOUT);
        mvwprintw(game_menu, 2 * (i+1), (2*default_term_size.x/3-strlen(list[i]))/2, "%s",list[i]);
    }
    wrefresh(game_menu);
    i = 1;
    while(1) {
        ch = getch();
        mvwprintw(game_menu, 2 * (i + 1), (2 * default_term_size.x / 3 - strlen(list[i])) / 2, "%s", list[i]);
        switch (ch) {
            case KEY_UP:
                i--;
                i = (i < 1) ? counter : i;
                break;
            case KEY_DOWN:
                i++;
                i = (i > counter) ? 1 : i;
                break;
        }
        wattron(game_menu, A_STANDOUT);
        mvwprintw(game_menu, 2 * (i + 1), (2 * default_term_size.x / 3 - strlen(list[i])) / 2, "%s", list[i]);
        wattroff(game_menu, A_STANDOUT);
        wrefresh(game_menu);
        if(ch == '\n'){
            if(i < counter){
                id = i;
                break;
            }
            else{
                delwin(game_menu);
                show_main_menu();
                box(game_menu, 0, 0);
                wattron(game_menu, COLOR_PAIR(1));
                mvwprintw(game_menu, 0,(2*default_term_size.x/3-strlen(mesg))/2,"%s",mesg);
                wattroff(game_menu, COLOR_PAIR(1));
                wrefresh(game_menu);
                counter = save_file_name_to_list(head, 1);
                for(i = 1; i <= counter; i++){
                    if(i == 1)
                        wattron(game_menu, A_STANDOUT);
                    else
                        wattroff(game_menu, A_STANDOUT);
                    mvwprintw(game_menu, 2 * (i+1), (2*default_term_size.x/3-strlen(list[i]))/2, "%s",list[i]);
                }
                wrefresh(game_menu);
                i = 1;
            }
        }
    }
    return findpass(head,id);
}