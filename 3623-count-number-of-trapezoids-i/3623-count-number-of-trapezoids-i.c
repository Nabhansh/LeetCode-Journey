#include <stdlib.h>

#define MOD 1000000007LL

static int compareInts(const void *p1, const void *p2) {
    int a = *(const int *)p1;
    int b = *(const int *)p2;

    return (a > b) - (a < b);
}

int countTrapezoids(int **points, int pointsSize,
                    int *pointsColSize) {
    (void)pointsColSize;

    int *yValues = malloc(pointsSize * sizeof(int));

    for (int i = 0; i < pointsSize; ++i)
        yValues[i] = points[i][1];

    qsort(yValues, pointsSize, sizeof(int), compareInts);

    long long previousSides = 0;
    long long answer = 0;

    int i = 0;

    while (i < pointsSize) {
        int j = i;

        while (j < pointsSize && yValues[j] == yValues[i])
            ++j;

        long long count = j - i;
        long long currentSides =
            count * (count - 1) / 2 % MOD;

        answer = (answer +
                  previousSides * currentSides) % MOD;

        previousSides =
            (previousSides + currentSides) % MOD;

        i = j;
    }

    free(yValues);
    return (int)answer;
}