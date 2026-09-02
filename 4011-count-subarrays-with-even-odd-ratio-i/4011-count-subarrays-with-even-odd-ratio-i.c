#include <stdlib.h>

typedef struct {
    int* tree;
    int n;
} Fenwick;

void add(Fenwick* f, int i) {
    for (i++; i <= f->n; i += i & -i)
        f->tree[i]++;
}

int query(Fenwick* f, int i) {
    int res = 0;

    for (i++; i > 0; i -= i & -i)
        res += f->tree[i];

    return res;
}

int cmp(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;

    return (x > y) - (x < y);
}

int lowerBound(int* arr, int n, int x) {
    int l = 0, r = n;

    while (l < r) {
        int m = l + (r - l) / 2;

        if (arr[m] < x)
            l = m + 1;
        else
            r = m;
    }

    return l;
}

long long countRatioSubarrays(int* nums, int numsSize, int a, int b) {
    int* prefix = malloc(sizeof(int) * (numsSize + 1));
    int* sorted = malloc(sizeof(int) * (numsSize + 1));

    prefix[0] = 0;

    for (int i = 0; i < numsSize; i++) {
        int weight = nums[i] % 2 == 0 ? b : -a;
        prefix[i + 1] = prefix[i] + weight;
    }

    for (int i = 0; i <= numsSize; i++)
        sorted[i] = prefix[i];

    qsort(sorted, numsSize + 1, sizeof(int), cmp);

    int m = 0;

    for (int i = 0; i <= numsSize; i++) {
        if (i == 0 || sorted[i] != sorted[i - 1])
            sorted[m++] = sorted[i];
    }

    Fenwick f;
    f.n = m;
    f.tree = calloc(m + 1, sizeof(int));

    long long answer = 0;
    int seen = 0;

    for (int i = 0; i <= numsSize; i++) {
        int rank = lowerBound(sorted, m, prefix[i]);
        answer += seen - query(&f, rank - 1);
        add(&f, rank);
        seen++;
    }

    free(prefix);
    free(sorted);
    free(f.tree);

    return answer;
}