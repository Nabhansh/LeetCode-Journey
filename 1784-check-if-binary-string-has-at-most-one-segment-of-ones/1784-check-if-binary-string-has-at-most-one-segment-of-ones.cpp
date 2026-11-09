class Solution {
public:
    bool checkOnesSegment(string s) {
        bool seenOne = false;
        bool seenZeroAfterOne = false;

        for (char c : s) {
            if (c == '1') {
                if (seenZeroAfterOne)
                    return false;

                seenOne = true;
            }
            else if (seenOne) {
                seenZeroAfterOne = true;
            }
        }

        return true;
    }
};