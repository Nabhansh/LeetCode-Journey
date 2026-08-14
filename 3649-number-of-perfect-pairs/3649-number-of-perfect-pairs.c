#include <stdlib.h>

long long absoluteValue(int x)
{
    long long v = x;

    if (v < 0)
        v = -v;

    return v;
}

int compareLongLong(const void *a, const void *b)
{
    long long x = *(long long *)a;
    long long y = *(long long *)b;

    if (x < y)
        return -1;

    if (x > y)
        return 1;

    return 0;
}

long long perfectPairs(int* nums, int numsSize)
{
    long long *arr = malloc(numsSize * sizeof(long long));

    for (int i = 0; i < numsSize; i++)
        arr[i] = absoluteValue(nums[i]);

    qsort(arr, numsSize, sizeof(long long), compareLongLong);

    long long answer = 0;
    int left = 0;

    for (int right = 0; right < numsSize; right++)
    {
        while (arr[right] > 2 * arr[left])
            left++;

        answer += right - left;
    }

    free(arr);

    return answer;
}