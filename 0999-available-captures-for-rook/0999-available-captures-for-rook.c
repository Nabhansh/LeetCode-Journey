int numRookCaptures(char** board, int boardSize, int* boardColSize) {
    int row = 0, col = 0;

    // Find the rook
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            if (board[i][j] == 'R') {
                row = i;
                col = j;
            }
        }
    }

    int directions[4][2] = {
        {-1, 0},  // Up
        {1, 0},   // Down
        {0, -1},  // Left
        {0, 1}    // Right
    };

    int captures = 0;

    for (int d = 0; d < 4; d++) {
        int r = row + directions[d][0];
        int c = col + directions[d][1];

        while (r >= 0 && r < boardSize &&
               c >= 0 && c < boardColSize[r]) {

            if (board[r][c] == 'B') {
                break;
            }

            if (board[r][c] == 'p') {
                captures++;
                break;
            }

            r += directions[d][0];
            c += directions[d][1];
        }
    }

    return captures;
}