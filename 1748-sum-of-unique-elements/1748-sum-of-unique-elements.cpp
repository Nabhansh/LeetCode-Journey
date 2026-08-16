class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int freq[101] = {};

        for (int x : nums)
            freq[x]++;

        int ans = 0;

        for (int x : nums) {
            if (freq[x] == 1)
                ans += x;
        }

        return ans;
    }
};