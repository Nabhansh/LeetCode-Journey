#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

long long maxSum(int* nums, int numsSize, int k, int mul) {
    qsort(nums, numsSize, sizeof(int), cmp);

    long long ans = 0;

    for (int i = numsSize - 1; i >= numsSize - k; i--) {
        int m = mul > 1 ? mul : 1;
        ans += (long long)nums[i] * m;
        mul--;
    }

    return ans;
}