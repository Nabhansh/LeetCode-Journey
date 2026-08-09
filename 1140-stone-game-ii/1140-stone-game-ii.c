
int stoneGameRC(int n, int *rightSum, int i, int m, int dp[n][n]) {
    int x, j, ans, maxAns = 0;
    if (i == n)
        return 0;
    if (i + 2 * m >= n)
        return rightSum[i];
    if (dp[i][m])
        return dp[i][m];
    for (j = 1; j <= 2 * m; ++j) {
        if (j < m)
            x = m;
        else
            x = j;
        ans = rightSum[i] - stoneGameRC(n, rightSum, i + j, x, dp);
        if (ans > maxAns)
            maxAns = ans;
    }
    return dp[i][m] = maxAns;
}

int stoneGameII(int* piles, int pilesSize) {
    int i, n = pilesSize, rightSum[n], dp[n][n];
    memset(dp, 0, sizeof(dp));
    rightSum[n - 1] = piles[n - 1];
    for (i = n - 2; i >= 0; --i) {
        rightSum[i] = piles[i] + rightSum[i + 1];
    }
    return stoneGameRC(n, rightSum, 0, 1, dp);
}