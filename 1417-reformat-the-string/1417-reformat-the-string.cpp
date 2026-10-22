class Solution {
public:
    string reformat(string s) {
        string letters, digits;

        for (char c : s) {
            if (isdigit(c))
                digits += c;
            else
                letters += c;
        }

        if (abs((int)letters.size() - (int)digits.size()) > 1)
            return "";

        if (letters.size() < digits.size())
            swap(letters, digits);

        string ans;

        for (int i = 0; i < letters.size(); i++) {
            ans += letters[i];

            if (i < digits.size())
                ans += digits[i];
        }

        return ans;
    }
};