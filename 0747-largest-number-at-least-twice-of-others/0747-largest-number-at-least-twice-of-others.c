int dominantIndex(int* nums, int numsSize) {
    int max = -1, second = -1, index = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max) {
            second = max;
            max = nums[i];
            index = i;
        } else if (nums[i] > second) {
            second = nums[i];
        }
    }

    return (max >= 2 * second) ? index : -1;
}