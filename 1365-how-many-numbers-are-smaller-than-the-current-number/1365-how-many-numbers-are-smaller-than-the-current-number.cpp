class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> rank;

        for (int i = 0; i < sorted.size(); i++) {
            if (!rank.count(sorted[i]))
                rank[sorted[i]] = i;
        }

        vector<int> ans;

        for (int x : nums)
            ans.push_back(rank[x]);

        return ans;
    }
};