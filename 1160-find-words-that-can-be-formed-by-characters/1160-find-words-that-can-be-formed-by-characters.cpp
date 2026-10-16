class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq(26, 0);

        for (char c : chars)
            freq[c - 'a']++;

        int ans = 0;

        for (string &word : words) {
            vector<int> cnt = freq;
            bool ok = true;

            for (char c : word) {
                if (--cnt[c - 'a'] < 0) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                ans += word.size();
        }

        return ans;
    }
};