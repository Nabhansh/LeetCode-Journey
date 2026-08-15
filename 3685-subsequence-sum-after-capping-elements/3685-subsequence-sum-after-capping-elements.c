#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

bool* subsequenceSumAfterCapping(int* nums, int numsSize, int k, int* returnSize)
{
    qsort(nums, numsSize, sizeof(int), cmp);

    bool *ans = calloc(numsSize, sizeof(bool));
    bool *dp = calloc(k + 1, sizeof(bool));

    dp[0] = true;

    int i = 0;

    for (int x = 1; x <= numsSize; x++)
    {
        while (i < numsSize && nums[i] < x)
        {
            for (int j = k; j >= nums[i]; j--)
                dp[j] = dp[j] || dp[j - nums[i]];

            i++;
        }

        int remaining = numsSize - i;
        int limit = k / x;

        if (limit > remaining)
            limit = remaining;

        for (int j = 0; j <= limit; j++)
        {
            if (dp[k - j * x])
            {
                ans[x - 1] = true;
                break;
            }
        }
    }

    free(dp);

    *returnSize = numsSize;
    return ans;
}