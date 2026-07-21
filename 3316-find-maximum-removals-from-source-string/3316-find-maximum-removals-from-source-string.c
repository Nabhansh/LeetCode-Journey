#include <stdlib.h>
#include <string.h>

#define NEG -1000000000

int max(int a, int b) {
    return a > b ? a : b;
}

int maxRemovals(char* source, char* pattern, int* targetIndices, int targetIndicesSize) {
    int n = strlen(source);
    int m = strlen(pattern);

    int *mark = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < targetIndicesSize; i++)
        mark[targetIndices[i]] = 1;

    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int *)malloc((m + 1) * sizeof(int));
        for (int j = 0; j <= m; j++)
            dp[i][j] = NEG;
    }

    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {

            if (dp[i - 1][j] != NEG)
                dp[i][j] = dp[i - 1][j] + mark[i - 1];

            if (j > 0 &&
                source[i - 1] == pattern[j - 1] &&
                dp[i - 1][j - 1] != NEG) {

                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            }
        }
    }

    int ans = dp[n][m];

    for (int i = 0; i <= n; i++)
        free(dp[i]);
    free(dp);
    free(mark);

    return ans;
}