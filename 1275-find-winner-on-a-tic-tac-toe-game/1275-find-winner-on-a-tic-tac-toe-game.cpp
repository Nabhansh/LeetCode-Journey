class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int row[3] = {}, col[3] = {};
        int diagonal = 0, antiDiagonal = 0;

        for (int i = 0; i < moves.size(); i++) {
            int r = moves[i][0];
            int c = moves[i][1];
            int value = (i % 2 == 0) ? 1 : -1;

            row[r] += value;
            col[c] += value;

            if (r == c)
                diagonal += value;

            if (r + c == 2)
                antiDiagonal += value;

            if (abs(row[r]) == 3 || abs(col[c]) == 3 ||
                abs(diagonal) == 3 || abs(antiDiagonal) == 3)
                return value == 1 ? "A" : "B";
        }

        return moves.size() == 9 ? "Draw" : "Pending";
    }
};