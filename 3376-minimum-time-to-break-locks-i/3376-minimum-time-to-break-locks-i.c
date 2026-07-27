#include <stdlib.h>
#include <limits.h>

static inline int min(int a, int b) {
    return a < b ? a : b;
}

int findMinimumTime(int* strength, int strengthSize, int K) {
    int n = strengthSize;
    int total = 1 << n;

    int *dp = (int *)malloc(sizeof(int) * total);

    for (int i = 0; i < total; i++)
        dp[i] = INT_MAX;

    dp[0] = 0;

    for (int mask = 0; mask < total; mask++) {

        if (dp[mask] == INT_MAX)
            continue;

        int broken = 0;

        for (int i = 0; i < n; i++)
            if (mask & (1 << i))
                broken++;

        int x = 1 + broken * K;

        for (int i = 0; i < n; i++) {

            if (mask & (1 << i))
                continue;

            int cost = (strength[i] + x - 1) / x;

            int next = mask | (1 << i);

            dp[next] = min(dp[next], dp[mask] + cost);
        }
    }

    int ans = dp[total - 1];

    free(dp);

    return ans;
}