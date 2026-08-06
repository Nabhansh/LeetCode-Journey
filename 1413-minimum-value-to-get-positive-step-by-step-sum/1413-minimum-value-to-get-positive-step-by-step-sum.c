int minStartValue(int* nums, int numsSize) {
    int sum = 0;
    int minPrefix = 0;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        if (sum < minPrefix)
            minPrefix = sum;
    }

    return 1 - minPrefix;
}