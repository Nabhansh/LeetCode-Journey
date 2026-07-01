int minimumCoins(int* prices, int pricesSize) {
    int n = pricesSize;
    int dp[1001];

    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--) {
        dp[i] = 0x3f3f3f3f;
        int end = (2 * (i + 1) < n) ? 2 * (i + 1) : n;
        for (int j = i + 1; j <= end; j++) {
            if (prices[i] + dp[j] < dp[i])
                dp[i] = prices[i] + dp[j];
        }
    }

    return dp[0];
}