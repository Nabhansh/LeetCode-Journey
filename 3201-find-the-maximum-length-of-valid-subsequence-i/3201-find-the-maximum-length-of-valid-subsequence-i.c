int maximumLength(int* nums, int numsSize) {
    int even = 0;
    int odd = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    int alternating = 1;

    for (int i = 1; i < numsSize; i++) {
        if ((nums[i] % 2) != (nums[i - 1] % 2)) {
            alternating++;
        }
    }

    int ans = even > odd ? even : odd;

    return ans > alternating ? ans : alternating;
}