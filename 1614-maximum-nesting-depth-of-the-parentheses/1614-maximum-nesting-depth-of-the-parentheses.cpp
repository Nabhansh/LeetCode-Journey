class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int maximum = 0;

        for (char c : s) {
            if (c == '(') {
                depth++;
                maximum = max(maximum, depth);
            } else if (c == ')') {
                depth--;
            }
        }

        return maximum;
    }
};