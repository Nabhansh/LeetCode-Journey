#include <stdlib.h>

int* resultsArray(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = numsSize - k + 1;
    int *ans = (int *)malloc((*returnSize) * sizeof(int));

    int len = 1;

    for (int i = 0; i < numsSize; i++) {
        if (i > 0 && nums[i] == nums[i - 1] + 1)
            len++;
        else
            len = 1;

        if (i >= k - 1) {
            if (len >= k)
                ans[i - k + 1] = nums[i];
            else
                ans[i - k + 1] = -1;
        }
    }

    return ans;
}