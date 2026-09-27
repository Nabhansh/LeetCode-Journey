class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;

        for (int x : nums) {
            int idx = abs(x) - 1;
            nums[idx] = -abs(nums[idx]);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                ans.push_back(i + 1);
        }

        return ans;
    }
};