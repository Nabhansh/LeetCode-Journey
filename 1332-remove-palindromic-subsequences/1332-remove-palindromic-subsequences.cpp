class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.empty())
            return 0;

        string rev = s;
        reverse(rev.begin(), rev.end());

        return s == rev ? 1 : 2;
    }
};