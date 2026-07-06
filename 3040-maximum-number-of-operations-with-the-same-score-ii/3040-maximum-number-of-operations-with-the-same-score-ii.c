#include <stdlib.h>
#include <string.h>

int **dp;
int *a;
int target;

int max(int x, int y) {
    return x > y ? x : y;
}

int dfs(int l, int r) {
    if (l >= r)
        return 0;

    if (dp[l][r] != -1)
        return dp[l][r];

    int ans = 0;

    if (l + 1 <= r && a[l] + a[l + 1] == target)
        ans = max(ans, 1 + dfs(l + 2, r));

    if (a[l] + a[r] == target)
        ans = max(ans, 1 + dfs(l + 1, r - 1));

    if (l <= r - 1 && a[r - 1] + a[r] == target)
        ans = max(ans, 1 + dfs(l, r - 2));

    dp[l][r] = ans;
    return ans;
}

int solve(int *nums, int n, int t, int l, int r) {
    target = t;
    a = nums;

    dp = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        dp[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
            dp[i][j] = -1;
    }

    int ans = dfs(l, r);

    for (int i = 0; i < n; i++)
        free(dp[i]);
    free(dp);

    return ans;
}

int maxOperations(int* nums, int numsSize) {
    if (numsSize < 2)
        return 0;

    int ans = 0;

    ans = max(ans,
              1 + solve(nums, numsSize,
                        nums[0] + nums[1],
                        2, numsSize - 1));

    ans = max(ans,
              1 + solve(nums, numsSize,
                        nums[0] + nums[numsSize - 1],
                        1, numsSize - 2));

    ans = max(ans,
              1 + solve(nums, numsSize,
                        nums[numsSize - 2] + nums[numsSize - 1],
                        0, numsSize - 3));

    return ans;
}