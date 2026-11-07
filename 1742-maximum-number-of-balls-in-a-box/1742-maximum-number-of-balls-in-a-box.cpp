class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> freq;

        int ans = 0;

        for (int i = lowLimit; i <= highLimit; i++) {
            int x = i;
            int sum = 0;

            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }

            freq[sum]++;
            ans = max(ans, freq[sum]);
        }

        return ans;
    }
};