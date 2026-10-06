class Solution {
public:
    bool solve(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.')
                    continue;

                for (char x = '1'; x <= '9'; x++) {
                    bool valid = true;

                    for (int i = 0; i < 9; i++) {
                        if (board[r][i] == x || board[i][c] == x) {
                            valid = false;
                            break;
                        }
                    }

                    int sr = (r / 3) * 3;
                    int sc = (c / 3) * 3;

                    for (int i = sr; i < sr + 3 && valid; i++) {
                        for (int j = sc; j < sc + 3; j++) {
                            if (board[i][j] == x) {
                                valid = false;
                                break;
                            }
                        }
                    }

                    if (valid) {
                        board[r][c] = x;

                        if (solve(board))
                            return true;

                        board[r][c] = '.';
                    }
                }

                return false;
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};