#include <stdlib.h>

typedef struct
{
    int value;
    int sum;
    int index;
} Item;

int digitSum(int x)
{
    int sum = 0;

    while (x > 0)
    {
        sum += x % 10;
        x /= 10;
    }

    return sum;
}

int compare(const void *a, const void *b)
{
    Item *x = (Item *)a;
    Item *y = (Item *)b;

    /*
        First sort by digit sum.
    */

    if (x->sum != y->sum)
        return x->sum - y->sum;

    /*
        If digit sums are equal,
        sort by value.
    */

    return x->value - y->value;
}

int minSwaps(int* nums, int numsSize)
{
    Item *items = malloc(numsSize * sizeof(Item));

    /*
        Store value, digit sum,
        and original position.
    */

    for (int i = 0; i < numsSize; i++)
    {
        items[i].value = nums[i];
        items[i].sum = digitSum(nums[i]);
        items[i].index = i;
    }

    /*
        Sort according to:
        1. digit sum
        2. value
    */

    qsort(
        items,
        numsSize,
        sizeof(Item),
        compare
    );

    /*
        visited[i] tells whether
        position i has already been
        processed as part of a cycle.
    */

    int *visited = calloc(numsSize, sizeof(int));

    int swaps = 0;

    for (int i = 0; i < numsSize; i++)
    {
        /*
            Already in correct position.
        */

        if (visited[i] || items[i].index == i)
            continue;

        /*
            Find the cycle.
        */

        int cycleSize = 0;
        int j = i;

        while (!visited[j])
        {
            visited[j] = 1;

            /*
                items[j].index tells us
                where this element came from.
            */

            j = items[j].index;

            cycleSize++;
        }

        /*
            A cycle of size N requires
            N - 1 swaps.
        */

        swaps += cycleSize - 1;
    }

    free(items);
    free(visited);

    return swaps;
}