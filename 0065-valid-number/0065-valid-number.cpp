class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        int i = 0;

        while (i < n && s[i] == ' ')
            i++;

        if (i == n)
            return false;

        if (s[i] == '+' || s[i] == '-')
            i++;

        bool digit = false;
        bool dot = false;

        while (i < n && s[i] != 'e' && s[i] != 'E') {
            if (isdigit(s[i])) {
                digit = true;
            } else if (s[i] == '.' && !dot) {
                dot = true;
            } else {
                return false;
            }

            i++;
        }

        if (!digit)
            return false;

        if (i < n) {
            i++;

            if (i < n && (s[i] == '+' || s[i] == '-'))
                i++;

            bool exponentDigit = false;

            while (i < n) {
                if (!isdigit(s[i]))
                    return false;

                exponentDigit = true;
                i++;
            }

            if (!exponentDigit)
                return false;
        }

        while (i < n && s[i] == ' ')
            i++;

        return i == n;
    }
};