#include <stdlib.h>

#define MOD 1000000007LL
#define MAXV 200001

int specialTriplets(int* nums, int numsSize)
{
    int *left = calloc(MAXV, sizeof(int));
    int *right = calloc(MAXV, sizeof(int));

    for (int i = 0; i < numsSize; ++i)
        ++right[nums[i]];

    long long ans = 0;

    for (int j = 0; j < numsSize; ++j)
    {
        int x = nums[j];
        int target = x << 1;

        --right[x];

        if (target < MAXV)
        {
            ans += (long long)left[target] * right[target];

            if (ans >= MOD)
                ans %= MOD;
        }

        ++left[x];
    }

    free(left);
    free(right);

    return (int)(ans % MOD);
}