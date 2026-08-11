#include <limits.h>

long long maximumProduct(int* nums, int numsSize, int m)
{
    long long minFirst = LLONG_MAX;
    long long maxFirst = LLONG_MIN;
    long long ans = LLONG_MIN;

    for (int j = m - 1; j < numsSize; ++j)
    {
        int first = nums[j - m + 1];
        int last = nums[j];

        if (first < minFirst)
            minFirst = first;

        if (first > maxFirst)
            maxFirst = first;

        long long p1 = minFirst * last;
        long long p2 = maxFirst * last;

        if (p1 > ans)
            ans = p1;

        if (p2 > ans)
            ans = p2;
    }

    return ans;
}