class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());

        int total = accumulate(nums.begin(), nums.end(), 0);
        int chosen = 0;
        vector<int> ans;

        for (int x : nums) {
            ans.push_back(x);
            chosen += x;

            if (chosen > total - chosen)
                break;
        }

        return ans;
    }
};