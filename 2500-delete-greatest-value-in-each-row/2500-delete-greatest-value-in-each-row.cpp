class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for (auto& row : grid)
            sort(row.begin(), row.end());

        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();

        for (int j = 0; j < m; j++) {
            int mx = 0;

            for (int i = 0; i < n; i++)
                mx = max(mx, grid[i][j]);

            ans += mx;
        }

        return ans;
    }
};