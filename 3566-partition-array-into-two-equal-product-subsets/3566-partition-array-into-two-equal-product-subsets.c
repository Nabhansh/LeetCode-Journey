#include <stdbool.h>

bool checkEqualPartitions(int* nums, int numsSize, long long target)
{
    int total = 1 << numsSize;

    for (int mask = 1; mask < total - 1; mask++)
    {
        long long product1 = 1;
        long long product2 = 1;

        for (int i = 0; i < numsSize; i++)
        {
            if (mask & (1 << i))
                product1 *= nums[i];
            else
                product2 *= nums[i];

            if (product1 > target || product2 > target)
                break;
        }

        if (product1 == target && product2 == target)
            return true;
    }

    return false;
}