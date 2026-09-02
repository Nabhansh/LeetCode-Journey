class Solution {
public:
    bool equalFrequency(string word) {
        for (int i = 0; i < word.size(); i++) {
            int freq[26] = {};
            
            for (int j = 0; j < word.size(); j++) {
                if (i != j)
                    freq[word[j] - 'a']++;
            }
            
            int x = 0;
            bool ok = true;
            
            for (int j = 0; j < 26; j++) {
                if (freq[j]) {
                    if (x == 0)
                        x = freq[j];
                    else if (freq[j] != x) {
                        ok = false;
                        break;
                    }
                }
            }
            
            if (ok)
                return true;
        }
        
        return false;
    }
};