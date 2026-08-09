#include <stdlib.h>

int* runningSum(
    int* nums,
    int numsSize,
    int* returnSize
)
{
    int *answer = malloc(numsSize * sizeof(int));

    int sum = 0;

    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
        answer[i] = sum;
    }

    *returnSize = numsSize;

    return answer;
}