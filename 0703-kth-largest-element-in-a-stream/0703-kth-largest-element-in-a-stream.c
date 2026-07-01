#include <stdlib.h>

typedef struct {
    int *heap;
    int size;
    int k;
} KthLargest;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(KthLargest *obj, int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (obj->heap[p] <= obj->heap[i])
            break;
        swap(&obj->heap[p], &obj->heap[i]);
        i = p;
    }
}

void heapifyDown(KthLargest *obj, int i) {
    while (1) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int s = i;

        if (l < obj->size && obj->heap[l] < obj->heap[s])
            s = l;
        if (r < obj->size && obj->heap[r] < obj->heap[s])
            s = r;

        if (s == i)
            break;

        swap(&obj->heap[s], &obj->heap[i]);
        i = s;
    }
}

int kthLargestAdd(KthLargest* obj, int val);

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest *obj = (KthLargest *)malloc(sizeof(KthLargest));
    obj->heap = (int *)malloc(sizeof(int) * (k + numsSize + 1));
    obj->size = 0;
    obj->k = k;

    for (int i = 0; i < numsSize; i++)
        kthLargestAdd(obj, nums[i]);

    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->size < obj->k) {
        obj->heap[obj->size] = val;
        heapifyUp(obj, obj->size);
        obj->size++;
    } else if (val > obj->heap[0]) {
        obj->heap[0] = val;
        heapifyDown(obj, 0);
    }

    return obj->heap[0];
}

void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}