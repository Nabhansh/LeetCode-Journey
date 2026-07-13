#include <stdio.h>
#include <stdlib.h>

int* sequentialDigits(int low, int high, int* returnSize) {
    int *result = (int*)malloc(100 * sizeof(int)); // enough space
    *returnSize = 0;

    char digits[] = "123456789";

    // length of sequential number
    for (int len = 1; len <= 9; len++) {
        for (int i = 0; i + len <= 9; i++) {
            int num = 0;

            // build number
            for (int j = i; j < i + len; j++) {
                num = num * 10 + (digits[j] - '0');
            }

            if (num >= low && num <= high) {
                result[*returnSize] = num;
                (*returnSize)++;
            }
        }
    }

    return result;
}