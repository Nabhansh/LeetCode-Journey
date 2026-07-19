#include <stdlib.h>
#include <stdbool.h>

bool* prefixesDivBy5(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    bool *ans = (bool *)malloc(numsSize * sizeof(bool));

    int rem = 0;

    for (int i = 0; i < numsSize; i++) {
        rem = (rem * 2 + nums[i]) % 5;
        ans[i] = (rem == 0);
    }

    return ans;
}