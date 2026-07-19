int minFlips(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    int ans = 0;

    // Groups of four symmetric cells
    for (int i = 0; i < m / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            int ones =
                grid[i][j] +
                grid[i][n - 1 - j] +
                grid[m - 1 - i][j] +
                grid[m - 1 - i][n - 1 - j];

            ans += (ones < 4 - ones) ? ones : (4 - ones);
        }
    }

    int diff = 0, onePair = 0;

    // Middle row
    if (m & 1) {
        int r = m / 2;
        for (int j = 0; j < n / 2; j++) {
            int a = grid[r][j];
            int b = grid[r][n - 1 - j];
            if (a != b)
                diff++;
            else if (a == 1)
                onePair += 2;
        }
    }

    // Middle column
    if (n & 1) {
        int c = n / 2;
        for (int i = 0; i < m / 2; i++) {
            int a = grid[i][c];
            int b = grid[m - 1 - i][c];
            if (a != b)
                diff++;
            else if (a == 1)
                onePair += 2;
        }
    }

    if (diff > 0)
        ans += diff;
    else
        ans += (onePair % 4 == 0) ? 0 : 2;

    // Center cell
    if ((m & 1) && (n & 1))
        ans += grid[m / 2][n / 2];

    return ans;
}