#include <stdlib.h>

typedef struct {
    int a;
    int b;
    int idx;
} Node;

int cmp(const void *x, const void *y)
{
    Node *p = (Node *)x;
    Node *q = (Node *)y;
    return p->a - q->a;
}

/* ---------- Min Heap ---------- */

void heapUp(int heap[], int idx)
{
    while (idx > 0)
    {
        int p = (idx - 1) / 2;

        if (heap[p] <= heap[idx])
            break;

        int t = heap[p];
        heap[p] = heap[idx];
        heap[idx] = t;

        idx = p;
    }
}

void heapDown(int heap[], int size, int idx)
{
    while (1)
    {
        int s = idx;
        int l = idx * 2 + 1;
        int r = idx * 2 + 2;

        if (l < size && heap[l] < heap[s])
            s = l;

        if (r < size && heap[r] < heap[s])
            s = r;

        if (s == idx)
            break;

        int t = heap[idx];
        heap[idx] = heap[s];
        heap[s] = t;

        idx = s;
    }
}

void push(int heap[], int *size, int val)
{
    heap[*size] = val;
    (*size)++;

    heapUp(heap, *size - 1);
}

int pop(int heap[], int *size)
{
    int ans = heap[0];

    heap[0] = heap[*size - 1];
    (*size)--;

    heapDown(heap, *size, 0);

    return ans;
}

/* ---------- Solution ---------- */

long long* findMaxSum(int* nums1, int nums1Size,
                      int* nums2, int nums2Size,
                      int k,
                      int* returnSize)
{
    *returnSize = nums1Size;

    Node *arr = malloc(sizeof(Node) * nums1Size);

    for (int i = 0; i < nums1Size; i++)
    {
        arr[i].a = nums1[i];
        arr[i].b = nums2[i];
        arr[i].idx = i;
    }

    qsort(arr, nums1Size, sizeof(Node), cmp);

    long long *ans = malloc(sizeof(long long) * nums1Size);

    int *heap = malloc(sizeof(int) * (k + 5));
    int heapSize = 0;

    long long sum = 0;

    int i = 0;

    while (i < nums1Size)
    {
        int j = i;

        while (j < nums1Size && arr[j].a == arr[i].a)
            j++;

        for (int t = i; t < j; t++)
            ans[arr[t].idx] = sum;

        for (int t = i; t < j; t++)
        {
            push(heap, &heapSize, arr[t].b);
            sum += arr[t].b;

            if (heapSize > k)
                sum -= pop(heap, &heapSize);
        }

        i = j;
    }

    free(arr);
    free(heap);

    return ans;
}