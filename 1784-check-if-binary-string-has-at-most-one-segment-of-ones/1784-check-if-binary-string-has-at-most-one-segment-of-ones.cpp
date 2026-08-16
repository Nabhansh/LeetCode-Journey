class Solution {
public:
    bool checkOnesSegment(string s) {
        bool found = false;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                if (found && i > 0 && s[i - 1] == '0')
                    return false;

                found = true;
            }
        }

        return true;
    }
};