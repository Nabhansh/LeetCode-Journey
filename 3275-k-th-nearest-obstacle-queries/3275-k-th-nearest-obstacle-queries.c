typedef struct {
    int *a;
    int size;
} Heap;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void push(Heap *h, int x) {
    int i = h->size++;
    h->a[i] = x;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->a[p] >= h->a[i]) break;
        swap(&h->a[p], &h->a[i]);
        i = p;
    }
}

void pop(Heap *h) {
    h->a[0] = h->a[--h->size];
    int i = 0;
    while (1) {
        int l = 2 * i + 1, r = 2 * i + 2, mx = i;
        if (l < h->size && h->a[l] > h->a[mx]) mx = l;
        if (r < h->size && h->a[r] > h->a[mx]) mx = r;
        if (mx == i) break;
        swap(&h->a[i], &h->a[mx]);
        i = mx;
    }
}

/**
 * Note: The returned array must be malloced.
 */
int* resultsArray(int** queries, int queriesSize, int* queriesColSize,
                  int k, int* returnSize) {
    *returnSize = queriesSize;
    int *ans = malloc(sizeof(int) * queriesSize);

    Heap h;
    h.a = malloc(sizeof(int) * (queriesSize + 1));
    h.size = 0;

    for (int i = 0; i < queriesSize; i++) {
        int d = abs(queries[i][0]) + abs(queries[i][1]);
        push(&h, d);

        if (h.size > k)
            pop(&h);

        ans[i] = (h.size < k) ? -1 : h.a[0];
    }

    free(h.a);
    return ans;
}