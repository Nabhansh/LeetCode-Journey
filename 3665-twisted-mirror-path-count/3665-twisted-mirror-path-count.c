#include <stdlib.h>

#define MOD 1000000007

int uniquePaths(int** grid, int gridSize, int* gridColSize)
{
    int n = gridColSize[0];

    long long (*dp)[2] =
        malloc((n + 1) * sizeof(*dp));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 0;
    }

    dp[1][0] = 1;
    dp[1][1] = 1;

    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 0)
            {
                dp[j + 1][0] =
                    (dp[j][0] + dp[j + 1][1]) % MOD;

                dp[j + 1][1] = dp[j + 1][0];
            }
            else
            {
                long long temp = dp[j + 1][1];

                dp[j + 1][0] = temp;
                dp[j + 1][1] = dp[j][0];
            }
        }
    }

    int answer = dp[n][0];

    free(dp);

    return answer;
}