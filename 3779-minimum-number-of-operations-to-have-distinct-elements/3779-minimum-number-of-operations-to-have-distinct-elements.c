#include <stdlib.h>

int minOperations(int* nums, int numsSize) {
    int *seen = calloc(100001, sizeof(int));

    for (int i = numsSize - 1; i >= 0; i--) {
        if (seen[nums[i]]) {
            free(seen);
            return i / 3 + 1;
        }
        seen[nums[i]] = 1;
    }

    free(seen);
    return 0;
}