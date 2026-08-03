#include <stdlib.h>
#include <limits.h>

char* stoneGameIII(int* stoneValue, int stoneValueSize) {
    int n = stoneValueSize;

    int *dp = (int *)malloc((n + 3) * sizeof(int));

    for (int i = 0; i < n + 3; i++)
        dp[i] = 0;

    for (int i = n - 1; i >= 0; i--) {
        int sum = 0;
        dp[i] = INT_MIN;

        for (int k = 0; k < 3 && i + k < n; k++) {
            sum += stoneValue[i + k];
            int diff = sum - dp[i + k + 1];
            if (diff > dp[i])
                dp[i] = diff;
        }
    }

    char *result;
    if (dp[0] > 0)
        result = "Alice";
    else if (dp[0] < 0)
        result = "Bob";
    else
        result = "Tie";

    free(dp);
    return result;
}