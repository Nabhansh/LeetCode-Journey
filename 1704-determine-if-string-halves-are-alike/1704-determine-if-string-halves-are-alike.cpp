class Solution {
public:
    bool halvesAreAlike(string s) {
        string vowels = "aeiouAEIOU";

        int a = 0, b = 0;
        int n = s.size();

        for (int i = 0; i < n / 2; i++) {
            if (vowels.find(s[i]) != string::npos)
                a++;

            if (vowels.find(s[i + n / 2]) != string::npos)
                b++;
        }

        return a == b;
    }
};