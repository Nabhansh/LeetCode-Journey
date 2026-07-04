#include <stdlib.h>

int* countOfPairs(int n, int x, int y, int* returnSize) {
    int *ans = (int *)calloc(n, sizeof(int));

    x--;
    y--;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int d = abs(i - j);

            int t1 = abs(i - x) + 1 + abs(y - j);
            int t2 = abs(i - y) + 1 + abs(x - j);

            if (t1 < d) d = t1;
            if (t2 < d) d = t2;

            ans[d - 1] += 2;
        }
    }

    *returnSize = n;
    return ans;
}