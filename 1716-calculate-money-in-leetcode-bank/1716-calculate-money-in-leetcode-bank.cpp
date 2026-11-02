class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int week = i / 7;
            int day = i % 7;

            ans += 1 + week + day;
        }

        return ans;
    }
};