#include <stdlib.h>

void swap(long long *a, long long *b) {
    long long t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(long long heap[], int idx) {
    while (idx > 0) {
        int p = (idx - 1) / 2;
        if (heap[p] <= heap[idx]) break;
        swap(&heap[p], &heap[idx]);
        idx = p;
    }
}

void heapifyDown(long long heap[], int size, int idx) {
    while (1) {
        int s = idx;
        int l = idx * 2 + 1;
        int r = idx * 2 + 2;

        if (l < size && heap[l] < heap[s]) s = l;
        if (r < size && heap[r] < heap[s]) s = r;

        if (s == idx) break;

        swap(&heap[s], &heap[idx]);
        idx = s;
    }
}

int minOperations(int* nums, int numsSize, int k) {
    long long *heap = (long long *)malloc(sizeof(long long) * numsSize);

    int size = 0;

    for (int i = 0; i < numsSize; i++) {
        heap[size] = nums[i];
        heapifyUp(heap, size);
        size++;
    }

    int ans = 0;

    while (size >= 2 && heap[0] < k) {
        long long x = heap[0];
        heap[0] = heap[--size];
        heapifyDown(heap, size, 0);

        long long y = heap[0];
        heap[0] = heap[--size];
        heapifyDown(heap, size, 0);

        long long z = x * 2 + y;

        heap[size] = z;
        heapifyUp(heap, size);
        size++;

        ans++;
    }

    free(heap);
    return ans;
}