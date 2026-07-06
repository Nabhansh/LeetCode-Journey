#include <stdio.h>
#include <stdlib.h>

// Comparator for sorting
int cmp(const void *a, const void *b) {
    int *i1 = *(int **)a;
    int *i2 = *(int **)b;

    if (i1[0] == i2[0])
        return i2[1] - i1[1];  // end descending
    return i1[0] - i2[0];      // start ascending
}

int removeCoveredIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    // Step 1: Sort intervals
    qsort(intervals, intervalsSize, sizeof(int*), cmp);

    int count = 0;
    int max_end = 0;

    // Step 2: Traverse
    for (int i = 0; i < intervalsSize; i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];

        if (end > max_end) {
            count++;
            max_end = end;
        }
        // else: covered, ignore
    }

    return count;
}