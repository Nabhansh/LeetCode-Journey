int compareBitonicSums(int* nums, int numsSize) {
    long long left = nums[0];
    long long right = 0;

    for (int i = 0; i < numsSize; i++)
        right += nums[i];

    for (int i = 1; i < numsSize; i++) {
        if (nums[i - 1] > nums[i])
            break;

        left += nums[i];
        right -= nums[i - 1];
    }

    if (left == right)
        return -1;

    return left > right ? 0 : 1;
}