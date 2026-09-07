long long getSum(long long *nums, int l, int r) {
    long long sum = 0;

    for (int i = l; i <= r; i++)
        sum += nums[i];

    return sum;
}

int countGoodRotations(int* nums, int numsSize) {
    int half = numsSize / 2;

    long long first = 0;
    long long total = 0;

    for (int i = 0; i < numsSize; i++)
        total += nums[i];

    for (int i = 0; i < half; i++)
        first += nums[i];

    int ans = 0;

    for (int i = 0; i < numsSize; i++) {
        if (first > total - first)
            ans++;

        first -= nums[i];
        first += nums[(i + half) % numsSize];
    }

    return ans;
}