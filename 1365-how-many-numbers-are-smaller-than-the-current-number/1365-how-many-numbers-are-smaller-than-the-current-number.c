#include <stdlib.h>

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    int freq[101] = {0};

    for (int i = 0; i < numsSize; i++)
        freq[nums[i]]++;

    for (int i = 1; i <= 100; i++)
        freq[i] += freq[i - 1];

    int *ans = (int *)malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0)
            ans[i] = 0;
        else
            ans[i] = freq[nums[i] - 1];
    }

    *returnSize = numsSize;
    return ans;
}