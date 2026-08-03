#include <stdlib.h>

static int max(int a, int b) {
    return a > b ? a : b;
}

int maxFreeTime(int eventTime, int k,
                int* startTime, int startTimeSize,
                int* endTime, int endTimeSize) {
    int n = startTimeSize;

    // gaps[0] = before first meeting
    // gaps[n] = after last meeting
    int *gaps = (int *)malloc((n + 1) * sizeof(int));

    gaps[0] = startTime[0];

    for (int i = 1; i < n; i++)
        gaps[i] = startTime[i] - endTime[i - 1];

    gaps[n] = eventTime - endTime[n - 1];

    // Sliding window over k+1 consecutive gaps
    int window = 0;
    for (int i = 0; i <= k; i++)
        window += gaps[i];

    int ans = window;

    for (int i = k + 1; i <= n; i++) {
        window += gaps[i];
        window -= gaps[i - (k + 1)];
        ans = max(ans, window);
    }

    free(gaps);
    return ans;
}