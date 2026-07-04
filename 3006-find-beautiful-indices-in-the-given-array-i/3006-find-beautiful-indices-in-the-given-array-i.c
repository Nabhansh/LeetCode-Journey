#include <stdlib.h>
#include <string.h>

int* beautifulIndices(char* s, char* a, char* b, int k, int* returnSize) {
    int n = strlen(s), la = strlen(a), lb = strlen(b);

    int *pa = malloc(n * sizeof(int));
    int *pb = malloc(n * sizeof(int));
    int ca = 0, cb = 0;

    for (int i = 0; i + la <= n; i++)
        if (strncmp(s + i, a, la) == 0)
            pa[ca++] = i;

    for (int i = 0; i + lb <= n; i++)
        if (strncmp(s + i, b, lb) == 0)
            pb[cb++] = i;

    int *ans = malloc(ca * sizeof(int));
    int sz = 0;
    int j = 0;

    for (int i = 0; i < ca; i++) {
        while (j < cb && pb[j] < pa[i] - k)
            j++;

        if ((j < cb && abs(pb[j] - pa[i]) <= k) ||
            (j > 0 && abs(pb[j - 1] - pa[i]) <= k))
            ans[sz++] = pa[i];
    }

    free(pa);
    free(pb);

    *returnSize = sz;
    return ans;
}