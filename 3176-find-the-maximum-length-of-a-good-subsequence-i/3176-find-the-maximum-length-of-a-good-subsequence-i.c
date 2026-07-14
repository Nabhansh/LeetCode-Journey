#include <stdlib.h>

int maximumLength(int* nums, int numsSize, int k) {
    int n = numsSize;

    int** dp = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        dp[i] = (int*)malloc((k + 1) * sizeof(int));

        for (int j = 0; j <= k; j++) {
            dp[i][j] = 1;
        }
    }

    int answer = 1;

    for (int i = 0; i < n; i++) {

        for (int p = 0; p < i; p++) {

            if (nums[p] == nums[i]) {

                for (int j = 0; j <= k; j++) {
                    if (dp[p][j] + 1 > dp[i][j]) {
                        dp[i][j] = dp[p][j] + 1;
                    }
                }

            } else {

                for (int j = 1; j <= k; j++) {
                    if (dp[p][j - 1] + 1 > dp[i][j]) {
                        dp[i][j] = dp[p][j - 1] + 1;
                    }
                }
            }
        }

        for (int j = 0; j <= k; j++) {
            if (dp[i][j] > answer) {
                answer = dp[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        free(dp[i]);
    }

    free(dp);

    return answer;
}