int minLength(int* nums, int numsSize, int k) {
    int *freq = calloc(100001, sizeof(int));
    int left = 0;
    int ans = numsSize + 1;
    long long sum = 0;

    for (int right = 0; right < numsSize; right++) {
        if (freq[nums[right]] == 0)
            sum += nums[right];

        freq[nums[right]]++;

        while (sum >= k) {
            int len = right - left + 1;
            if (len < ans)
                ans = len;

            freq[nums[left]]--;

            if (freq[nums[left]] == 0)
                sum -= nums[left];

            left++;
        }
    }

    free(freq);

    return ans == numsSize + 1 ? -1 : ans;
}