class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool broken[26] = {};

        for (char c : brokenLetters) {
            broken[c - 'a'] = true;
        }

        stringstream ss(text);
        string word;

        int ans = 0;

        while (ss >> word) {
            bool valid = true;

            for (char c : word) {
                if (broken[c - 'a']) {
                    valid = false;
                    break;
                }
            }

            if (valid)
                ans++;
        }

        return ans;
    }
};