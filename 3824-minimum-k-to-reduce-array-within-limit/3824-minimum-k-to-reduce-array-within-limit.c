int minimumK(int* nums, int numsSize) {
    int l = 1, r = 100000;

    while (l < r) {
        int k = l + (r - l) / 2;
        long long ops = 0;

        for (int i = 0; i < numsSize; i++) {
            ops += (nums[i] + k - 1) / k;
            if (ops > 1LL * k * k)
                break;
        }

        if (ops <= 1LL * k * k)
            r = k;
        else
            l = k + 1;
    }

    return l;
}