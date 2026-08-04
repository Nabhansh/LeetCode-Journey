class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;

        for (int x : arr)
            freq[x]++;

        int ans = -1;

        for (auto &p : freq) {
            if (p.first == p.second)
                ans = max(ans, p.first);
        }

        return ans;
    }
};