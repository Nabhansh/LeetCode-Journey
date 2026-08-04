#include <limits.h>
#include <stdlib.h>

long long max(long long a, long long b)
{
    return (a > b) ? a : b;
}

long long maxSum(int* nums, int numsSize, int k, int m)
{
    long long *prefix = (long long *)malloc((numsSize + 1) * sizeof(long long));

    prefix[0] = 0;

    for (int i = 1; i <= numsSize; i++)
        prefix[i] = prefix[i - 1] + nums[i - 1];

    const long long NEG = LLONG_MIN / 4;

    long long **dp = (long long **)malloc((numsSize + 1) * sizeof(long long *));

    for (int i = 0; i <= numsSize; i++)
    {
        dp[i] = (long long *)malloc((k + 1) * sizeof(long long));

        for (int j = 0; j <= k; j++)
            dp[i][j] = NEG;
    }

    for (int i = 0; i <= numsSize; i++)
        dp[i][0] = 0;

    for (int j = 1; j <= k; j++)
    {
        long long best = NEG;

        for (int i = 1; i <= numsSize; i++)
        {
            dp[i][j] = dp[i - 1][j];

            if (i >= m)
            {
                if (dp[i - m][j - 1] != NEG)
                {
                    long long candidate = dp[i - m][j - 1] - prefix[i - m];

                    if (candidate > best)
                        best = candidate;
                }

                if (best != NEG)
                    dp[i][j] = max(dp[i][j], prefix[i] + best);
            }
        }
    }

    long long ans = dp[numsSize][k];

    for (int i = 0; i <= numsSize; i++)
        free(dp[i]);

    free(dp);
    free(prefix);

    return ans;
}