class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> v;

        for (int i = 0; i < nums.size(); i++)
            v.push_back({nums[i], i});

        sort(v.rbegin(), v.rend());

        vector<int> indices;

        for (int i = 0; i < k; i++)
            indices.push_back(v[i].second);

        sort(indices.begin(), indices.end());

        vector<int> ans;

        for (int i : indices)
            ans.push_back(nums[i]);

        return ans;
    }
};