#include <stdlib.h>

int oddCells(int m, int n, int** indices, int indicesSize, int* indicesColSize) {
    int *rows = calloc(m, sizeof(int));
    int *cols = calloc(n, sizeof(int));

    for (int i = 0; i < indicesSize; i++) {
        rows[indices[i][0]]++;
        cols[indices[i][1]]++;
    }

    int ans = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((rows[i] + cols[j]) % 2)
                ans++;
        }
    }

    free(rows);
    free(cols);

    return ans;
}