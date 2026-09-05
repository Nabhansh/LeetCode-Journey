class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans = 0;

        for (string s : strs) {
            bool numeric = true;

            for (char c : s) {
                if (!isdigit(c)) {
                    numeric = false;
                    break;
                }
            }

            if (numeric)
                ans = max(ans, stoi(s));
            else
                ans = max(ans, (int)s.size());
        }

        return ans;
    }
};