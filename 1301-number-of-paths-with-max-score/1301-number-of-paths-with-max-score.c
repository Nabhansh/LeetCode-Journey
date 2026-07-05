#define MOD 1000000007

int* pathsWithMaxScore(char** board, int boardSize, int* returnSize) {
    int n = boardSize;

    int score[n][n];
    int ways[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            score[i][j] = -1;
            ways[i][j] = 0;
        }
    }

    score[n - 1][n - 1] = 0;
    ways[n - 1][n - 1] = 1;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (board[i][j] == 'X' || (i == n - 1 && j == n - 1))
                continue;

            int best = -1;
            int cnt = 0;

            if (i + 1 < n && score[i + 1][j] != -1) {
                best = score[i + 1][j];
                cnt = ways[i + 1][j];
            }

            if (j + 1 < n && score[i][j + 1] != -1) {
                if (score[i][j + 1] > best) {
                    best = score[i][j + 1];
                    cnt = ways[i][j + 1];
                } else if (score[i][j + 1] == best) {
                    cnt = (cnt + ways[i][j + 1]) % MOD;
                }
            }

            if (i + 1 < n && j + 1 < n && score[i + 1][j + 1] != -1) {
                if (score[i + 1][j + 1] > best) {
                    best = score[i + 1][j + 1];
                    cnt = ways[i + 1][j + 1];
                } else if (score[i + 1][j + 1] == best) {
                    cnt = (cnt + ways[i + 1][j + 1]) % MOD;
                }
            }

            if (best == -1)
                continue;

            int val = 0;
            if (board[i][j] >= '1' && board[i][j] <= '9')
                val = board[i][j] - '0';

            score[i][j] = best + val;
            ways[i][j] = cnt;
        }
    }

    int *ans = (int *)malloc(2 * sizeof(int));
    *returnSize = 2;

    if (score[0][0] == -1) {
        ans[0] = 0;
        ans[1] = 0;
    } else {
        ans[0] = score[0][0];
        ans[1] = ways[0][0];
    }

    return ans;
}