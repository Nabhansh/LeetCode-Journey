class Solution {
public:
    string reformatNumber(string number) {
        string s = "";
        
        for (char c : number) {
            if (isdigit(c))
                s += c;
        }
        
        string ans = "";
        int n = s.size();
        int i = 0;
        
        while (n - i > 4) {
            if (!ans.empty())
                ans += '-';
            
            ans += s.substr(i, 3);
            i += 3;
        }
        
        if (!ans.empty())
            ans += '-';
        
        if (n - i == 4) {
            ans += s.substr(i, 2);
            ans += '-';
            ans += s.substr(i + 2, 2);
        }
        else {
            ans += s.substr(i);
        }
        
        return ans;
    }
};