long long minOperations(int* nums, int numsSize) {
    long long ans = 0;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < nums[i - 1])
            ans += (long long)nums[i - 1] - nums[i];
    }

    return ans;
}