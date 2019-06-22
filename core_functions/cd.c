#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>
#include <dirent.h>
char game_file[] = "game file/";
void cd(char * direct){
    strcat(game_file,direct);
    chdir(game_file);
    opendir(game_file);

}