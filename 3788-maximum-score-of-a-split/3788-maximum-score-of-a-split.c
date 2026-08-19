#include <limits.h>

long long maximumScore(int* nums, int numsSize) {
    long long suffixMin = nums[numsSize - 1];
    long long prefixSum = 0;
    long long ans = LLONG_MIN;

    long long *suffix = malloc(numsSize * sizeof(long long));

    suffix[numsSize - 1] = nums[numsSize - 1];

    for (int i = numsSize - 2; i >= 0; i--) {
        suffix[i] = nums[i] < suffix[i + 1] ? nums[i] : suffix[i + 1];
    }

    for (int i = 0; i < numsSize - 1; i++) {
        prefixSum += nums[i];
        long long score = prefixSum - suffix[i + 1];

        if (score > ans)
            ans = score;
    }

    free(suffix);
    return ans;
}