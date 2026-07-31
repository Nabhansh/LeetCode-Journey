#define MOD 1000000007

int countPathsWithXorValue(int** grid, int gridSize, int* gridColSize, int k) {
    int m = gridSize;
    int n = gridColSize[0];

    // dp[i][j][x] = ways to reach (i,j) with xor = x
    int dp[m][n][16];
    memset(dp, 0, sizeof(dp));

    dp[0][0][grid[0][0]] = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (i == 0 && j == 0)
                continue;

            for (int x = 0; x < 16; x++) {

                int prev = x ^ grid[i][j];

                long long ways = 0;

                if (i > 0)
                    ways += dp[i - 1][j][prev];

                if (j > 0)
                    ways += dp[i][j - 1][prev];

                dp[i][j][x] = ways % MOD;
            }
        }
    }

    return dp[m - 1][n - 1][k];
}