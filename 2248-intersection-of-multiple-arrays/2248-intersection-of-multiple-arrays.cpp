class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> freq(1001, 0);

        for (auto &v : nums)
            for (int x : v)
                freq[x]++;

        vector<int> ans;

        for (int i = 1; i <= 1000; i++) {
            if (freq[i] == n)
                ans.push_back(i);
        }

        return ans;
    }
};