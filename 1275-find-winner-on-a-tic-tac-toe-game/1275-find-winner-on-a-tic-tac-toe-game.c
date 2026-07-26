#include <string.h>

char* tictactoe(int** moves, int movesSize, int* movesColSize) {
    char board[3][3];
    memset(board, ' ', sizeof(board));

    for (int i = 0; i < movesSize; i++) {
        int r = moves[i][0];
        int c = moves[i][1];
        board[r][c] = (i % 2 == 0) ? 'A' : 'B';
    }

    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return board[i][0] == 'A' ? "A" : "B";

        if (board[0][i] != ' ' &&
            board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return board[0][i] == 'A' ? "A" : "B";
    }

    if (board[0][0] != ' ' &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return board[0][0] == 'A' ? "A" : "B";

    if (board[0][2] != ' ' &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return board[0][2] == 'A' ? "A" : "B";

    return movesSize == 9 ? "Draw" : "Pending";
}