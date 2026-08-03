#include <stdlib.h>

#define MOD 1000000007LL

static int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int minMaxSums(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), cmp);

    long long **C = (long long **)malloc((numsSize + 1) * sizeof(long long *));
    for (int i = 0; i <= numsSize; i++) {
        C[i] = (long long *)calloc(k + 1, sizeof(long long));
    }

    C[0][0] = 1;
    for (int i = 1; i <= numsSize; i++) {
        C[i][0] = 1;
        int lim = (i < k ? i : k);
        for (int j = 1; j <= lim; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }

    long long ans = 0;

    for (int i = 0; i < numsSize; i++) {
        long long waysMax = 0;
        long long waysMin = 0;

        int left = i;
        int right = numsSize - i - 1;

        int limLeft = (left < k - 1 ? left : k - 1);
        int limRight = (right < k - 1 ? right : k - 1);

        for (int j = 0; j <= limLeft; j++)
            waysMax = (waysMax + C[left][j]) % MOD;

        for (int j = 0; j <= limRight; j++)
            waysMin = (waysMin + C[right][j]) % MOD;

        ans = (ans + (long long)nums[i] * waysMax) % MOD;
        ans = (ans + (long long)nums[i] * waysMin) % MOD;
    }

    for (int i = 0; i <= numsSize; i++)
        free(C[i]);
    free(C);

    return (int)(ans % MOD);
}