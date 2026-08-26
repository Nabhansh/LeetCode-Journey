#include <stdlib.h>

long long minIncrease(int* nums, int numsSize) {
    int n = numsSize;
    long long (*dp)[2] = calloc(n + 2, sizeof(long long[2]));

    for (int i = n - 2; i >= 1; i--) {
        long long cost = 0;
        long long target = (long long)(nums[i - 1] > nums[i + 1] ? nums[i - 1] : nums[i + 1]) + 1;

        if (target > nums[i])
            cost = target - nums[i];

        dp[i][0] = cost + dp[i + 2][0];
        dp[i][1] = cost + dp[i + 2][1];

        if (i + 1 < n - 1 && dp[i + 1][0] < dp[i][1])
            dp[i][1] = dp[i + 1][0];
    }

    long long ans = dp[1][(n & 1) ^ 1];
    free(dp);
    return ans;
}