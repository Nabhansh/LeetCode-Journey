class Solution {
public:
    int convertTime(string current, string correct) {
        int h1 = stoi(current.substr(0, 2));
        int m1 = stoi(current.substr(3, 2));
        int h2 = stoi(correct.substr(0, 2));
        int m2 = stoi(correct.substr(3, 2));

        int diff = (h2 * 60 + m2) - (h1 * 60 + m1);
        int ans = 0;

        for (int x : {60, 15, 5, 1}) {
            ans += diff / x;
            diff %= x;
        }

        return ans;
    }
};