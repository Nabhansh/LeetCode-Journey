int cmp(const void *a, const void *b) {
    int *p = *(int **)a;
    int *q = *(int **)b;

    if (p[0] != q[0])
        return p[0] - q[0];
    return q[1] - p[1];
}

int numberOfPairs(int** points, int pointsSize, int* pointsColSize) {
    qsort(points, pointsSize, sizeof(int *), cmp);

    int ans = 0;

    for (int i = 0; i < pointsSize; i++) {
        int maxY = -1;

        for (int j = i + 1; j < pointsSize; j++) {
            if (points[j][1] <= points[i][1] && points[j][1] > maxY) {
                ans++;
                maxY = points[j][1];
            }
        }
    }

    return ans;
}