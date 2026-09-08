class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int> ans(n, 0);

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < grid.size(); i++) {
                ans[j] = max(ans[j], (int)to_string(grid[i][j]).size());
            }
        }

        return ans;
    }
};