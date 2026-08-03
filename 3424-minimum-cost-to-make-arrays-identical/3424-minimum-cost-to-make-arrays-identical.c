#include <stdlib.h>

static int cmp(const void *a, const void *b) {
    long long x = *(const long long *)a;
    long long y = *(const long long *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

long long minCost(int* arr, int arrSize, int* brr, int brrSize, long long k) {
    long long direct = 0;

    // Cost without rearranging
    for (int i = 0; i < arrSize; i++) {
        long long diff = (long long)arr[i] - brr[i];
        if (diff < 0) diff = -diff;
        direct += diff;
    }

    // Copy arrays
    long long *a = (long long *)malloc(sizeof(long long) * arrSize);
    long long *b = (long long *)malloc(sizeof(long long) * brrSize);

    for (int i = 0; i < arrSize; i++) a[i] = arr[i];
    for (int i = 0; i < brrSize; i++) b[i] = brr[i];

    qsort(a, arrSize, sizeof(long long), cmp);
    qsort(b, brrSize, sizeof(long long), cmp);

    long long rearrange = k;

    for (int i = 0; i < arrSize; i++) {
        long long diff = a[i] - b[i];
        if (diff < 0) diff = -diff;
        rearrange += diff;
    }

    free(a);
    free(b);

    return direct < rearrange ? direct : rearrange;
}