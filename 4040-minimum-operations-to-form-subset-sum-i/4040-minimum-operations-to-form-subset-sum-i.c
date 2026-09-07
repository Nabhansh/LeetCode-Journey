#include <limits.h>
#include <stdlib.h>

int minOperations(int* nums, int numsSize, int sum) {
    int INF = 1000000000;

    int *dp = malloc((sum + 1) * sizeof(int));
    int *ndp = malloc((sum + 1) * sizeof(int));

    for (int i = 0; i <= sum; i++)
        dp[i] = INF;

    dp[0] = 0;

    for (int i = 0; i < numsSize; i++) {
        for (int s = 0; s <= sum; s++)
            ndp[s] = dp[s];

        int x = nums[i];

        int value = x;
        int cost = 0;

        while (value <= sum) {
            for (int s = sum; s >= value; s--) {
                if (dp[s - value] != INF) {
                    int v = dp[s - value] + cost;
                    if (v < ndp[s])
                        ndp[s] = v;
                }
            }

            if (value > sum / 2)
                break;

            value *= 2;
            cost++;
        }

        value = x;
        cost = 0;

        while (value > 0) {
            if (value <= sum) {
                for (int s = sum; s >= value; s--) {
                    if (dp[s - value] != INF) {
                        int v = dp[s - value] + cost;
                        if (v < ndp[s])
                            ndp[s] = v;
                    }
                }
            }

            value /= 2;
            cost++;
        }

        int *tmp = dp;
        dp = ndp;
        ndp = tmp;
    }

    int ans = dp[sum];

    free(dp);
    free(ndp);

    return ans == INF ? -1 : ans;
}