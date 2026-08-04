class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> ans;

        for (int i = 0; i < m; i++) {
            int col = 0;

            for (int j = 1; j < n; j++) {
                if (matrix[i][j] < matrix[i][col])
                    col = j;
            }

            bool ok = true;

            for (int k = 0; k < m; k++) {
                if (matrix[k][col] > matrix[i][col]) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                ans.push_back(matrix[i][col]);
        }

        return ans;
    }
};