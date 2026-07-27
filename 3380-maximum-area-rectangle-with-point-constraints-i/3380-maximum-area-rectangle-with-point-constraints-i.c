int max(int a, int b) {
    return a > b ? a : b;
}

bool check(int** points, int pointsSize, int x1, int y1, int x2, int y2) {
    int cnt = 0;

    for (int i = 0; i < pointsSize; i++) {
        int x = points[i][0];
        int y = points[i][1];

        if (x < x1 || x > x2 || y < y1 || y > y2)
            continue;

        if ((x == x1 || x == x2) && (y == y1 || y == y2)) {
            cnt++;
            continue;
        }

        return false;
    }

    return cnt == 4;
}

int maxRectangleArea(int** points, int pointsSize, int* pointsColSize) {
    int ans = -1;

    for (int i = 0; i < pointsSize; i++) {
        int x1 = points[i][0];
        int y1 = points[i][1];

        for (int j = 0; j < i; j++) {
            int x2 = points[j][0];
            int y2 = points[j][1];

            int left = x1 < x2 ? x1 : x2;
            int right = x1 > x2 ? x1 : x2;
            int bottom = y1 < y2 ? y1 : y2;
            int top = y1 > y2 ? y1 : y2;

            if (left == right || bottom == top)
                continue;

            if (check(points, pointsSize, left, bottom, right, top)) {
                int area = (right - left) * (top - bottom);
                ans = max(ans, area);
            }
        }
    }

    return ans;
}