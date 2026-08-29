class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        vector<int> even, odd;

        for (char c : s) {
            int d = c - '0';
            if (d % 2 == 0)
                even.push_back(d);
            else
                odd.push_back(d);
        }

        sort(even.rbegin(), even.rend());
        sort(odd.rbegin(), odd.rend());

        int e = 0, o = 0;

        for (char &c : s) {
            int d = c - '0';
            if (d % 2 == 0)
                c = char('0' + even[e++]);
            else
                c = char('0' + odd[o++]);
        }

        return stoi(s);
    }
};