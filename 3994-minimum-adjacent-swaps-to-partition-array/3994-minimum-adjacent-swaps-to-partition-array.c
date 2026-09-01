int minAdjacentSwaps(int* nums, int numsSize, int a, int b) {
    const long long MOD = 1000000007;
    long long low = 0;
    long long mid = 0;
    long long ans = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < a) {
            ans = (ans + mid + low) % MOD;
        } else if (nums[i] <= b) {
            ans = (ans + low) % MOD;
            mid++;
        } else {
            low++;
        }
    }

    return (int)ans;
}