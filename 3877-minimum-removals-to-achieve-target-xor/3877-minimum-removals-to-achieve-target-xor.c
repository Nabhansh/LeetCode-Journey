#include <limits.h>

int minRemovals(int* nums, int numsSize, int target) {
    int maxXor = 16384;   // 2^14 > 10000
    int INF = 1000000;

    int totalXor = 0;

    for (int i = 0; i < numsSize; i++) {
        totalXor ^= nums[i];
    }

    int required = totalXor ^ target;

    int dp[16384];

    for (int i = 0; i < maxXor; i++) {
        dp[i] = INF;
    }

    dp[0] = 0;

    for (int i = 0; i < numsSize; i++) {

        int next[16384];

        for (int j = 0; j < maxXor; j++) {
            next[j] = dp[j];
        }

        for (int x = 0; x < maxXor; x++) {
            if (dp[x] != INF) {
                int newXor = x ^ nums[i];

                if (dp[x] + 1 < next[newXor]) {
                    next[newXor] = dp[x] + 1;
                }
            }
        }

        for (int j = 0; j < maxXor; j++) {
            dp[j] = next[j];
        }
    }

    return dp[required] == INF ? -1 : dp[required];
}