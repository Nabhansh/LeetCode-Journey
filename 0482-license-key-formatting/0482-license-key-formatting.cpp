class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string t;

        for (char c : s) {
            if (c != '-')
                t += toupper(c);
        }

        string ans;
        int first = t.size() % k;
        int i = 0;

        if (first) {
            ans += t.substr(0, first);
            i = first;
        }

        while (i < t.size()) {
            if (!ans.empty())
                ans += '-';

            ans += t.substr(i, k);
            i += k;
        }

        return ans;
    }
};