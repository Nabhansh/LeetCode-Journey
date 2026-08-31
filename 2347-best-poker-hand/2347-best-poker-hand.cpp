class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        bool flush = true;

        for (int i = 1; i < 5; i++) {
            if (suits[i] != suits[0]) {
                flush = false;
                break;
            }
        }

        if (flush)
            return "Flush";

        vector<int> cnt(14, 0);
        int mx = 0;

        for (int x : ranks) {
            cnt[x]++;
            mx = max(mx, cnt[x]);
        }

        if (mx >= 3)
            return "Three of a Kind";

        if (mx == 2)
            return "Pair";

        return "High Card";
    }
};