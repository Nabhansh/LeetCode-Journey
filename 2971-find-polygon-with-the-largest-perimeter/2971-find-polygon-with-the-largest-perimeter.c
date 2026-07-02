#include <stdlib.h>

int cmp(const void *a, const void *b) {
    long long x = *(int *)a;
    long long y = *(int *)b;
    return (x > y) - (x < y);
}

long long largestPerimeter(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    long long sum = 0;

    for (int i = 0; i < numsSize; i++)
        sum += nums[i];

    for (int i = numsSize - 1; i >= 0; i--) {
        if (sum - nums[i] > nums[i])
            return sum;
        sum -= nums[i];
    }

    return -1;
}