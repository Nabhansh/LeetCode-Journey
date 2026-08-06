#include <stdio.h>

int maximumPossibleSize(int* nums, int numsSize) {
    int ans = 0;
    int prev = 0;
    
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] >= prev) {
            prev = nums[i];
            ans++;
        }
    }
    
    return ans;
}