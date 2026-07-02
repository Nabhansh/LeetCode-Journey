long long countSubarrays(int* nums, int numsSize, int k) {
    int maxVal = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > maxVal)
            maxVal = nums[i];
    }

    long long ans = 0;
    int left = 0, cnt = 0;

    for (int right = 0; right < numsSize; right++) {
        if (nums[right] == maxVal)
            cnt++;

        while (cnt >= k) {
            if (nums[left] == maxVal)
                cnt--;
            left++;
        }

        ans += left;
    }

    return ans;
}