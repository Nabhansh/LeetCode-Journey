int minimumPrefixLength(int* nums, int numsSize) {
    for (int i = numsSize - 1; i > 0; i--) {
        if (nums[i - 1] >= nums[i])
            return i;
    }
    return 0;
}