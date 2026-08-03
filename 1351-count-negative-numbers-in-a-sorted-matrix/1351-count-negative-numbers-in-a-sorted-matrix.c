int countNegatives(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];

    int row = m - 1;
    int col = 0;
    int ans = 0;

    while (row >= 0 && col < n) {
        if (grid[row][col] < 0) {
            ans += n - col;
            row--;
        } else {
            col++;
        }
    }

    return ans;
}