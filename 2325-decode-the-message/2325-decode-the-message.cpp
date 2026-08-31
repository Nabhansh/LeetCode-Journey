class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<char> mp(26, 0);
        char cur = 'a';

        for (char c : key) {
            if (c != ' ' && mp[c - 'a'] == 0) {
                mp[c - 'a'] = cur++;
                if (cur > 'z') break;
            }
        }

        for (char &c : message) {
            if (c != ' ')
                c = mp[c - 'a'];
        }

        return message;
    }
};