#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int **x = (int **)a;
    int **y = (int **)b;

    if (x[0][0] != y[0][0])
        return x[0][0] - y[0][0];

    return x[0][1] - y[0][1];
}

int** filterOccupiedIntervals(
    int** occupiedIntervals,
    int occupiedIntervalsSize,
    int* occupiedIntervalsColSize,
    int freeStart,
    int freeEnd,
    int* returnSize,
    int** returnColumnSizes
) {
    qsort(
        occupiedIntervals,
        occupiedIntervalsSize,
        sizeof(int *),
        cmp
    );

    int **busy = malloc(occupiedIntervalsSize * sizeof(int *));

    int m = 0;

    for (int i = 0; i < occupiedIntervalsSize; i++) {
        if (m == 0 || busy[m - 1][1] + 1 < occupiedIntervals[i][0]) {
            busy[m++] = occupiedIntervals[i];
        } else if (occupiedIntervals[i][1] > busy[m - 1][1]) {
            busy[m - 1][1] = occupiedIntervals[i][1];
        }
    }

    int **ans = malloc(2 * occupiedIntervalsSize * sizeof(int *));
    *returnColumnSizes = malloc(2 * occupiedIntervalsSize * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < m; i++) {
        int s = busy[i][0];
        int e = busy[i][1];

        if (e < freeStart || s > freeEnd) {
            ans[*returnSize] = malloc(2 * sizeof(int));
            ans[*returnSize][0] = s;
            ans[*returnSize][1] = e;
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;
        } else {
            if (s < freeStart) {
                ans[*returnSize] = malloc(2 * sizeof(int));
                ans[*returnSize][0] = s;
                ans[*returnSize][1] = freeStart - 1;
                (*returnColumnSizes)[*returnSize] = 2;
                (*returnSize)++;
            }

            if (e > freeEnd) {
                ans[*returnSize] = malloc(2 * sizeof(int));
                ans[*returnSize][0] = freeEnd + 1;
                ans[*returnSize][1] = e;
                (*returnColumnSizes)[*returnSize] = 2;
                (*returnSize)++;
            }
        }
    }

    free(busy);

    return ans;
}