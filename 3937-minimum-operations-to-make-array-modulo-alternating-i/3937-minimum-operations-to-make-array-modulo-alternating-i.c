int minOperations(int* nums, int numsSize, int k) {
    long long even[100] = {0};
    long long odd[100] = {0};

    for (int i = 0; i < numsSize; i++) {
        int v = nums[i] % k;

        for (int r = 0; r < k; r++) {
            int d = abs(v - r);
            int cost = d < k - d ? d : k - d;

            if (i % 2 == 0)
                even[r] += cost;
            else
                odd[r] += cost;
        }
    }

    long long ans = 1LL << 60;

    for (int x = 0; x < k; x++) {
        for (int y = 0; y < k; y++) {
            if (x != y) {
                long long cost = even[x] + odd[y];

                if (cost < ans)
                    ans = cost;
            }
        }
    }

    return (int)ans;
}