#include <stdlib.h>

int absVal(int x) {
    return x < 0 ? -x : x;
}

int** resultGrid(int** image, int imageSize, int* imageColSize,
                 int threshold, int* returnSize, int** returnColumnSizes) {

    int m = imageSize;
    int n = imageColSize[0];

    int **sum = (int **)malloc(m * sizeof(int *));
    int **cnt = (int **)malloc(m * sizeof(int *));

    for (int i = 0; i < m; i++) {
        sum[i] = (int *)calloc(n, sizeof(int));
        cnt[i] = (int *)calloc(n, sizeof(int));
    }

    for (int i = 0; i + 2 < m; i++) {
        for (int j = 0; j + 2 < n; j++) {

            int ok = 1;

            for (int r = i; r < i + 3 && ok; r++) {
                for (int c = j; c < j + 2; c++) {
                    if (absVal(image[r][c] - image[r][c + 1]) > threshold) {
                        ok = 0;
                        break;
                    }
                }
            }

            for (int r = i; r < i + 2 && ok; r++) {
                for (int c = j; c < j + 3; c++) {
                    if (absVal(image[r][c] - image[r + 1][c]) > threshold) {
                        ok = 0;
                        break;
                    }
                }
            }

            if (!ok) continue;

            int total = 0;
            for (int r = i; r < i + 3; r++)
                for (int c = j; c < j + 3; c++)
                    total += image[r][c];

            int avg = total / 9;

            for (int r = i; r < i + 3; r++) {
                for (int c = j; c < j + 3; c++) {
                    sum[r][c] += avg;
                    cnt[r][c]++;
                }
            }
        }
    }

    int **ans = (int **)malloc(m * sizeof(int *));
    *returnColumnSizes = (int *)malloc(m * sizeof(int));

    for (int i = 0; i < m; i++) {
        ans[i] = (int *)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;

        for (int j = 0; j < n; j++) {
            if (cnt[i][j] == 0)
                ans[i][j] = image[i][j];
            else
                ans[i][j] = sum[i][j] / cnt[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        free(sum[i]);
        free(cnt[i]);
    }
    free(sum);
    free(cnt);

    *returnSize = m;
    return ans;
}