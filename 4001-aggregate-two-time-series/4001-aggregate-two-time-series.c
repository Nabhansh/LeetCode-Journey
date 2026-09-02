#include <stdlib.h>

int** aggregateTimeSeries(
    int** series1, int series1Size, int* series1ColSize,
    int** series2, int series2Size, int* series2ColSize,
    int* returnSize, int** returnColumnSizes
) {
    int maxSize = series1Size + series2Size;
    int** ans = malloc(sizeof(int*) * maxSize);
    *returnColumnSizes = malloc(sizeof(int) * maxSize);

    int i = 0, j = 0, k = 0;

    while (i < series1Size && j < series2Size) {
        ans[k] = malloc(sizeof(int) * 2);
        (*returnColumnSizes)[k] = 2;

        if (series1[i][0] == series2[j][0]) {
            ans[k][0] = series1[i][0];
            ans[k][1] = series1[i][1] + series2[j][1];
            i++;
            j++;
        } else if (series1[i][0] < series2[j][0]) {
            ans[k][0] = series1[i][0];
            ans[k][1] = series1[i][1] + series2[j][1];
            i++;
        } else {
            ans[k][0] = series2[j][0];
            ans[k][1] = series1[i][1] + series2[j][1];
            j++;
        }

        k++;
    }

    while (i < series1Size) {
        ans[k] = malloc(sizeof(int) * 2);
        ans[k][0] = series1[i][0];
        ans[k][1] = series1[i][1];
        (*returnColumnSizes)[k] = 2;
        i++;
        k++;
    }

    while (j < series2Size) {
        ans[k] = malloc(sizeof(int) * 2);
        ans[k][0] = series2[j][0];
        ans[k][1] = series2[j][1];
        (*returnColumnSizes)[k] = 2;
        j++;
        k++;
    }

    *returnSize = k;
    return ans;
}