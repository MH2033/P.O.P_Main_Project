#include <stdio.h>


void debug_output(int w,int b,int i , int j,char l) {
    FILE *output = fopen("debug_output.txt","a");

    fprintf(output, "%d\t%d\t%d\t%d\t%c\n>>>>>>>>>>\n",w,b, i, j,l);

    fclose(output);

    //getchar();

    return ;
}