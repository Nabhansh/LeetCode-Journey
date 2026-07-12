#include <limits.h>

int minimumOperations(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];

    int prev[10] = {0};
    int curr[10];

    for (int digit = 0; digit < 10; digit++) {
        int count = 0;

        for (int row = 0; row < rows; row++) {
            if (grid[row][0] != digit) {
                count++;
            }
        }

        prev[digit] = count;
    }

    for (int col = 1; col < cols; col++) {
        for (int digit = 0; digit < 10; digit++) {
            int changeCost = 0;

            for (int row = 0; row < rows; row++) {
                if (grid[row][col] != digit) {
                    changeCost++;
                }
            }

            int bestPrevious = INT_MAX;

            for (int previousDigit = 0; previousDigit < 10;
                 previousDigit++) {

                if (previousDigit != digit &&
                    prev[previousDigit] < bestPrevious) {
                    bestPrevious = prev[previousDigit];
                }
            }

            curr[digit] = bestPrevious + changeCost;
        }

        for (int digit = 0; digit < 10; digit++) {
            prev[digit] = curr[digit];
        }
    }

    int answer = prev[0];

    for (int digit = 1; digit < 10; digit++) {
        if (prev[digit] < answer) {
            answer = prev[digit];
        }
    }

    return answer;
}