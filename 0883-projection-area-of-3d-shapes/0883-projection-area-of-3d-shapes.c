int projectionArea(int** grid, int gridSize, int* gridColSize) {
    int ans = 0;
    int n = gridSize;

    for (int i = 0; i < n; i++) {
        int rowMax = 0;
        int colMax = 0;

        for (int j = 0; j < n; j++) {
            if (grid[i][j] > 0)
                ans++;

            if (grid[i][j] > rowMax)
                rowMax = grid[i][j];

            if (grid[j][i] > colMax)
                colMax = grid[j][i];
        }

        ans += rowMax + colMax;
    }

    return ans;
}