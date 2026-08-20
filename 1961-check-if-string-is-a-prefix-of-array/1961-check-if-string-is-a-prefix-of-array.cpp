class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string t;
        
        for (string word : words) {
            t += word;
            
            if (t == s)
                return true;
            
            if (t.size() > s.size())
                return false;
        }
        
        return false;
    }
};