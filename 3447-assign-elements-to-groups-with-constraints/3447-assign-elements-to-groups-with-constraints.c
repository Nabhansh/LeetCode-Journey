#include <stdlib.h>

int* assignElements(int* groups, int groupsSize,
                    int* elements, int elementsSize,
                    int* returnSize) {
    int maxValue = 0;

    for (int i = 0; i < groupsSize; i++)
        if (groups[i] > maxValue)
            maxValue = groups[i];

    int *first = (int *)malloc((maxValue + 1) * sizeof(int));

    for (int i = 0; i <= maxValue; i++)
        first[i] = -1;

    /* Store the first occurrence of each element value */
    for (int i = 0; i < elementsSize; i++) {
        int x = elements[i];
        if (x <= maxValue && first[x] == -1)
            first[x] = i;
    }

    int *ans = (int *)malloc(groupsSize * sizeof(int));

    for (int i = 0; i < groupsSize; i++) {
        int g = groups[i];
        int best = -1;

        for (int d = 1; (long long)d * d <= g; d++) {
            if (g % d != 0)
                continue;

            if (d <= maxValue && first[d] != -1) {
                if (best == -1 || first[d] < best)
                    best = first[d];
            }

            int other = g / d;
            if (other != d && other <= maxValue && first[other] != -1) {
                if (best == -1 || first[other] < best)
                    best = first[other];
            }
        }

        ans[i] = best;
    }

    free(first);

    *returnSize = groupsSize;
    return ans;
}