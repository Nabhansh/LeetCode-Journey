int longestArithmetic(int* nums, int numsSize) {
    int n = numsSize;

    int* d = (int*)malloc(n * sizeof(int));
    int* f = (int*)malloc(n * sizeof(int));
    int* g = (int*)malloc(n * sizeof(int));

    d[0] = 0;

    for (int i = 1; i < n; i++) {
        d[i] = nums[i] - nums[i - 1];
    }

    // f[i] = longest arithmetic subarray ending at i
    for (int i = 0; i < n; i++) {
        f[i] = 2;
    }

    f[0] = 1;

    for (int i = 2; i < n; i++) {
        if (d[i] == d[i - 1]) {
            f[i] = f[i - 1] + 1;
        }
    }

    // g[i] = longest arithmetic subarray starting at i
    for (int i = 0; i < n; i++) {
        g[i] = 2;
    }

    g[n - 1] = 1;

    for (int i = n - 3; i >= 0; i--) {
        if (d[i + 1] == d[i + 2]) {
            g[i] = g[i + 1] + 1;
        }
    }

    // Since n >= 4, we can always make
    // an arithmetic subarray of length 3.
    int ans = 3;

    for (int i = 0; i < n; i++) {

        // Don't change nums[i]
        if (f[i] > ans)
            ans = f[i];

        if (g[i] > ans)
            ans = g[i];

        // Change nums[i] to extend left side
        if (i > 0) {
            if (f[i - 1] + 1 > ans)
                ans = f[i - 1] + 1;
        }

        // Change nums[i] to extend right side
        if (i + 1 < n) {
            if (g[i + 1] + 1 > ans)
                ans = g[i + 1] + 1;
        }

        // Change nums[i] and connect both sides
        if (i > 0 && i < n - 1) {

            int diff = nums[i + 1] - nums[i - 1];

            // The required middle value must be an integer.
            if (diff % 2 == 0) {

                diff /= 2;

                int len = 3;

                // Extend to the left
                if (i > 1 && diff == d[i - 1]) {
                    len += f[i - 1] - 1;
                }

                // Extend to the right
                if (i < n - 2 && diff == d[i + 2]) {
                    len += g[i + 1] - 1;
                }

                if (len > ans)
                    ans = len;
            }
        }
    }

    free(d);
    free(f);
    free(g);

    return ans;
}