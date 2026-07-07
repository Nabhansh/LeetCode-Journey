int minimumOperationsToWriteY(int** grid, int gridSize, int* gridColSize) {
    int inY[3] = {0}, outY[3] = {0};
    int mid = gridSize / 2;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            int isY = 0;

            if (i <= mid) {
                if (j == i || j == gridSize - 1 - i)
                    isY = 1;
            }
            if (i >= mid && j == mid)
                isY = 1;

            if (isY)
                inY[grid[i][j]]++;
            else
                outY[grid[i][j]]++;
        }
    }

    int totalY = inY[0] + inY[1] + inY[2];
    int totalOut = outY[0] + outY[1] + outY[2];

    int ans = 1e9;

    for (int yColor = 0; yColor < 3; yColor++) {
        for (int outColor = 0; outColor < 3; outColor++) {
            if (yColor == outColor)
                continue;

            int ops = (totalY - inY[yColor]) +
                      (totalOut - outY[outColor]);

            if (ops < ans)
                ans = ops;
        }
    }

    return ans;
}