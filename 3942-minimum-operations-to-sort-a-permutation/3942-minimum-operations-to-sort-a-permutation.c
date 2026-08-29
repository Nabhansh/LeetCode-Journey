int minOperations(int* nums, int numsSize) {
    int n = numsSize;
    int zero = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            zero = i;
            break;
        }
    }

    int right = 1;
    for (int i = 1; i < n; i++) {
        int prev = (zero + i - 1) % n;
        int curr = (zero + i) % n;

        if (nums[prev] > nums[curr]) {
            right = 0;
            break;
        }
    }

    int left = 1;
    for (int i = 1; i < n; i++) {
        int prev = (zero - (i - 1) % n + n) % n;
        int curr = (zero - i % n + n) % n;

        if (nums[prev] > nums[curr]) {
            left = 0;
            break;
        }
    }

    int ans = 1000000000;

    if (right) {
        if (zero < ans)
            ans = zero;

        if (n - zero + 2 < ans)
            ans = n - zero + 2;
    }

    if (left) {
        if (zero + 2 < ans)
            ans = zero + 2;

        if (n - zero < ans)
            ans = n - zero;
    }

    return ans == 1000000000 ? -1 : ans;
}