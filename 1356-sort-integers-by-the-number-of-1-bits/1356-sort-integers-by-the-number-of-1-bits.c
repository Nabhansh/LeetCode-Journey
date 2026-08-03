#include <stdlib.h>

typedef struct {
    int val;
    int bits;
} Node;

static int bitCount(int x) {
    int cnt = 0;
    while (x) {
        cnt += x & 1;
        x >>= 1;
    }
    return cnt;
}

static int cmp(const void *a, const void *b) {
    Node *x = (Node *)a;
    Node *y = (Node *)b;

    if (x->bits != y->bits)
        return x->bits - y->bits;

    return x->val - y->val;
}

int* sortByBits(int* arr, int arrSize, int* returnSize) {
    Node *v = (Node *)malloc(arrSize * sizeof(Node));

    for (int i = 0; i < arrSize; i++) {
        v[i].val = arr[i];
        v[i].bits = bitCount(arr[i]);
    }

    qsort(v, arrSize, sizeof(Node), cmp);

    int *ans = (int *)malloc(arrSize * sizeof(int));
    for (int i = 0; i < arrSize; i++)
        ans[i] = v[i].val;

    free(v);

    *returnSize = arrSize;
    return ans;
}