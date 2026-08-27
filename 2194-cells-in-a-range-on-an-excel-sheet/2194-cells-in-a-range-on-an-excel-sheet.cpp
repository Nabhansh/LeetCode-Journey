class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;

        char c1 = s[0];
        int r1 = s[1] - '0';
        char c2 = s[3];
        int r2 = s[4] - '0';

        for (char c = c1; c <= c2; c++) {
            for (int r = r1; r <= r2; r++) {
                string cell;
                cell += c;
                cell += char('0' + r);
                ans.push_back(cell);
            }
        }

        return ans;
    }
};