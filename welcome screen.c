#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "game_console.h"

void print_file_name(struct file_name * head,int counter){
    if (head == NULL){
        return;
    }
    printf("%d )%s\n",counter,head->file,counter);
    counter ++;
    print_file_name(head->next, counter);
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
        //printf("%s\n",head->next->file);
        return head;
    }
    return head;
}
char * findpass(struct file_name * head, int number){
    if (number == 1){
        return head->file;
    }
    return findpass(head->next,number-1);
}
char* What_in_it(void){
    char *id;
    id = (char *)malloc(sizeof(char)*100);
    char * name_file = (char *)malloc(sizeof(char)*100);
    struct dirent * dn;
    int count = 0;
    struct file_name* head = NULL;
    DIR *dirct = opendir(".");
    while ((dn = (readdir(dirct)) )!= NULL){
        if ( count > 1 )
            head = add_file(head , dn->d_name);
        count++;
    }
    closedir(dirct);
    print_file_name(head , 1);
    printf("==========================================");
    printf("Plese Enter The Number Of The File That You Want To Open :");
    scanf("%s", id);
    return findpass(head,atoi(id));
}