#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes) {
    qsort(arr, arrSize, sizeof(int), cmp);

    int minDiff = 1e9;
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] - arr[i - 1] < minDiff)
            minDiff = arr[i] - arr[i - 1];
    }

    int cnt = 0;
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] - arr[i - 1] == minDiff)
            cnt++;
    }

    int **ans = (int **)malloc(cnt * sizeof(int *));
    *returnColumnSizes = (int *)malloc(cnt * sizeof(int));

    int idx = 0;
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] - arr[i - 1] == minDiff) {
            ans[idx] = (int *)malloc(2 * sizeof(int));
            ans[idx][0] = arr[i - 1];
            ans[idx][1] = arr[i];
            (*returnColumnSizes)[idx] = 2;
            idx++;
        }
    }

    *returnSize = cnt;
    return ans;
}