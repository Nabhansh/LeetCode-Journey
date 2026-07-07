#include <stdlib.h>

typedef long long ll;

typedef struct {
    ll freq;
    int id;
} Node;

void swap(Node *a, Node *b) {
    Node t = *a;
    *a = *b;
    *b = t;
}

void push(Node *heap, int *sz, ll freq, int id) {
    int i = ++(*sz);
    heap[i].freq = freq;
    heap[i].id = id;

    while (i > 1 && heap[i].freq > heap[i / 2].freq) {
        swap(&heap[i], &heap[i / 2]);
        i /= 2;
    }
}

void pop(Node *heap, int *sz) {
    heap[1] = heap[(*sz)--];

    int i = 1;
    while (1) {
        int l = i * 2;
        int r = l + 1;
        int largest = i;

        if (l <= *sz && heap[l].freq > heap[largest].freq)
            largest = l;
        if (r <= *sz && heap[r].freq > heap[largest].freq)
            largest = r;

        if (largest == i)
            break;

        swap(&heap[i], &heap[largest]);
        i = largest;
    }
}

long long* mostFrequentIDs(int* nums, int numsSize, int* freq, int freqSize, int* returnSize) {
    *returnSize = numsSize;

    ll *cnt = calloc(100001, sizeof(ll));

    Node *heap = malloc(sizeof(Node) * (numsSize + 5));
    int heapSize = 0;

    ll *ans = malloc(sizeof(ll) * numsSize);

    for (int i = 0; i < numsSize; i++) {
        int id = nums[i];

        cnt[id] += (ll)freq[i];

        push(heap, &heapSize, cnt[id], id);

        while (heapSize > 0 && heap[1].freq != cnt[heap[1].id])
            pop(heap, &heapSize);

        ans[i] = (heapSize == 0) ? 0 : heap[1].freq;
    }

    free(cnt);
    free(heap);

    return ans;
}