bool check(int* nums, int numsSize, int** queries, int k) {
    int *diff = calloc(numsSize + 1, sizeof(int));

    for (int i = 0; i < k; i++) {
        int l = queries[i][0];
        int r = queries[i][1];
        int val = queries[i][2];

        diff[l] += val;
        if (r + 1 < numsSize)
            diff[r + 1] -= val;
    }

    int cur = 0;

    for (int i = 0; i < numsSize; i++) {
        cur += diff[i];
        if (cur < nums[i]) {
            free(diff);
            return false;
        }
    }

    free(diff);
    return true;
}

int minZeroArray(int* nums, int numsSize, int** queries,
                 int queriesSize, int* queriesColSize) {

    int lo = 0, hi = queriesSize, ans = -1;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (check(nums, numsSize, queries, mid)) {
            ans = mid;
            hi = mid - 1;
        } else
            lo = mid + 1;
    }

    return ans;
}