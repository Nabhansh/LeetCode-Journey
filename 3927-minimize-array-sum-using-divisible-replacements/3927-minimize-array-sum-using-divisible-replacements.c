long long minArraySum(int* nums, int numsSize) {
    int maxVal = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > maxVal)
            maxVal = nums[i];
    }

    int *freq = calloc(maxVal + 1, sizeof(int));

    for (int i = 0; i < numsSize; i++)
        freq[nums[i]]++;

    long long ans = 0;

    for (int d = 1; d <= maxVal; d++) {
        if (freq[d] == 0)
            continue;

        for (int x = d; x <= maxVal; x += d) {
            if (freq[x] > 0) {
                ans += (long long)freq[x] * d;
                freq[x] = 0;
            }
        }
    }

    free(freq);
    return ans;
}