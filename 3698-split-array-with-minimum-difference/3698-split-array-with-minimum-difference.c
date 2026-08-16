#include <stdlib.h>

long long splitArray(int *nums, int numsSize)
{
    int n = numsSize;

    long long *prefix = (long long *)malloc(n * sizeof(long long));
    int *inc = (int *)malloc(n * sizeof(int));
    int *dec = (int *)malloc(n * sizeof(int));

    prefix[0] = nums[0];

    inc[0] = 1;

    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + nums[i];

        if (inc[i - 1] && nums[i - 1] < nums[i])
            inc[i] = 1;
        else
            inc[i] = 0;
    }

    dec[n - 1] = 1;

    for (int i = n - 2; i >= 0; i--)
    {
        if (dec[i + 1] && nums[i] > nums[i + 1])
            dec[i] = 1;
        else
            dec[i] = 0;
    }

    long long total = prefix[n - 1];
    long long answer = -1;

    // Split after index i
    // left  = [0 ... i]
    // right = [i+1 ... n-1]
    for (int i = 0; i < n - 1; i++)
    {
        if (inc[i] && dec[i + 1])
        {
            long long leftSum = prefix[i];
            long long rightSum = total - leftSum;

            long long diff = llabs(leftSum - rightSum);

            if (answer == -1 || diff < answer)
                answer = diff;
        }
    }

    free(prefix);
    free(inc);
    free(dec);

    return answer;
}