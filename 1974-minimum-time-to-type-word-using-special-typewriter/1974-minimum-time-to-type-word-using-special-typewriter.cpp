class Solution {
public:
    int minTimeToType(string word) {
        int ans = 0;
        char cur = 'a';

        for (char c : word) {
            int d = abs(c - cur);
            ans += min(d, 26 - d) + 1;
            cur = c;
        }

        return ans;
    }
};