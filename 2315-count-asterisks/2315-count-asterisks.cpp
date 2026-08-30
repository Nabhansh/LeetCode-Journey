class Solution {
public:
    int countAsterisks(string s) {
        int ans = 0;
        bool inside = false;

        for (char c : s) {
            if (c == '|')
                inside = !inside;
            else if (c == '*' && !inside)
                ans++;
        }

        return ans;
    }
};