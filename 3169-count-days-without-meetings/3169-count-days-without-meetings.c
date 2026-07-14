#include <stdlib.h>

int compare(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;

    if (x[0] < y[0]) return -1;
    if (x[0] > y[0]) return 1;
    return 0;
}

int countDays(int days, int** meetings, int meetingsSize,
              int* meetingsColSize) {

    qsort(meetings, meetingsSize, sizeof(int*), compare);

    int busyDays = 0;

    int start = meetings[0][0];
    int end = meetings[0][1];

    for (int i = 1; i < meetingsSize; i++) {

        int nextStart = meetings[i][0];
        int nextEnd = meetings[i][1];

        if (nextStart <= end) {
            if (nextEnd > end) {
                end = nextEnd;
            }
        } else {
            busyDays += end - start + 1;

            start = nextStart;
            end = nextEnd;
        }
    }

    busyDays += end - start + 1;

    return days - busyDays;
}