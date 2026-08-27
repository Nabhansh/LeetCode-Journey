class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> mp;
        int ans = 0;
        int best = 0;

        for (int i = 0; i + 1 < nums.size(); i++) {
            if (nums[i] == key) {
                mp[nums[i + 1]]++;

                if (mp[nums[i + 1]] > best) {
                    best = mp[nums[i + 1]];
                    ans = nums[i + 1];
                }
            }
        }

        return ans;
    }
};