#include <stdlib.h>

int minChanges(int* nums, int numsSize, int k) {
    int pairs = numsSize / 2;

    int *diff = (int *)calloc(k + 2, sizeof(int));
    int *cnt = (int *)calloc(k + 1, sizeof(int));

    for (int i = 0; i < pairs; i++) {
        int a = nums[i];
        int b = nums[numsSize - 1 - i];

        int d = abs(a - b);
        cnt[d]++;

        int mx = a > b ? a : b;
        int mn = a < b ? a : b;

        int limit = mx > (k - mn) ? mx : (k - mn);

        diff[0]++;
        diff[limit + 1]--;
    }

    int oneChange = 0;
    int ans = pairs;

    for (int x = 0; x <= k; x++) {
        oneChange += diff[x];

        int cost = oneChange - cnt[x];
        cost += (pairs - oneChange) * 2;

        if (cost < ans)
            ans = cost;
    }

    free(diff);
    free(cnt);

    return ans;
}