#include <stdio.h>

int longestSubarray(int* nums, int numsSize)
{
    int current = 2;
    int answer = 2;

    for (int i = 2; i < numsSize; i++)
    {
        if (nums[i] == nums[i - 1] + nums[i - 2])
        {
            current++;
        }
        else
        {
            current = 2;
        }

        if (current > answer)
            answer = current;
    }

    return answer;
}