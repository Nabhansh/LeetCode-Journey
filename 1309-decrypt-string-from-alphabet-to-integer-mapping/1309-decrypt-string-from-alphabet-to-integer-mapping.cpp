class Solution {
public:
    string freqAlphabets(string s) {
        string ans;

        for (int i = 0; i < s.size();) {
            if (i + 2 < s.size() && s[i + 2] == '#') {
                int num = stoi(s.substr(i, 2));
                ans += char('a' + num - 1);
                i += 3;
            } else {
                int num = s[i] - '0';
                ans += char('a' + num - 1);
                i++;
            }
        }

        return ans;
    }
};