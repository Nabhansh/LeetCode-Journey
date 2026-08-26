int countDigitOccurrences(int* nums, int numsSize, int digit) {
    int ans = 0;

    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];

        while (x > 0) {
            if (x % 10 == digit)
                ans++;
            x /= 10;
        }
    }

    return ans;
}