class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; i++) {
            vector<int> row(n + 1), col(n + 1);

            for (int j = 0; j < n; j++) {
                if (++row[matrix[i][j]] > 1)
                    return false;

                if (++col[matrix[j][i]] > 1)
                    return false;
            }
        }

        return true;
    }
};