class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        sort(nums.begin(), nums.end());
        int maximum = 3;
        int i = nums.size() - 1;

        while (maximum != 1 && i > 0) {
            if (nums[i] != nums[i - 1]) {
                maximum--;
            }
            i--;
        }
        if (maximum == 1) {
            return nums[i];
        }

        return nums[nums.size() - 1];
    }
};