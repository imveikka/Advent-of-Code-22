/*
Advent of Code: Day 1, Problem 2
Author: Veikka Immonen
*/


#include <stdio.h>
#include <stdlib.h>


#define SWAP(x, y, T) do { T SWAP = x; x = y; y = SWAP; } while (0)


int main(int argc, char *argv[]) {

    if (argc < 2) {
        perror("Give filename\n");
        exit(1);
    }

    char * line = NULL;
    size_t bytes = 0;
    size_t read; 

    FILE * file;
    if ((file = fopen(argv[1], "r")) == NULL) {
        perror("File not found\n");
        exit(1);
    }

    int max[3] = {0};
    int calories = 0;


    while ((read = getline(&line, &bytes, file)) != -1) {
        if (read == 1) {
            if (calories >= max[2]) max[2] = calories;
            if (max[2] >= max[1]) SWAP(max[1], max[2], int);
            if (max[1] >= max[0]) SWAP(max[0], max[1], int);
            calories = 0;
        }
        else calories += atoi(line);
    }

    fclose(file);
    free(line);

    printf("Top 3 elves: %d, %d, %d\n", max[0], max[1], max[2]);
    printf("Top 3 elves are carrying %d calories in total.\n", max[0] + max[1] + max[2]);
    return 0;
}