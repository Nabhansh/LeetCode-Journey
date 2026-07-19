#include <stdlib.h>

void heapify(int *heap, int n, int i) {
    while (1) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && heap[l] > heap[largest]) largest = l;
        if (r < n && heap[r] > heap[largest]) largest = r;

        if (largest == i) break;

        int t = heap[i];
        heap[i] = heap[largest];
        heap[largest] = t;
        i = largest;
    }
}

void push(int *heap, int *size, int val) {
    int i = (*size)++;
    heap[i] = val;

    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] >= heap[i]) break;

        int t = heap[p];
        heap[p] = heap[i];
        heap[i] = t;
        i = p;
    }
}

int pop(int *heap, int *size) {
    int ret = heap[0];
    heap[0] = heap[--(*size)];
    heapify(heap, *size, 0);
    return ret;
}

int lastStoneWeight(int* stones, int stonesSize) {
    for (int i = stonesSize / 2 - 1; i >= 0; i--)
        heapify(stones, stonesSize, i);

    int size = stonesSize;

    while (size > 1) {
        int x = pop(stones, &size);
        int y = pop(stones, &size);

        if (x != y)
            push(stones, &size, x - y);
    }

    return size ? stones[0] : 0;
}