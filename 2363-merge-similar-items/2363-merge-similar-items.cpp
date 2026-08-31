class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<int> sum(1001, 0);

        for (auto &x : items1)
            sum[x[0]] += x[1];

        for (auto &x : items2)
            sum[x[0]] += x[1];

        vector<vector<int>> ans;

        for (int i = 1; i <= 1000; i++) {
            if (sum[i])
                ans.push_back({i, sum[i]});
        }

        return ans;
    }
};