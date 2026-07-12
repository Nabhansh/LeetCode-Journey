#include <stdlib.h>

int compare(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;

    return (x > y) - (x < y);
}

int binarySearch(int* arr, int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int* arrayRankTransform(int* arr, int arrSize, int* returnSize) {
    int* answer = (int*)malloc(arrSize * sizeof(int));
    int* sorted = (int*)malloc(arrSize * sizeof(int));

    for (int i = 0; i < arrSize; i++) {
        sorted[i] = arr[i];
    }

    qsort(sorted, arrSize, sizeof(int), compare);

    // Remove duplicates
    int uniqueSize = 0;

    for (int i = 0; i < arrSize; i++) {
        if (i == 0 || sorted[i] != sorted[i - 1]) {
            sorted[uniqueSize++] = sorted[i];
        }
    }

    // Find rank of every element
    for (int i = 0; i < arrSize; i++) {
        int index = binarySearch(sorted, uniqueSize, arr[i]);
        answer[i] = index + 1;
    }

    free(sorted);

    *returnSize = arrSize;
    return answer;
}