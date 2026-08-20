class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int freq[26] = {};
        
        for (char c : s)
            freq[c - 'a']++;
        
        int x = 0;
        
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                if (x == 0)
                    x = freq[i];
                else if (freq[i] != x)
                    return false;
            }
        }
        
        return true;
    }
};