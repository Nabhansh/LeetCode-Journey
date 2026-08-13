#include <stdlib.h>

static int compareInts(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

long long maximumMedianSum(int *nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compareInts);

    long long answer = 0;

    for (int i = numsSize / 3; i < numsSize; i += 2)
        answer += nums[i];

    return answer;
}