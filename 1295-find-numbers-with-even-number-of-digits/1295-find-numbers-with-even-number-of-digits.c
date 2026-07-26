int findNumbers(int* nums, int numsSize) {
    int ans = 0;

    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        int digits = 0;

        while (x) {
            digits++;
            x /= 10;
        }

        if (digits % 2 == 0)
            ans++;
    }

    return ans;
}