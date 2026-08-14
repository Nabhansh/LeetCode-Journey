#include <stdbool.h>

bool partitionArray(int* nums, int numsSize, int k)
{
    if (numsSize % k != 0)
        return false;

    int groups = numsSize / k;
    int freq[100001] = {0};

    for (int i = 0; i < numsSize; i++)
    {
        freq[nums[i]]++;

        if (freq[nums[i]] > groups)
            return false;
    }

    return true;
}