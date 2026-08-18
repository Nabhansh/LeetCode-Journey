#include <stdlib.h>
#include <limits.h>

int isPalindrome(int x)
{
    int a = x;
    int b = 0;

    while (x)
    {
        b = (b << 1) | (x & 1);
        x >>= 1;
    }

    return a == b;
}

int* minOperations(int* nums, int numsSize, int* returnSize)
{
    int* p = malloc(8192 * sizeof(int));
    int count = 0;

    for (int i = 1; i <= 8191; i++)
    {
        if (isPalindrome(i))
            p[count++] = i;
    }

    int* ans = malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++)
    {
        int x = nums[i];
        int l = 0;
        int r = count - 1;

        while (l < r)
        {
            int m = l + (r - l) / 2;

            if (p[m] < x)
                l = m + 1;
            else
                r = m;
        }

        int best = INT_MAX;

        if (l < count)
            best = p[l] - x;

        if (l > 0 && x - p[l - 1] < best)
            best = x - p[l - 1];

        ans[i] = best;
    }

    free(p);

    *returnSize = numsSize;
    return ans;
}