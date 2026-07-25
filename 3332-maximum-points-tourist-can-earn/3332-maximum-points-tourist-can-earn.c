long long max(long long a, long long b) {
    return a > b ? a : b;
}

long long maxScore(int n, int k, int** stayScore, int stayScoreSize,
                   int* stayScoreColSize, int** travelScore,
                   int travelScoreSize, int* travelScoreColSize) {

    long long dp[k + 1][n];

    for (int j = 0; j < n; j++)
        dp[0][j] = 0;

    for (int day = 1; day <= k; day++) {
        for (int city = 0; city < n; city++) {

            dp[day][city] = dp[day - 1][city] +
                            stayScore[day - 1][city];

            for (int prev = 0; prev < n; prev++) {
                if (prev == city) continue;

                dp[day][city] = max(
                    dp[day][city],
                    dp[day - 1][prev] +
                    travelScore[prev][city]
                );
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[k][i]);

    return ans;
}