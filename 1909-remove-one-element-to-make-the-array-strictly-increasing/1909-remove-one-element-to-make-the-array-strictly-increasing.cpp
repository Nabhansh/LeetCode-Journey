class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();

        auto check = [&](int skip) {
            int previous = -1;

            for (int i = 0; i < n; i++) {
                if (i == skip)
                    continue;

                if (previous != -1 && nums[i] <= nums[previous])
                    return false;

                previous = i;
            }

            return true;
        };

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] >= nums[i + 1]) {
                return check(i) || check(i + 1);
            }
        }

        return true;
    }
};