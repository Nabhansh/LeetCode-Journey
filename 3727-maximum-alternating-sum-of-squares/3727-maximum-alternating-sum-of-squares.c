#include <stdlib.h>

int compareLongLong(const void* a, const void* b)
{
    long long x = *(const long long*)a;
    long long y = *(const long long*)b;

    if (x < y)
        return -1;

    if (x > y)
        return 1;

    return 0;
}

long long maxAlternatingSum(int* nums, int numsSize)
{
    long long* squares =
        (long long*)malloc(sizeof(long long) * numsSize);

    for (int i = 0; i < numsSize; i++)
    {
        long long x = nums[i];
        squares[i] = x * x;
    }

    qsort(
        squares,
        numsSize,
        sizeof(long long),
        compareLongLong
    );

    long long answer = 0;

    int half = numsSize / 2;

    for (int i = 0; i < half; i++)
        answer -= squares[i];

    for (int i = half; i < numsSize; i++)
        answer += squares[i];

    free(squares);

    return answer;
}