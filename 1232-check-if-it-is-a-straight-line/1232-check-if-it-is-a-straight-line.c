#include <stdbool.h>

bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize) {
    int x0 = coordinates[0][0];
    int y0 = coordinates[0][1];
    int x1 = coordinates[1][0];
    int y1 = coordinates[1][1];

    int dx = x1 - x0;
    int dy = y1 - y0;

    for (int i = 2; i < coordinatesSize; i++) {
        int x = coordinates[i][0];
        int y = coordinates[i][1];

        if ((long long)(x - x0) * dy != (long long)(y - y0) * dx)
            return false;
    }

    return true;
}