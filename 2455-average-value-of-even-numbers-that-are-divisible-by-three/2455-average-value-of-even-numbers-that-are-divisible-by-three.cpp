class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0, count = 0;

        for (int x : nums) {
            if (x % 2 == 0 && x % 3 == 0) {
                sum += x;
                count++;
            }
        }

        return count ? sum / count : 0;
    }
};