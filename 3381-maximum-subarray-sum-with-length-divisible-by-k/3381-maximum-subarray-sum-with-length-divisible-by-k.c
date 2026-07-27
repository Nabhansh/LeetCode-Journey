long long maxSubarraySum(int* nums, int numsSize, int k) {
    const long long INF = (1LL << 60);

    long long *minPrefix = (long long *)malloc(sizeof(long long) * k);

    for (int i = 0; i < k; i++)
        minPrefix[i] = INF;

    minPrefix[k - 1] = 0;

    long long prefix = 0;
    long long ans = -INF;

    for (int i = 0; i < numsSize; i++) {
        prefix += nums[i];

        if (prefix - minPrefix[i % k] > ans)
            ans = prefix - minPrefix[i % k];

        if (prefix < minPrefix[i % k])
            minPrefix[i % k] = prefix;
    }

    free(minPrefix);
    return ans;
}