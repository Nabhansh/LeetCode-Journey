#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

double trimMean(int* arr, int arrSize) {
    qsort(arr, arrSize, sizeof(int), compare);

    int remove = arrSize / 20;
    long long sum = 0;

    for (int i = remove; i < arrSize - remove; i++)
        sum += arr[i];

    return (double)sum / (arrSize - 2 * remove);
}