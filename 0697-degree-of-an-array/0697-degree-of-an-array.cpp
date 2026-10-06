class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int> first;

        int degree = 0;
        int ans = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            if (!first.count(nums[i]))
                first[nums[i]] = i;

            freq[nums[i]]++;
            degree = max(degree, freq[nums[i]]);
        }

        for (auto& [x, f] : freq) {
            if (f == degree) {
                int len = nums.size() - first[x];

                for (int i = nums.size() - 1; i >= first[x]; i--) {
                    if (nums[i] == x) {
                        len = i - first[x] + 1;
                        break;
                    }
                }

                ans = min(ans, len);
            }
        }

        return ans;
    }
};