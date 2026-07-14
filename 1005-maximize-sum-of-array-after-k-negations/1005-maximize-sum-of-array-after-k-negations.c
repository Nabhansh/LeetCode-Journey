#include <stdlib.h>

int compare(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;

    return (x > y) - (x < y);
}

int largestSumAfterKNegations(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 0; i < numsSize && k > 0; i++) {
        if (nums[i] < 0) {
            nums[i] = -nums[i];
            k--;
        }
    }

    int sum = 0;
    int minAbs = nums[0] < 0 ? -nums[0] : nums[0];

    for (int i = 0; i < numsSize; i++) {
        int absValue = nums[i] < 0 ? -nums[i] : nums[i];

        sum += nums[i];

        if (absValue < minAbs) {
            minAbs = absValue;
        }
    }

    if (k % 2 == 1) {
        sum -= 2 * minAbs;
    }

    return sum;
}