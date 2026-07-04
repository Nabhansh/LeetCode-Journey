#include <stdbool.h>

bool canSortArray(int* nums, int numsSize) {
    int i = 0;
    int prevMax = 0;

    while (i < numsSize) {
        int bits = __builtin_popcount(nums[i]);
        int curMin = nums[i];
        int curMax = nums[i];

        int j = i + 1;
        while (j < numsSize && __builtin_popcount(nums[j]) == bits) {
            if (nums[j] < curMin) curMin = nums[j];
            if (nums[j] > curMax) curMax = nums[j];
            j++;
        }

        if (curMin < prevMax)
            return false;

        prevMax = curMax;
        i = j;
    }

    return true;
}