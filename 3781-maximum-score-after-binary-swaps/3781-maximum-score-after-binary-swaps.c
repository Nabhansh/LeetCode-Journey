#include <stdlib.h>

void push(int *heap, int *size, int value) {
    int i = (*size)++;
    heap[i] = value;

    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] >= heap[i])
            break;

        int temp = heap[p];
        heap[p] = heap[i];
        heap[i] = temp;
        i = p;
    }
}

int pop(int *heap, int *size) {
    int result = heap[0];
    heap[0] = heap[--(*size)];

    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < *size && heap[left] > heap[largest])
            largest = left;

        if (right < *size && heap[right] > heap[largest])
            largest = right;

        if (largest == i)
            break;

        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        i = largest;
    }

    return result;
}

long long maximumScore(int* nums, int numsSize, char* s) {
    int *heap = malloc(numsSize * sizeof(int));
    int size = 0;
    long long ans = 0;

    for (int i = 0; i < numsSize; i++) {
        push(heap, &size, nums[i]);

        if (s[i] == '1')
            ans += pop(heap, &size);
    }

    free(heap);
    return ans;
}