#include <stdbool.h>
#include <stdlib.h>

bool isZeroArray(int* nums, int numsSize, int** queries,
                 int queriesSize, int* queriesColSize) {

    int *diff = calloc(numsSize + 1, sizeof(int));

    for (int i = 0; i < queriesSize; i++) {
        int l = queries[i][0];
        int r = queries[i][1];
        diff[l]++;
        if (r + 1 < numsSize)
            diff[r + 1]--;
    }

    int cover = 0;

    for (int i = 0; i < numsSize; i++) {
        cover += diff[i];
        if (nums[i] > cover) {
            free(diff);
            return false;
        }
    }

    free(diff);
    return true;
}