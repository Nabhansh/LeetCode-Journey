class Solution {
public:
    bool checkZeroOnes(string s) {
        int ones = 0, zeros = 0;
        int cur = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                cur++;
                ones = max(ones, cur);
            } else {
                cur = 0;
            }
        }

        cur = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                cur++;
                zeros = max(zeros, cur);
            } else {
                cur = 0;
            }
        }

        return ones > zeros;
    }
};