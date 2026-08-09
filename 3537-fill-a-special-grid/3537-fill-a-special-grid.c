void fill(int n, long long start, int** grid, int rowOff, int colOff) {
    int size = 1 << n;
    if (n == 0) {
        grid[rowOff][colOff] = (int)start;
        return;
    }
    int half = size / 2;
    long long q = (long long)half * half; // numbers per quadrant

    fill(n - 1, start,         grid, rowOff,        colOff + half); // TR
    fill(n - 1, start + q,     grid, rowOff + half,  colOff + half); // BR
    fill(n - 1, start + 2 * q, grid, rowOff + half,  colOff);        // BL
    fill(n - 1, start + 3 * q, grid, rowOff,         colOff);        // TL
}

int** specialGrid(int n, int* gridSize, int** gridColSize) {
    int size = 1 << n;
    *gridSize = size;
    *gridColSize = (int*)malloc(size * sizeof(int));
    int** grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        grid[i] = (int*)malloc(size * sizeof(int));
        (*gridColSize)[i] = size;
    }

    fill(n, 0, grid, 0, 0);

    return grid;
}