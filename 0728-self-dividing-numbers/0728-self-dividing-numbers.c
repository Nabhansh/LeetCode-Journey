#include <stdlib.h>

int* selfDividingNumbers(int left, int right, int* returnSize) {
    int* ans = (int*)malloc((right - left + 1) * sizeof(int));
    *returnSize = 0;

    for (int num = left; num <= right; num++) {
        int temp = num;
        int ok = 1;

        while (temp > 0) {
            int digit = temp % 10;

            if (digit == 0 || num % digit != 0) {
                ok = 0;
                break;
            }

            temp /= 10;
        }

        if (ok)
            ans[(*returnSize)++] = num;
    }

    return ans;
}