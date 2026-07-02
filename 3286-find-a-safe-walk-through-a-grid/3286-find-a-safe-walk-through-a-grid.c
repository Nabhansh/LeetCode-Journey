static int*** global_his = NULL;
static inline bool dfs(int i, int j, int** grid, int row, int col, int health,
         int** visited) {
    if ( global_his[i][j][health]|| visited[i][j] || health <= 0) {
        return false;
    }
    health -= grid[i][j];

    if (i == row && j == col) {
        if (health >= 1) {
            return true;
        }
    }

    if (health >= 1) {
        visited[i][j] = 1;
    } else {
        visited[i][j] = 0;
        return false;
    }

    // down
    bool ret = false;
    if (i + 1 <= row) {
        ret = dfs(i + 1, j, grid, row, col, health, visited);
        if (ret == false) {
            global_his[i + 1][j][health] = 1;
        }
    }
    // right
    if (ret == false && j + 1 <= col) {
        ret = dfs(i, j + 1, grid, row, col, health, visited);
        if (ret == false) {
            global_his[i][j + 1][health] = 1;
        }
    }
    // up
    if (ret == false && i - 1 >= 0) {
        ret = dfs(i - 1, j, grid, row, col, health, visited);
        if (ret == false) {
            global_his[i - 1][j][health] = 1;
        }
    }
    // left
    if (ret == false && j - 1 >= 0) {
        ret = dfs(i, j - 1, grid, row, col, health, visited);
        if (ret == false) {
            global_his[i][j - 1][health] = 1;
        }
    }
    // right
    if (ret == false) {
        visited[i][j] = 0;
        global_his[i][j][health] = 1;
    }
    return ret;
}

bool findSafeWalk(int** grid, int gridSize, int* gridColSize, int health) {
    int** visited = (int**)calloc(gridSize, sizeof(int*));
    for (int i = 0; i < gridSize; i++) {
        visited[i] = calloc(*gridColSize, sizeof(int));
    }
    global_his = (int***)calloc(gridSize, sizeof(int**));
    for (int i = 0; i < gridSize; i++) {
        global_his[i] = (int**)calloc((*gridColSize), sizeof(int*));
        for (int j = 0; j < *gridColSize; j++) {
            global_his[i][j] = calloc(health + 1, sizeof(int));
        }
    }

    bool ret = dfs(0, 0, grid, gridSize - 1, *gridColSize - 1, health, visited);

    for (int i = 0; i < gridSize; i++) {
        free(visited[i]);
    }
    free(visited);

    for (int i = 0; i < gridSize; i++) {

        for (int j = 0; j < *gridColSize; j++) {
            free(global_his[i][j]);
        }
        free(global_his[i]);
    }
    free(global_his);
    return ret;
}