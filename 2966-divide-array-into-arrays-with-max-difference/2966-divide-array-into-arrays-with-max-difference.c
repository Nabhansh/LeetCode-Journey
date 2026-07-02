#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}

int** divideArray(int* nums, int numsSize, int k,
                  int* returnSize, int** returnColumnSizes) {

    qsort(nums, numsSize, sizeof(int), cmp);

    *returnSize = numsSize / 3;
    *returnColumnSizes = (int *)malloc((*returnSize) * sizeof(int));

    int **ans = (int **)malloc((*returnSize) * sizeof(int *));

    for (int i = 0; i < *returnSize; i++)
        (*returnColumnSizes)[i] = 3;

    int idx = 0;

    for (int i = 0; i < numsSize; i += 3) {
        if (nums[i + 2] - nums[i] > k) {
            *returnSize = 0;
            return NULL;
        }

        ans[idx] = (int *)malloc(3 * sizeof(int));
        ans[idx][0] = nums[i];
        ans[idx][1] = nums[i + 1];
        ans[idx][2] = nums[i + 2];
        idx++;
    }

    return ans;
}