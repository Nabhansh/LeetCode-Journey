long long numberOfRightTriangles(int** grid, int gridSize,
                                 int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];

    int rowCount[rows];
    int colCount[cols];

    for (int i = 0; i < rows; i++) {
        rowCount[i] = 0;
    }

    for (int j = 0; j < cols; j++) {
        colCount[j] = 0;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                rowCount[i]++;
                colCount[j]++;
            }
        }
    }

    long long answer = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                answer += (long long)(rowCount[i] - 1) *
                          (colCount[j] - 1);
            }
        }
    }

    return answer;
}