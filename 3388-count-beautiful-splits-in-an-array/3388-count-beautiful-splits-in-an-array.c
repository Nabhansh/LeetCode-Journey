int beautifulSplits(int* nums, int numsSize) {
    int n = numsSize;

    int **lcp = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        lcp[i] = (int *)calloc(n + 1, sizeof(int));
    }

    // Build LCP table
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (nums[i] == nums[j]) {
                lcp[i][j] = lcp[i + 1][j + 1] + 1;
            }
        }
    }

    int ans = 0;

    // Enumerate all valid splits
    for (int i = 1; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {

            bool first =
                (i <= j - i) &&
                (lcp[0][i] >= i);

            bool second =
                (j - i <= n - j) &&
                (lcp[i][j] >= (j - i));

            if (first || second)
                ans++;
        }
    }

    for (int i = 0; i <= n; i++)
        free(lcp[i]);
    free(lcp);

    return ans;
}