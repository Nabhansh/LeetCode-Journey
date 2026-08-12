#include <stdlib.h>
#include <limits.h>

int minXor(int* nums, int numsSize, int k) {
    int n = numsSize;

    int* prefix = malloc((n + 1) * sizeof(int));

    for (int i = 0; i <= n; i++)
        prefix[i] = 0;

    for (int i = 1; i <= n; i++)
        prefix[i] = prefix[i - 1] ^ nums[i - 1];

    int** dp = malloc((n + 1) * sizeof(int*));

    for (int i = 0; i <= n; i++) {
        dp[i] = malloc((k + 1) * sizeof(int));

        for (int j = 0; j <= k; j++)
            dp[i][j] = INT_MAX;
    }

    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k && j <= i; j++) {
            for (int h = j - 1; h < i; h++) {
                if (dp[h][j - 1] == INT_MAX)
                    continue;

                int x = prefix[i] ^ prefix[h];
                int value = dp[h][j - 1] > x ? dp[h][j - 1] : x;

                if (value < dp[i][j])
                    dp[i][j] = value;
            }
        }
    }

    int result = dp[n][k];

    for (int i = 0; i <= n; i++)
        free(dp[i]);

    free(dp);
    free(prefix);

    return result;
}