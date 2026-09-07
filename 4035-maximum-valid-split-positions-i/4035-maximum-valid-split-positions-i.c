int gcd(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int calc(int *a, int n) {
    if (n < 2) return 0;

    int pre[n], suf[n];

    pre[0] = a[0];
    for (int i = 1; i < n; i++)
        pre[i] = gcd(pre[i - 1], a[i]);

    suf[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suf[i] = gcd(suf[i + 1], a[i]);

    int ans = 0;

    for (int i = 0; i < n - 1; i++)
        if (pre[i] == suf[i + 1])
            ans++;

    return ans;
}

int maxValidSplits(int* nums, int numsSize) {
    int ans = calc(nums, numsSize);
    int arr[numsSize - 1];

    for (int del = 0; del < numsSize; del++) {
        int k = 0;

        for (int i = 0; i < numsSize; i++)
            if (i != del)
                arr[k++] = nums[i];

        int cur = calc(arr, numsSize - 1);

        if (cur > ans)
            ans = cur;
    }

    return ans;
}