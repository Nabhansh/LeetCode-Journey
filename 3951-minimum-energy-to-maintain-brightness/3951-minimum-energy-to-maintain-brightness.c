#include <stdlib.h>

int compareIntervals(const void* a, const void* b) {
    int** x = (int**)a;
    int** y = (int**)b;

    return x[0][0] - y[0][0];
}

long long minEnergy(
    int n,
    int brightness,
    int** intervals,
    int intervalsSize,
    int* intervalsColSize
) {
    qsort(
        intervals,
        intervalsSize,
        sizeof(int*),
        compareIntervals
    );

    long long bulbs = (brightness + 2LL) / 3;
    long long answer = 0;

    long long start = intervals[0][0];
    long long end = intervals[0][1];

    for (int i = 1; i < intervalsSize; i++) {
        long long nextStart = intervals[i][0];
        long long nextEnd = intervals[i][1];

        if (nextStart <= end) {
            if (nextEnd > end)
                end = nextEnd;
        } else {
            long long length = end - start + 1;
            answer += length * bulbs;

            start = nextStart;
            end = nextEnd;
        }
    }

    answer += (end - start + 1) * bulbs;

    return answer;
}