#include <stdlib.h>

static int max(int a, int b) {
    return a > b ? a : b;
}

int maxFreeTime(int eventTime,
                int* startTime, int startTimeSize,
                int* endTime, int endTimeSize) {
    int n = startTimeSize;

    int *gap = (int *)malloc((n + 1) * sizeof(int));

    gap[0] = startTime[0];
    for (int i = 1; i < n; i++)
        gap[i] = startTime[i] - endTime[i - 1];
    gap[n] = eventTime - endTime[n - 1];

    int *pre = (int *)malloc((n + 1) * sizeof(int));
    int *suf = (int *)malloc((n + 1) * sizeof(int));

    pre[0] = gap[0];
    for (int i = 1; i <= n; i++)
        pre[i] = max(pre[i - 1], gap[i]);

    suf[n] = gap[n];
    for (int i = n - 1; i >= 0; i--)
        suf[i] = max(suf[i + 1], gap[i]);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int len = endTime[i] - startTime[i];

        int leftGap = gap[i];
        int rightGap = gap[i + 1];

        /* Move meeting elsewhere if another gap can hold it */
        if ((i > 0 && pre[i - 1] >= len) ||
            (i + 2 <= n && suf[i + 2] >= len)) {
            ans = max(ans, leftGap + len + rightGap);
        }

        /* Otherwise move it within adjacent free space */
        ans = max(ans, leftGap + rightGap);
    }

    free(gap);
    free(pre);
    free(suf);

    return ans;
}