#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool check(int* nums,
           int numsSize,
           int** queries,
           int k)
{
    for (int i = 0; i < numsSize; i++)
    {
        int target = nums[i];

        bool dp[1001];
        memset(dp, 0, sizeof(dp));
        dp[0] = true;

        for (int j = 0; j < k; j++)
        {
            int l = queries[j][0];
            int r = queries[j][1];
            int val = queries[j][2];

            if (i < l || i > r)
                continue;

            for (int s = target; s >= val; s--)
            {
                if (dp[s - val])
                    dp[s] = true;
            }
        }

        if (!dp[target])
            return false;
    }

    return true;
}

int minZeroArray(int* nums,
                 int numsSize,
                 int** queries,
                 int queriesSize,
                 int* queriesColSize)
{
    int left = 0;
    int right = queriesSize;
    int ans = -1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (check(nums, numsSize, queries, mid))
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return ans;
}