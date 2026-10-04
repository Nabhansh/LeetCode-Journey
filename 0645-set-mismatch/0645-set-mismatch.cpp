class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        vector<int> freq(nums.size() + 1);

        for (int x : nums)
            freq[x]++;

        for (int i = 1; i <= nums.size(); i++) {
            if (freq[i] == 2)
                ans.push_back(i);
        }

        for (int i = 1; i <= nums.size(); i++) {
            if (freq[i] == 0)
                ans.push_back(i);
        }

        return ans;
    }
};