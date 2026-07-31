#include <stdlib.h>

static int gcd(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

long long numberOfSubsequences(int* nums, int numsSize) {
    // key = (x << 12) | y
    // x,y <= 1000, so 12 bits are enough.
    const int MAXKEY = 1 << 24;

    int *cnt = (int *)calloc(MAXKEY, sizeof(int));

    // Build all valid (r,s) pairs.
    for (int r = 4; r < numsSize - 2; r++) {
        int c = nums[r];
        for (int s = r + 2; s < numsSize; s++) {
            int d = nums[s];
            int g = gcd(c, d);
            int key = ((d / g) << 12) | (c / g);
            cnt[key]++;
        }
    }

    long long ans = 0;

    for (int q = 2; q < numsSize - 4; q++) {

        // Count valid (p,q)
        for (int p = 0; p < q - 1; p++) {
            int a = nums[p];
            int b = nums[q];
            int g = gcd(a, b);
            int key = ((a / g) << 12) | (b / g);
            ans += cnt[key];
        }

        // Remove pairs whose r becomes invalid
        int c = nums[q + 2];
        for (int s = q + 4; s < numsSize; s++) {
            int d = nums[s];
            int g = gcd(c, d);
            int key = ((d / g) << 12) | (c / g);
            cnt[key]--;
        }
    }

    free(cnt);
    return ans;
}