int minimumArrayLength(int* nums, int numsSize) {
    int mn = nums[0];

    for (int i = 1; i < numsSize; i++)
        if (nums[i] < mn)
            mn = nums[i];

    int cnt = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % mn != 0)
            return 1;
        if (nums[i] == mn)
            cnt++;
    }

    return (cnt + 1) / 2;
}