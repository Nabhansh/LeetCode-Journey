#include <stdio.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int surfaceArea(int** grid, int gridSize, int* gridColSize) {
    int totalArea = 0;
    
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            int v = grid[i][j];
            
            if (v > 0) {
                totalArea += (2 + 4 * v);

                if (i > 0) {
                    totalArea -= 2 * min(v, grid[i - 1][j]);
                }
                
                if (j > 0) {
                    totalArea -= 2 * min(v, grid[i][j - 1]);
                }
            }
        }
    }
    
    return totalArea;
}