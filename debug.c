#include <stdio.h>


void debug_output(int i , int j,char l) {
    FILE *output = fopen("debug_output.txt","a");

    fprintf(output, "%d\t%d\t%c\n>>>>>>>>>>\n", i, j,l);

    fclose(output);

    //getchar();

    return ;
}