#include <stdlib.h>

int compare(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;

    return (x > y) - (x < y);
}

long long minOperationsToMakeMedianK(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);

    int mid = numsSize / 2;
    long long operations = 0;

    if (nums[mid] < k) {
        for (int i = mid; i < numsSize; i++) {
            if (nums[i] < k) {
                operations += (long long)k - nums[i];
            }
        }
    } 
    else if (nums[mid] > k) {
        for (int i = 0; i <= mid; i++) {
            if (nums[i] > k) {
                operations += (long long)nums[i] - k;
            }
        }
    }

    return operations;
}