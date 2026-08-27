class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start ^ goal;
        int ans = 0;

        while (x) {
            x &= x - 1;
            ans++;
        }

        return ans;
    }
};