#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int heightChecker(int* heights, int heightsSize) {
    int *sorted = (int *)malloc(heightsSize * sizeof(int));

    for (int i = 0; i < heightsSize; i++)
        sorted[i] = heights[i];

    qsort(sorted, heightsSize, sizeof(int), cmp);

    int ans = 0;

    for (int i = 0; i < heightsSize; i++)
        if (heights[i] != sorted[i])
            ans++;

    free(sorted);
    return ans;
}