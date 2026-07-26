#include <stdbool.h>

bool hasZero(int x) {
    while (x) {
        if (x % 10 == 0)
            return true;
        x /= 10;
    }
    return false;
}

int* getNoZeroIntegers(int n, int* returnSize) {

    *returnSize = 2;

    int *ans = (int *)malloc(2 * sizeof(int));

    for (int a = 1; a < n; a++) {
        int b = n - a;

        if (!hasZero(a) && !hasZero(b)) {
            ans[0] = a;
            ans[1] = b;
            return ans;
        }
    }

    return ans;
}