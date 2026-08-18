#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int countElements(int* nums, int numsSize, int k)
{
    if (k == 0)
        return numsSize;

    qsort(nums, numsSize, sizeof(int), cmp);

    int threshold = nums[numsSize - k];
    int ans = 0;

    for (int i = 0; i < numsSize - k; i++)
    {
        if (nums[i] < threshold)
            ans++;
    }

    return ans;
}