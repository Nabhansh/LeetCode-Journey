int minFlips(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];

    int rowFlips = 0, colFlips = 0;

    // Make every row a palindrome
    for (int i = 0; i < m; i++) {
        for (int l = 0, r = n - 1; l < r; l++, r--) {
            if (grid[i][l] != grid[i][r])
                rowFlips++;
        }
    }

    // Make every column a palindrome
    for (int j = 0; j < n; j++) {
        for (int t = 0, b = m - 1; t < b; t++, b--) {
            if (grid[t][j] != grid[b][j])
                colFlips++;
        }
    }

    return rowFlips < colFlips ? rowFlips : colFlips;
}