class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> a(26, 0), b(26, 0);

        for (char c : s)
            a[c - 'a']++;

        for (char c : target)
            b[c - 'a']++;

        int ans = INT_MAX;

        for (int i = 0; i < 26; i++) {
            if (b[i] > 0)
                ans = min(ans, a[i] / b[i]);
        }

        return ans;
    }
};