class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        int j = 0;

        for (int x : nums) {
            if (x != 0)
                nums[j++] = x;
        }

        while (j < n)
            nums[j++] = 0;

        return nums;
    }
};