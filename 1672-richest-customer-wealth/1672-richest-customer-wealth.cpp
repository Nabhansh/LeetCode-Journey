class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;

        for (auto account : accounts) {
            int sum = 0;

            for (int money : account)
                sum += money;

            ans = max(ans, sum);
        }

        return ans;
    }
};