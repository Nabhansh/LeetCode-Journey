class Solution {
public:
    int count(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int countBalls(int lowLimit, int highLimit) {
        int boxes[50] = {};
        int ans = 0;

        for (int i = lowLimit; i <= highLimit; i++) {
            boxes[count(i)]++;
        }

        for (int i = 0; i < 50; i++) {
            ans = max(ans, boxes[i]);
        }

        return ans;
    }
};