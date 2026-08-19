#include <stdlib.h>

typedef struct {
    int diff;
} Item;

int cmp(const void *a, const void *b) {
    Item *x = (Item *)a;
    Item *y = (Item *)b;
    return y->diff - x->diff;
}

long long maxPoints(int* technique1, int technique1Size, int* technique2, int technique2Size, int k) {
    int n = technique1Size;
    Item *a = (Item *)malloc(n * sizeof(Item));
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        ans += technique2[i];
        a[i].diff = technique1[i] - technique2[i];
    }

    qsort(a, n, sizeof(Item), cmp);

    for (int i = 0; i < n; i++) {
        if (i < k || a[i].diff > 0)
            ans += a[i].diff;
    }

    free(a);
    return ans;
}