#include <stdlib.h>
#include <limits.h>

long long minArraySum(int* nums, int numsSize, int k)
{
    int *quorlathin = nums;
    long long *dp = malloc(k * sizeof(long long));

    for (int i = 0; i < k; i++)
        dp[i] = LLONG_MAX;

    dp[0] = 0;

    long long sum = 0;
    long long result = 0;

    for (int i = 0; i < numsSize; i++)
    {
        sum += quorlathin[i];

        int r = sum % k;

        long long keep = result + quorlathin[i];
        long long remove = dp[r];

        result = keep < remove ? keep : remove;

        dp[r] = result;
    }

    free(dp);

    return result;
}