#include <stdlib.h>

int compare(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;

    return (x > y) - (x < y);
}

int minRectanglesToCoverPoints(int** points, int pointsSize,
                               int* pointsColSize, int w) {
    int* x = (int*)malloc(pointsSize * sizeof(int));

    for (int i = 0; i < pointsSize; i++) {
        x[i] = points[i][0];
    }

    qsort(x, pointsSize, sizeof(int), compare);

    int answer = 0;
    int i = 0;

    while (i < pointsSize) {
        int start = x[i];
        answer++;
        i++;

        while (i < pointsSize && x[i] <= start + w) {
            i++;
        }
    }

    free(x);

    return answer;
}