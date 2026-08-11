#include <stdlib.h>

#define MOD 1000000007LL

int specialTriplets(int* nums, int numsSize)
{
    int left[200001] = {0};
    int right[200001] = {0};

    for (int i = 0; i < numsSize; ++i)
        ++right[nums[i]];

    long long ans = 0;

    for (int j = 0; j < numsSize; ++j)
    {
        int x = nums[j];
        int target = x * 2;

        --right[x];

        ans = (ans + (long long)left[target] * right[target])
              % MOD;

        ++left[x];
    }

    return (int)ans;
}