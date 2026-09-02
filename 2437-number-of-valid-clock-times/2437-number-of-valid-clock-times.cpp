class Solution {
public:
    int countTime(string time) {
        int ans = 0;
        
        for (int h = 0; h < 24; h++) {
            for (int m = 0; m < 60; m++) {
                string s = to_string(h / 10) + to_string(h % 10) + ":" +
                           to_string(m / 10) + to_string(m % 10);
                
                bool ok = true;
                
                for (int i = 0; i < 5; i++) {
                    if (time[i] != '?' && time[i] != s[i]) {
                        ok = false;
                        break;
                    }
                }
                
                if (ok)
                    ans++;
            }
        }
        
        return ans;
    }
};