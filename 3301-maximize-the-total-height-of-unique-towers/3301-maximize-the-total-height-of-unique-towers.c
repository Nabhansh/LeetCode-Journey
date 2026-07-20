#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    if (x < y) return 1;
    if (x > y) return -1;
    return 0;
}

long long maximumTotalSum(int* maximumHeight, int maximumHeightSize) {
    qsort(maximumHeight, maximumHeightSize, sizeof(int), cmp);

    long long ans = 0;
    int prev = 1 << 30;      // 1073741824 (> 1e9)

    for (int i = 0; i < maximumHeightSize; i++) {
        int cur = maximumHeight[i];
        if (cur > prev - 1)
            cur = prev - 1;

        if (cur <= 0)
            return -1;

        ans += (long long)cur;
        prev = cur;
    }

    return ans;
}