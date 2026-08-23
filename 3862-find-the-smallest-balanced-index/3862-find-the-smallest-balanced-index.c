int smallestBalancedIndex(int* nums, int numsSize) {
    long long sum = 0;
    long long product = 1;

    for (int i = 0; i < numsSize; i++)
        sum += nums[i];

    for (int i = numsSize - 1; i >= 0; i--) {
        sum -= nums[i];

        if (sum == product)
            return i;

        if (product > sum / nums[i])
            break;

        product *= nums[i];
    }

    return -1;
}