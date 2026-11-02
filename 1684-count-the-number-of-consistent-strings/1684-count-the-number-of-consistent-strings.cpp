class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool valid[26] = {};

        for (char c : allowed)
            valid[c - 'a'] = true;

        int ans = 0;

        for (string word : words) {
            bool consistent = true;

            for (char c : word) {
                if (!valid[c - 'a']) {
                    consistent = false;
                    break;
                }
            }

            if (consistent) ans++;
        }

        return ans;
    }
};