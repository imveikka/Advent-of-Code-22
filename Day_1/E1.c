/*
Advent of Code: Day 1, Problem 1
Author: Veikka Immonen
*/


#include <stdio.h>
#include <stdlib.h>


#define MAX(a, b) (a) > (b) ? (a) : (b)


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

    int max = 0;
    int calories = 0;


    while ((read = getline(&line, &bytes, file)) != -1) {
        if (read == 1) {
            max = MAX(max, calories);
            calories = 0;
        }
        else calories += atoi(line);
    }

    fclose(file);
    free(line);

    printf("Max elf is carrying %d calories.\n", max);
    return 0;
}