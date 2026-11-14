class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int totalOR = 0;

        for (int x : nums) {
            totalOR |= x;
        }

        return totalOR * (1 << (nums.size() - 1));
    }
};