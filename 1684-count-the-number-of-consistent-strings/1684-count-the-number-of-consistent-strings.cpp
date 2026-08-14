class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool allowedChars[26] = {};
        
        for (char c : allowed)
            allowedChars[c - 'a'] = true;
        
        int ans = 0;
        
        for (string &word : words) {
            bool valid = true;
            
            for (char c : word) {
                if (!allowedChars[c - 'a']) {
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