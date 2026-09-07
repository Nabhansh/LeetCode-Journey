class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int left = 0;

        vector<int> ans;

        for (int x : nums) {
            total -= x;
            ans.push_back(abs(left - total));
            left += x;
        }

        return ans;
    }
};