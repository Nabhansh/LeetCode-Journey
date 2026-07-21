#include <stdlib.h>

#define MAXV 1000000

int minOperations(int* nums, int numsSize) {
    static int spf[MAXV + 1];
    static int initialized = 0;

    if (!initialized) {
        for (int i = 0; i <= MAXV; i++)
            spf[i] = 0;

        for (int i = 2; i <= MAXV; i++) {
            if (spf[i] == 0) {
                for (int j = i; j <= MAXV; j += i) {
                    if (spf[j] == 0)
                        spf[j] = i;
                }
            }
        }
        spf[1] = 1;
        initialized = 1;
    }

    int ans = 0;

    for (int i = numsSize - 2; i >= 0; i--) {
        if (nums[i] <= nums[i + 1])
            continue;

        nums[i] = spf[nums[i]];
        ans++;

        if (nums[i] > nums[i + 1])
            return -1;
    }

    return ans;
}