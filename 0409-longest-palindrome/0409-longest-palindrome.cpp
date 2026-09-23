class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq(128, 0);

        for (char c : s)
            freq[c]++;

        int ans = 0;
        bool odd = false;

        for (int x : freq) {
            ans += (x / 2) * 2;

            if (x % 2)
                odd = true;
        }

        if (odd)
            ans++;

        return ans;
    }
};