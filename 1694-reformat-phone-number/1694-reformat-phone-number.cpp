class Solution {
public:
    string reformatNumber(string number) {
        string digits = "";

        for (char c : number) {
            if (isdigit(c))
                digits += c;
        }

        string ans;
        int i = 0;
        int n = digits.size();

        while (n - i > 4) {
            ans += digits.substr(i, 3) + "-";
            i += 3;
        }

        int remaining = n - i;

        if (remaining == 4) {
            ans += digits.substr(i, 2) + "-";
            ans += digits.substr(i + 2, 2);
        } 
        else {
            ans += digits.substr(i);
        }

        return ans;
    }
};