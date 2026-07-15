int maximumLength(int* nums, int numsSize, int k) {
    int dp[1001][1001] = {0};
    int ans = 0;

    for (int i = 0; i < numsSize; i++) {
        int x = nums[i] % k;

        for (int y = 0; y < k; y++) {
            dp[x][y] = dp[y][x] + 1;

            if (dp[x][y] > ans) {
                ans = dp[x][y];
            }
        }
    }

    return ans;
}