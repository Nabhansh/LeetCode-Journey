class Solution {
public:
    int time(string s) {
        return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
    }

    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int a = time(event1[0]);
        int b = time(event1[1]);
        int c = time(event2[0]);
        int d = time(event2[1]);

        return max(a, c) <= min(b, d);
    }
};