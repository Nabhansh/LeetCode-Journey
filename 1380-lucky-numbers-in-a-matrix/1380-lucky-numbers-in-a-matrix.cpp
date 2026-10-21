class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> ans;

        for (int i = 0; i < m; i++) {
            int minCol = min_element(
                matrix[i].begin(), matrix[i].end()
            ) - matrix[i].begin();

            int value = matrix[i][minCol];
            bool lucky = true;

            for (int r = 0; r < m; r++) {
                if (matrix[r][minCol] > value) {
                    lucky = false;
                    break;
                }
            }

            if (lucky)
                ans.push_back(value);
        }

        return ans;
    }
};