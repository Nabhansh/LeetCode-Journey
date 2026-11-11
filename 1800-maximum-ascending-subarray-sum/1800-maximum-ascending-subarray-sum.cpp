class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int current = nums[0];
        int ans = current;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1])
                current += nums[i];
            else
                current = nums[i];

            ans = max(ans, current);
        }

        return ans;
    }
};