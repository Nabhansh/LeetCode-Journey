class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;

        for (int x : nums) {
            if (s.count(x + diff) && s.count(x + 2 * diff))
                ans++;
        }

        return ans;
    }
};