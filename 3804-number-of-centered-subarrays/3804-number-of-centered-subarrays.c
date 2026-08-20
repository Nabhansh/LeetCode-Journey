int centeredSubarrays(int* nums, int numsSize) {
    int ans = 0;

    for (int i = 0; i < numsSize; i++) {
        int seen[200001] = {0};
        int sum = 0;

        for (int j = i; j < numsSize; j++) {
            sum += nums[j];
            seen[nums[j] + 100000] = 1;

            if (sum >= -100000 && sum <= 100000 &&
                seen[sum + 100000])
                ans++;
        }
    }

    return ans;
}