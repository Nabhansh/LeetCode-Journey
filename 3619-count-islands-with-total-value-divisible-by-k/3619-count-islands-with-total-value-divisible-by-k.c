#include <stdlib.h>

int countIslands(int **grid, int gridSize,
                 int *gridColSize, int k) {
    int rows = gridSize;
    int cols = gridColSize[0];
    int totalCells = rows * cols;

    int *stack = malloc(totalCells * sizeof(int));
    int answer = 0;

    static const int dr[4] = {-1, 1, 0, 0};
    static const int dc[4] = {0, 0, -1, 1};

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (grid[r][c] == 0)
                continue;

            int top = 0;
            int sumModuloK = grid[r][c] % k;

            stack[top++] = r * cols + c;
            grid[r][c] = 0;

            while (top > 0) {
                int position = stack[--top];
                int currentRow = position / cols;
                int currentCol = position % cols;

                for (int d = 0; d < 4; ++d) {
                    int nr = currentRow + dr[d];
                    int nc = currentCol + dc[d];

                    if (nr < 0 || nr >= rows ||
                        nc < 0 || nc >= cols ||
                        grid[nr][nc] == 0) {
                        continue;
                    }

                    sumModuloK =
                        (sumModuloK + grid[nr][nc]) % k;

                    grid[nr][nc] = 0;
                    stack[top++] = nr * cols + nc;
                }
            }

            if (sumModuloK == 0)
                ++answer;
        }
    }

    free(stack);
    return answer;
}