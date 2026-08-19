class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int idx = -1;
        int n = nums.size();
        for (int i = 0; i + 1 < n; i++) {
            if (nums[i] >= nums[i + 1]) {
                idx = i;
                break;
            }
        }
        bool flag = true;
        // before idx array is already strictly increasing
        for (int i = idx + 1; i + 1 < n; i++) {
            if (nums[i] >= nums[i + 1]) {
                flag = false;
                break;
            }
        }
        if ((idx == 0 || idx == n - 1) && flag)
            return 1;
        if ((idx - 1 >= 0 && idx + 1 < n && nums[idx - 1] < nums[idx + 1]) &&
            flag)
            return 1;
        // find first non balanced index from the end of nums
        for (int i = n - 1; i - 1 >= 0; i--) {
            if (nums[i] <= nums[i - 1]) {
                idx = i;
                break;
            }
        }
        flag = true;
        for (int i = idx - 1; i - 1 >= 0; i--) {
            if (nums[i] <= nums[i - 1]) {
                flag = false;
                break;
            }
        }
        if ((idx == 0 || idx == n - 1) && flag)
            return 1;
        if (idx - 1 >= 0 && idx + 1 < n && (nums[idx - 1] >= nums[idx + 1]))
            return false;
        if (flag)
            return true;
        return false;
    }
};