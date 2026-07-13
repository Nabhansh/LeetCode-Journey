#include <stdlib.h>
#include <limits.h>

int maxScore(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];

    int** minVal = (int**)malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++) {
        minVal[i] = (int*)malloc(cols * sizeof(int));
    }

    int answer = INT_MIN;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int previousMin = INT_MAX;

            if (i > 0 && minVal[i - 1][j] < previousMin) {
                previousMin = minVal[i - 1][j];
            }

            if (j > 0 && minVal[i][j - 1] < previousMin) {
                previousMin = minVal[i][j - 1];
            }

            if (previousMin != INT_MAX) {
                int score = grid[i][j] - previousMin;

                if (score > answer) {
                    answer = score;
                }
            }

            minVal[i][j] = grid[i][j];

            if (i > 0 && minVal[i - 1][j] < minVal[i][j]) {
                minVal[i][j] = minVal[i - 1][j];
            }

            if (j > 0 && minVal[i][j - 1] < minVal[i][j]) {
                minVal[i][j] = minVal[i][j - 1];
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        free(minVal[i]);
    }

    free(minVal);

    return answer;
}