#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Pair;

int cmpVal(const void *a, const void *b) {
    return ((Pair *)a)->val - ((Pair *)b)->val;
}

int cmpInt(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}

int* lexicographicallySmallestArray(int* nums, int numsSize, int limit, int* returnSize) {
    Pair *arr = (Pair *)malloc(numsSize * sizeof(Pair));
    int *ans = (int *)malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].idx = i;
    }

    qsort(arr, numsSize, sizeof(Pair), cmpVal);

    int i = 0;
    while (i < numsSize) {
        int j = i;
        while (j + 1 < numsSize && arr[j + 1].val - arr[j].val <= limit)
            j++;

        int len = j - i + 1;

        int *idx = (int *)malloc(len * sizeof(int));
        int *val = (int *)malloc(len * sizeof(int));

        for (int k = 0; k < len; k++) {
            idx[k] = arr[i + k].idx;
            val[k] = arr[i + k].val;
        }

        qsort(idx, len, sizeof(int), cmpInt);

        for (int k = 0; k < len; k++)
            ans[idx[k]] = val[k];

        free(idx);
        free(val);
        i = j + 1;
    }

    free(arr);
    *returnSize = numsSize;
    return ans;
}