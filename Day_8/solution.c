/*  Advent of Code: Day 8:
    
    

    Author: Veikka Immonen @imveikka*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define N 1 << 7


int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    char **lines = calloc(N, sizeof *lines), *line = NULL, **temp;
    size_t bytes = 0, read;

    for (temp = lines; (read = getline(&line, &bytes, file)) != -1; temp++)
    {
        *temp = calloc(read, sizeof **temp);
        strncpy(*temp, line, read - 1);
    }

    /* TODO solution */

    for (temp = lines; *temp; temp++)
    {
        printf("%s\n", *temp);
        free(*temp);
    }

    free(lines);
    free(line);
    fclose(file);

    return 0;
}