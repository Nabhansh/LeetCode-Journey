#include <stdlib.h>

long long bowlSubarrays(int* nums, int numsSize)
{
    int *stack = malloc(numsSize * sizeof(int));
    int top = -1;
    long long ans = 0;

    for (int i = 0; i < numsSize; i++)
    {
        while (top >= 0 && nums[stack[top]] < nums[i])
        {
            if (i - stack[top] > 1)
                ans++;

            top--;
        }

        stack[++top] = i;
    }

    top = -1;

    for (int i = numsSize - 1; i >= 0; i--)
    {
        while (top >= 0 && nums[stack[top]] < nums[i])
        {
            if (stack[top] - i > 1)
                ans++;

            top--;
        }

        stack[++top] = i;
    }

    free(stack);
    return ans;
}