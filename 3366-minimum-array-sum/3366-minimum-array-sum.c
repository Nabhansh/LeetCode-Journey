#include <stdlib.h>
#include <string.h>
#include <limits.h>

static inline int min(int a, int b) {
    return a < b ? a : b;
}

int minArraySum(int* nums, int numsSize, int k, int op1, int op2) {
    const int INF = INT_MAX / 2;

    int **dp = (int **)malloc((op1 + 1) * sizeof(int *));
    int **ndp = (int **)malloc((op1 + 1) * sizeof(int *));

    for (int i = 0; i <= op1; i++) {
        dp[i] = (int *)malloc((op2 + 1) * sizeof(int));
        ndp[i] = (int *)malloc((op2 + 1) * sizeof(int));
    }

    for (int i = 0; i <= op1; i++)
        for (int j = 0; j <= op2; j++)
            dp[i][j] = INF;

    dp[0][0] = 0;

    for (int idx = 0; idx < numsSize; idx++) {

        for (int i = 0; i <= op1; i++)
            for (int j = 0; j <= op2; j++)
                ndp[i][j] = INF;

        int x = nums[idx];

        for (int a = 0; a <= op1; a++) {
            for (int b = 0; b <= op2; b++) {

                if (dp[a][b] == INF)
                    continue;

                // No operation
                ndp[a][b] = min(ndp[a][b], dp[a][b] + x);

                // Operation 1
                if (a < op1) {
                    int y = (x + 1) / 2;
                    ndp[a + 1][b] = min(ndp[a + 1][b], dp[a][b] + y);
                }

                // Operation 2
                if (b < op2 && x >= k) {
                    int y = x - k;
                    ndp[a][b + 1] = min(ndp[a][b + 1], dp[a][b] + y);
                }

                // Both operations

                if (a < op1 && b < op2) {

                    // Op1 -> Op2
                    int y = (x + 1) / 2;
                    if (y >= k)
                        ndp[a + 1][b + 1] =
                            min(ndp[a + 1][b + 1], dp[a][b] + (y - k));

                    // Op2 -> Op1
                    if (x >= k) {
                        y = (x - k + 1) / 2;
                        ndp[a + 1][b + 1] =
                            min(ndp[a + 1][b + 1], dp[a][b] + y);
                    }
                }
            }
        }

        int **tmp = dp;
        dp = ndp;
        ndp = tmp;
    }

    int ans = INF;

    for (int i = 0; i <= op1; i++)
        for (int j = 0; j <= op2; j++)
            ans = min(ans, dp[i][j]);

    for (int i = 0; i <= op1; i++) {
        free(dp[i]);
        free(ndp[i]);
    }

    free(dp);
    free(ndp);

    return ans;
}