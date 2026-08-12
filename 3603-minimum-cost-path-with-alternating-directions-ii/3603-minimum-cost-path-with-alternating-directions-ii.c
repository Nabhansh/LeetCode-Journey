#include <stdlib.h>
#include <limits.h>

long long minCost(int m, int n, int** waitCost, int waitCostSize, int* waitCostColSize) {
    long long *dp = malloc((long long)m * n * sizeof(long long));

    for (int i = 0; i < m * n; i++)
        dp[i] = LLONG_MAX;

    dp[0] = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int idx = i * n + j;

            if (dp[idx] == LLONG_MAX)
                continue;

            if (i + 1 < m) {
                int ni = i + 1;
                int nj = j;
                int nidx = ni * n + nj;

                long long value = dp[idx]
                    + (long long)(ni + 1) * (nj + 1)
                    + waitCost[ni][nj];

                if (value < dp[nidx])
                    dp[nidx] = value;
            }

            if (j + 1 < n) {
                int ni = i;
                int nj = j + 1;
                int nidx = ni * n + nj;

                long long value = dp[idx]
                    + (long long)(ni + 1) * (nj + 1)
                    + waitCost[ni][nj];

                if (value < dp[nidx])
                    dp[nidx] = value;
            }
        }
    }

    long long ans = dp[(m - 1) * n + (n - 1)] - waitCost[m - 1][n - 1];

    free(dp);

    return ans;
}