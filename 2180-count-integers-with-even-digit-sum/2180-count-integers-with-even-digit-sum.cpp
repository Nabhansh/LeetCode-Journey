class Solution {
public:
    int countEven(int num) {
        int sum = 0;
        int x = num;

        while (x) {
            sum += x % 10;
            x /= 10;
        }

        return (num - sum % 2) / 2;
    }
};