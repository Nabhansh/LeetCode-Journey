#include <stdlib.h>

int* finalPrices(
    int* prices,
    int pricesSize,
    int* returnSize
)
{
    int *answer = malloc(pricesSize * sizeof(int));

    int *stack = malloc(pricesSize * sizeof(int));

    int top = -1;

    for (int i = 0; i < pricesSize; i++)
    {
        while (top >= 0 &&
               prices[stack[top]] >= prices[i])
        {
            int index = stack[top--];

            answer[index] =
                prices[index] - prices[i];
        }

        stack[++top] = i;
    }

    while (top >= 0)
    {
        int index = stack[top--];

        answer[index] = prices[index];
    }

    free(stack);

    *returnSize = pricesSize;

    return answer;
}