#include <stdio.h>


void debug_output(int i , int j) {
    FILE *output = fopen("debug_output.txt","a");

    fprintf(output, "%d\t%d\n", i, j);

    fclose(output);

    //getchar();

    return ;
}