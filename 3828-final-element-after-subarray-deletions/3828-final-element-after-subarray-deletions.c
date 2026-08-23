int finalElement(int* nums, int numsSize) {
    return nums[0] > nums[numsSize - 1] ? nums[0] : nums[numsSize - 1];
}