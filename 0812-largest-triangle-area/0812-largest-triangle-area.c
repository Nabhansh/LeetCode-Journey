double area(int* a, int* b, int* c) {
    return fabs(
        (double)a[0] * (b[1] - c[1]) +
        (double)b[0] * (c[1] - a[1]) +
        (double)c[0] * (a[1] - b[1])
    ) / 2.0;
}

double largestTriangleArea(int** points, int pointsSize, int* pointsColSize) {
    double ans = 0.0;

    for (int i = 0; i < pointsSize; i++) {
        for (int j = i + 1; j < pointsSize; j++) {
            for (int k = j + 1; k < pointsSize; k++) {
                double cur = area(points[i], points[j], points[k]);
                if (cur > ans)
                    ans = cur;
            }
        }
    }

    return ans;
}