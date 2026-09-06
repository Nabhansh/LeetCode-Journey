class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);

        string mx = s;
        string mn = s;

        char a = 0;

        for (char c : s) {
            if (c != '9') {
                a = c;
                break;
            }
        }

        if (a) {
            for (char& c : mx) {
                if (c == a)
                    c = '9';
            }
        }

        a = s[0];

        for (char& c : mn) {
            if (c == a)
                c = '0';
        }

        return stoi(mx) - stoi(mn);
    }
};