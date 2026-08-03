#include <stdlib.h>

static int max(int a, int b) {
    return a > b ? a : b;
}

int maxFrequency(int* nums, int numsSize, int k) {
    int base = 0;

    for (int i = 0; i < numsSize; i++)
        if (nums[i] == k)
            base++;

    int ans = base;

    for (int v = 1; v <= 50; v++) {
        if (v == k)
            continue;

        int cur = 0;
        int best = 0;

        for (int i = 0; i < numsSize; i++) {
            int w = 0;

            if (nums[i] == v)
                w = 1;
            else if (nums[i] == k)
                w = -1;

            cur = max(w, cur + w);
            best = max(best, cur);
        }

        ans = max(ans, base + best);
    }

    return ans;
}