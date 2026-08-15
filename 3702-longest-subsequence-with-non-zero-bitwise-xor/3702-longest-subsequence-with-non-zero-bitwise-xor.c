int longestSubsequence(int* nums, int numsSize) {
    int n = numsSize;

    int allZero = 1;

    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            allZero = 0;
            break;
        }
    }

    if (allZero) {
        return 0;
    }

    int x = 0;

    for (int i = 0; i < n; i++) {
        x ^= nums[i];
    }

    return x ? n : n - 1;

}