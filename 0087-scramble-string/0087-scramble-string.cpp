class Solution {
public:
    unordered_map<string, bool> memo;

    bool solve(string a, string b) {
        if (a == b)
            return true;

        string key = a + "#" + b;

        if (memo.count(key))
            return memo[key];

        vector<int> freq(26, 0);

        for (int i = 0; i < a.size(); i++) {
            freq[a[i] - 'a']++;
            freq[b[i] - 'a']--;
        }

        for (int x : freq) {
            if (x != 0)
                return memo[key] = false;
        }

        int n = a.size();

        for (int i = 1; i < n; i++) {
            if (solve(a.substr(0, i), b.substr(0, i)) &&
                solve(a.substr(i), b.substr(i)))
                return memo[key] = true;

            if (solve(a.substr(0, i), b.substr(n - i)) &&
                solve(a.substr(i), b.substr(0, n - i)))
                return memo[key] = true;
        }

        return memo[key] = false;
    }

    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;

        return solve(s1, s2);
    }
};