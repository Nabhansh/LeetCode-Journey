#include <stdlib.h>
#include <limits.h>

#define OFFSET 1000
#define SIZE 2001

int getLargestOutlier(int* nums, int numsSize) {
    int freq[SIZE] = {0};
    int sum = 0;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        freq[nums[i] + OFFSET]++;
    }

    int ans = INT_MIN;

    for (int i = 0; i < numsSize; i++) {
        int outlier = nums[i];
        int remain = sum - outlier;

        if (remain & 1)
            continue;

        int target = remain / 2;

        if (target < -1000 || target > 1000)
            continue;

        if (target == outlier) {
            if (freq[target + OFFSET] >= 2 && outlier > ans)
                ans = outlier;
        } else {
            if (freq[target + OFFSET] > 0 && outlier > ans)
                ans = outlier;
        }
    }

    return ans;
}