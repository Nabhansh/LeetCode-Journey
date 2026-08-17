#include <stdlib.h>

int compareInt(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

long long maxProduct(int* nums, int numsSize)
{
    qsort(
        nums,
        numsSize,
        sizeof(int),
        compareInt
    );

    long long smallest1 = nums[0];
    long long smallest2 = nums[1];

    long long largest1 = nums[numsSize - 1];
    long long largest2 = nums[numsSize - 2];

    const long long MAX_VALUE = 100000;
    const long long MIN_VALUE = -100000;

    long long candidate1 =
        smallest1 * smallest2 * MAX_VALUE;

    long long candidate2 =
        largest1 * largest2 * MAX_VALUE;

    long long candidate3 =
        smallest1 * largest1 * MIN_VALUE;

    long long answer = candidate1;

    if (candidate2 > answer)
        answer = candidate2;

    if (candidate3 > answer)
        answer = candidate3;

    return answer;
}