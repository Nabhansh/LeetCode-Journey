class Solution {
public:
    int countDigits(int num) {
        int x = num;
        int ans = 0;

        while (x > 0) {
            int digit = x % 10;

            if (num % digit == 0) {
                ans++;
            }

            x /= 10;
        }

        return ans;
    }
};