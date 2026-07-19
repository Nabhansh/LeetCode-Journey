#include <stdlib.h>

int R, C;

int cmp(const void *a, const void *b) {
    int *x = *(int **)a;
    int *y = *(int **)b;

    int d1 = abs(x[0] - R) + abs(x[1] - C);
    int d2 = abs(y[0] - R) + abs(y[1] - C);

    return d1 - d2;
}

int** allCellsDistOrder(int rows, int cols, int rCenter, int cCenter,
                        int* returnSize, int** returnColumnSizes) {
    int total = rows * cols;

    int **ans = (int **)malloc(total * sizeof(int *));
    *returnColumnSizes = (int *)malloc(total * sizeof(int));

    int idx = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            ans[idx] = (int *)malloc(2 * sizeof(int));
            ans[idx][0] = i;
            ans[idx][1] = j;
            (*returnColumnSizes)[idx] = 2;
            idx++;
        }
    }

    R = rCenter;
    C = cCenter;

    qsort(ans, total, sizeof(int *), cmp);

    *returnSize = total;
    return ans;
}