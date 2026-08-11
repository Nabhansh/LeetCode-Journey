#include <stdlib.h>

#define MOD 1000000007LL

int countPartitions(int* nums, int numsSize, int k)
{
    long long *dp = calloc(numsSize + 1, sizeof(long long));
    long long *prefix = calloc(numsSize + 1, sizeof(long long));

    int *minDeque = malloc(numsSize * sizeof(int));
    int *maxDeque = malloc(numsSize * sizeof(int));

    int minFront = 0, minBack = 0;
    int maxFront = 0, maxBack = 0;

    dp[0] = 1;
    prefix[0] = 1;

    int left = 0;

    for (int right = 0; right < numsSize; right++)
    {
        while (minBack > minFront &&
               nums[minDeque[minBack - 1]] >= nums[right])
        {
            minBack--;
        }

        minDeque[minBack++] = right;

        while (maxBack > maxFront &&
               nums[maxDeque[maxBack - 1]] <= nums[right])
        {
            maxBack--;
        }

        maxDeque[maxBack++] = right;

        while ((long long)nums[maxDeque[maxFront]]
             - nums[minDeque[minFront]] > k)
        {
            if (minDeque[minFront] == left)
                minFront++;

            if (maxDeque[maxFront] == left)
                maxFront++;

            left++;
        }

        long long sum = prefix[right];

        if (left > 0)
            sum = (sum - prefix[left - 1] + MOD) % MOD;

        dp[right + 1] = sum;

        prefix[right + 1] =
            (prefix[right] + dp[right + 1]) % MOD;
    }

    int answer = (int)dp[numsSize];

    free(dp);
    free(prefix);
    free(minDeque);
    free(maxDeque);

    return answer;
}