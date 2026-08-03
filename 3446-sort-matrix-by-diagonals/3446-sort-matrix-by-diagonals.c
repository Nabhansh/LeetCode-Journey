#include <stdlib.h>

static int cmpAsc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

static int cmpDesc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int** sortMatrix(int** grid, int gridSize, int* gridColSize,
                 int* returnSize, int** returnColumnSizes) {
    int n = gridSize;
    int *tmp = (int *)malloc(n * sizeof(int));

    // Diagonals starting from first column
    for (int r = 0; r < n; r++) {
        int len = 0;
        int i = r, j = 0;

        while (i < n && j < n)
            tmp[len++] = grid[i++][j++];

        qsort(tmp, len, sizeof(int), cmpDesc);

        i = r;
        j = 0;
        for (int k = 0; k < len; k++)
            grid[i++][j++] = tmp[k];
    }

    // Diagonals starting from first row (excluding main diagonal)
    for (int c = 1; c < n; c++) {
        int len = 0;
        int i = 0, j = c;

        while (i < n && j < n)
            tmp[len++] = grid[i++][j++];

        qsort(tmp, len, sizeof(int), cmpAsc);

        i = 0;
        j = c;
        for (int k = 0; k < len; k++)
            grid[i++][j++] = tmp[k];
    }

    free(tmp);

    *returnSize = n;
    *returnColumnSizes = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        (*returnColumnSizes)[i] = n;

    return grid;
}