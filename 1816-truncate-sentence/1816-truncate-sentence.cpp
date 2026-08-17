class Solution {
public:
    string truncateSentence(string s, int k) {
        int words = 0;
        int i = 0;

        while (i < s.size() && words < k) {
            if (s[i] == ' ') {
                words++;
            }
            i++;
        }
        
        if (words < k)
            return s;

        return s.substr(0, i - 1);
    }
};