#include <stdlib.h>

typedef struct {
    int soldiers;
    int index;
} Row;

static int cmp(const void *a, const void *b) {
    Row *x = (Row *)a;
    Row *y = (Row *)b;

    if (x->soldiers != y->soldiers)
        return x->soldiers - y->soldiers;

    return x->index - y->index;
}

int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize) {
    Row *rows = (Row *)malloc(matSize * sizeof(Row));

    for (int i = 0; i < matSize; i++) {
        int cnt = 0;
        while (cnt < matColSize[i] && mat[i][cnt] == 1)
            cnt++;

        rows[i].soldiers = cnt;
        rows[i].index = i;
    }

    qsort(rows, matSize, sizeof(Row), cmp);

    int *ans = (int *)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++)
        ans[i] = rows[i].index;

    free(rows);

    *returnSize = k;
    return ans;
}