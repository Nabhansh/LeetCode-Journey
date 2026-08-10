#include <stdlib.h>

int maxSumDistinctTriplet(int* x, int xSize,
                          int* y, int ySize)
{
    int maxX = 1000000;

    int *best = malloc((maxX + 1) * sizeof(int));

    for (int i = 0; i <= maxX; i++)
        best[i] = -1;

    /* Keep the maximum y for every x */
    for (int i = 0; i < xSize; i++)
    {
        if (y[i] > best[x[i]])
            best[x[i]] = y[i];
    }

    int first = -1;
    int second = -1;
    int third = -1;

    for (int value = 1; value <= maxX; value++)
    {
        if (best[value] == -1)
            continue;

        int current = best[value];

        if (current > first)
        {
            third = second;
            second = first;
            first = current;
        }
        else if (current > second)
        {
            third = second;
            second = current;
        }
        else if (current > third)
        {
            third = current;
        }
    }

    free(best);

    if (third == -1)
        return -1;

    return first + second + third;
}