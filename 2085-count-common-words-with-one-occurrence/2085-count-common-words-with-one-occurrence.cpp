class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> a, b;

        for (auto &s : words1) a[s]++;
        for (auto &s : words2) b[s]++;

        int ans = 0;

        for (auto &[s, cnt] : a) {
            if (cnt == 1 && b[s] == 1)
                ans++;
        }

        return ans;
    }
};