#include <stdlib.h>

int climbStairs(int n, int* costs, int costsSize)
{
    int *dp = malloc((n + 1) * sizeof(int));

    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1000000000;

        for (int j = i - 3; j < i; j++)
        {
            if (j >= 0)
            {
                int d = i - j;
                int value = dp[j] + costs[i - 1] + d * d;

                if (value < dp[i])
                    dp[i] = value;
            }
        }
    }

    int ans = dp[n];

    free(dp);

    return ans;
}