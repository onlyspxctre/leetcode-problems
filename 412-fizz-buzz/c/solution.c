#include "solution.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    char** ret = malloc((size_t) n * sizeof(char*));
    *returnSize = n;

    for (int i = 0; i < n; ++i) {
        switch ((i + 1) % 15) {
        case 0:
            ret[i] = malloc(8 + 1);
            strcpy(ret[i], "FizzBuzz");
            break;
        case 3:
        case 6:
        case 9:
        case 12:
            ret[i] = malloc(4 + 1);
            strcpy(ret[i], "Fizz");
            break;
        case 5:
        case 10:
            ret[i] = malloc(4 + 1);
            strcpy(ret[i], "Buzz");
            break;
        default:
            ret[i] = malloc(5 + 1);
            sprintf(ret[i], "%d", i + 1);
            break;
        }
    }

    return ret;
}
