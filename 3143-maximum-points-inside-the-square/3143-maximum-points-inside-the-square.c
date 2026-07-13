#include <stdlib.h>
#include <limits.h>

typedef struct {
    int dist;
    char label;
} Point;

int comparePoints(const void* a, const void* b) {
    Point* p1 = (Point*)a;
    Point* p2 = (Point*)b;

    if (p1->dist < p2->dist) return -1;
    if (p1->dist > p2->dist) return 1;
    return 0;
}

int maxPointsInsideSquare(int** points, int pointsSize, int* pointsColSize, char* s) {
    Point* arr = (Point*)malloc(pointsSize * sizeof(Point));

    for (int i = 0; i < pointsSize; i++) {
        int x = abs(points[i][0]);
        int y = abs(points[i][1]);

        arr[i].dist = x > y ? x : y;
        arr[i].label = s[i];
    }

    qsort(arr, pointsSize, sizeof(Point), comparePoints);

    int used[26] = {0};
    int answer = 0;
    int i = 0;

    while (i < pointsSize) {
        int j = i;
        int valid = 1;
        int current[26] = {0};

        while (j < pointsSize && arr[j].dist == arr[i].dist) {
            int c = arr[j].label - 'a';

            if (used[c] || current[c]) {
                valid = 0;
            }

            current[c] = 1;
            j++;
        }

        if (!valid) {
            break;
        }

        for (int k = i; k < j; k++) {
            used[arr[k].label - 'a'] = 1;
            answer++;
        }

        i = j;
    }

    free(arr);
    return answer;
}