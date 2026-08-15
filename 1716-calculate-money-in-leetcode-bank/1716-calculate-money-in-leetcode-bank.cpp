class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int monday = 1;

        for (int i = 0; i < n; i++) {
            ans += monday + i % 7;

            if (i % 7 == 6)
                monday++;
        }

        return ans;
    }
};