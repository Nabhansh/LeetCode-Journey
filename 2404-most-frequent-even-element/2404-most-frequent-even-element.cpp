class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int x : nums) {
            if (x % 2 == 0)
                freq[x]++;
        }

        int ans = -1;
        int maxFreq = 0;

        for (auto& p : freq) {
            if (p.second > maxFreq || (p.second == maxFreq && p.first < ans)) {
                maxFreq = p.second;
                ans = p.first;
            }
        }

        return ans;
    }
};