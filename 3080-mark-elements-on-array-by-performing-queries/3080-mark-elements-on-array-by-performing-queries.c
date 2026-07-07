#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Node;

int cmp(const void *a, const void *b) {
    Node *x = (Node *)a;
    Node *y = (Node *)b;

    if (x->val != y->val)
        return x->val - y->val;

    return x->idx - y->idx;
}

long long* unmarkedSumArray(int* nums, int numsSize,
                            int** queries, int queriesSize,
                            int* queriesColSize,
                            int* returnSize) {

    *returnSize = queriesSize;

    Node *a = malloc(numsSize * sizeof(Node));

    long long sum = 0;

    for (int i = 0; i < numsSize; i++) {
        a[i].val = nums[i];
        a[i].idx = i;
        sum += nums[i];
    }

    qsort(a, numsSize, sizeof(Node), cmp);

    int *marked = calloc(numsSize, sizeof(int));
    int p = 0;

    long long *ans = malloc(sizeof(long long) * queriesSize);

    for (int i = 0; i < queriesSize; i++) {

        int idx = queries[i][0];
        int k = queries[i][1];

        if (!marked[idx]) {
            marked[idx] = 1;
            sum -= nums[idx];
        }

        while (k && p < numsSize) {
            if (!marked[a[p].idx]) {
                marked[a[p].idx] = 1;
                sum -= a[p].val;
                k--;
            }
            p++;
        }

        ans[i] = sum;
    }

    free(a);
    free(marked);

    return ans;
}