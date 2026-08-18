#include <stdlib.h>

int* lexSmallestNegatedPerm(int n, long long target, int* returnSize)
{
    long long total = (long long)n * (n + 1) / 2;

    // Impossible target
    if (target < -total || target > total ||
        (total - target) % 2 != 0)
    {
        *returnSize = 0;
        return NULL;
    }

    long long need = (total - target) / 2;

    int* ans = (int*)malloc(n * sizeof(int));

    if (ans == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    int left = 0;
    int right = n - 1;

    // Process largest numbers first
    for (int x = n; x >= 1; x--)
    {
        if (need >= x)
        {
            // Make x negative
            ans[left++] = -x;
            need -= x;
        }
        else
        {
            // Keep x positive
            ans[right--] = x;
        }
    }

    *returnSize = n;

    return ans;
}