class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool broken[26] = {};
        
        for (char c : brokenLetters)
            broken[c - 'a'] = true;

        int ans = 0;
        bool possible = true;

        for (char c : text) {
            if (c == ' ') {
                if (possible)
                    ans++;
                possible = true;
            } else if (broken[c - 'a']) {
                possible = false;
            }
        }

        if (possible)
            ans++;

        return ans;
    }
};