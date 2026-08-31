class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        int pairs = 0;

        for (int x : nums) {
            mp[x]++;
            if (mp[x] == 2) {
                pairs++;
                mp[x] = 0;
            }
        }

        int left = nums.size() - pairs * 2;
        return {pairs, left};
    }
};