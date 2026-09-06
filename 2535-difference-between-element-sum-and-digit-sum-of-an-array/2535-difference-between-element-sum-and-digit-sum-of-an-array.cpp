class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elementSum = 0;
        int digitSum = 0;

        for (int x : nums) {
            elementSum += x;

            while (x > 0) {
                digitSum += x % 10;
                x /= 10;
            }
        }

        return abs(elementSum - digitSum);
    }
};