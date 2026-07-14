int valueAfterKSeconds(int n, int k) {
    const int MOD = 1000000007;

    long long nums[n];

    for (int i = 0; i < n; i++) {
        nums[i] = 1;
    }

    for (int second = 0; second < k; second++) {

        for (int i = 1; i < n; i++) {
            nums[i] = (nums[i] + nums[i - 1]) % MOD;
        }
    }

    return (int)nums[n - 1];
}