#include <stdlib.h>

int* resultsArray(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = numsSize - k + 1;
    int *ans = (int *)malloc((*returnSize) * sizeof(int));

    int consecutive = 1;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1] + 1)
            consecutive++;
        else
            consecutive = 1;

        if (i >= k - 1) {
            if (consecutive >= k)
                ans[i - k + 1] = nums[i];
            else
                ans[i - k + 1] = -1;
        }
    }

    if (k == 1) {
        for (int i = 0; i < numsSize; i++)
            ans[i] = nums[i];
    }

    return ans;
}