int countLocalMaximums(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;
    int m = matrixColSize[0];

    static int ps[201][202][202];

    for (int v = 0; v <= 200; v++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                ps[v][i][j] =
                    ps[v][i - 1][j] +
                    ps[v][i][j - 1] -
                    ps[v][i - 1][j - 1] +
                    (matrix[i - 1][j - 1] > v);
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int v = matrix[i][j];

            if (v == 0)
                continue;

            int r1 = i - v;
            int r2 = i + v;
            int c1 = j - v;
            int c2 = j + v;

            if (r1 < 0) r1 = 0;
            if (r2 >= n) r2 = n - 1;
            if (c1 < 0) c1 = 0;
            if (c2 >= m) c2 = m - 1;

            int cnt =
                ps[v][r2 + 1][c2 + 1] -
                ps[v][r1][c2 + 1] -
                ps[v][r2 + 1][c1] +
                ps[v][r1][c1];

            if (i - v >= 0 && j - v >= 0 &&
                matrix[i - v][j - v] > v)
                cnt--;

            if (i - v >= 0 && j + v < m &&
                matrix[i - v][j + v] > v)
                cnt--;

            if (i + v < n && j - v >= 0 &&
                matrix[i + v][j - v] > v)
                cnt--;

            if (i + v < n && j + v < m &&
                matrix[i + v][j + v] > v)
                cnt--;

            if (cnt == 0)
                ans++;
        }
    }

    return ans;
}