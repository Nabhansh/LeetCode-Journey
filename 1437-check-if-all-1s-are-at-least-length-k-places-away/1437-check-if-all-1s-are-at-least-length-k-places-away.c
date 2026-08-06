#include <stdbool.h>

bool kLengthApart(int* nums, int numsSize, int k) {
    int last = -1;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            if (last != -1 && i - last - 1 < k)
                return false;
            last = i;
        }
    }

    return true;
}