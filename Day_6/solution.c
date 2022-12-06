/*  Advent of Code: Day 6:
    Tuning Trouble

    Big boy in the house!

    Author: Veikka Immonen */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*  Check if any duplicates occurs in string
    lenght of n. Returns 1 if yes, 0 if no. */
int strndub(char *str, int n) {
    short table[26] = {0};
    for (int i = 0; str[i], i < n; ++i) {
        if (table[str[i]-97] == 1) return 1;
        table[str[i]-97]++;
    }
    return 0;
}


int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Give filename\n");
        return 0;
    }

    FILE * file;
    if ((file = fopen(argv[1], "r")) == NULL) {
        printf("File not found\n");
        return 0;
    }

    char foo[5];
    char bar[15];
    int result1 = 4, result2 = 14;

    /* Solution 1 */
    fscanf(file, "%4s", foo);
    while (foo[3]) {
        if (strndub(foo, 4) == 0) break;
        fseek(file, -3, SEEK_CUR);
        fscanf(file, "%4s", foo);
        result1++;
    }

    printf("Silver %d\n", result1);

    /* Solution 2 */
    fseek(file, 0, SEEK_SET);
    fscanf(file, "%14s", bar);
    while (bar[13]) {
        if (strndub(bar, 14) == 0) break;
        fseek(file, -13, SEEK_CUR);
        fscanf(file, "%14s", bar);
        result2++;
    }

    printf("Gold %d\n", result2);

    fclose(file);

    return 0;
}
