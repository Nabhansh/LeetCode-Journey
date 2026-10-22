class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int previous = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (previous != -1 && i - previous <= k)
                    return false;

                previous = i;
            }
        }

        return true;
    }
};