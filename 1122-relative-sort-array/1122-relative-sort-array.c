#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

/**
 * Note: The returned array must be malloced.
 */
int* relativeSortArray(int* arr1, int arr1Size,
                       int* arr2, int arr2Size,
                       int* returnSize) {

    *returnSize = arr1Size;
    int *ans = (int *)malloc(arr1Size * sizeof(int));

    int freq[1001] = {0};

    for (int i = 0; i < arr1Size; i++)
        freq[arr1[i]]++;

    int idx = 0;

    for (int i = 0; i < arr2Size; i++) {
        while (freq[arr2[i]]--)
            ans[idx++] = arr2[i];
    }

    int rest[1001];
    int m = 0;

    for (int i = 0; i <= 1000; i++) {
        while (freq[i]-- > 0)
            rest[m++] = i;
    }

    qsort(rest, m, sizeof(int), cmp);

    for (int i = 0; i < m; i++)
        ans[idx++] = rest[i];

    return ans;
}