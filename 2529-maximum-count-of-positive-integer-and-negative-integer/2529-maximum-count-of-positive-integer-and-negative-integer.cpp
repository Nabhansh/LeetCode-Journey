class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int positive = 0;
        int negative = 0;

        for (int x : nums) {
            if (x > 0) {
                positive++;
            } else if (x < 0) {
                negative++;
            }
        }

        return max(positive, negative);
    }
};