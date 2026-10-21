class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0;
        int minPrefix = 0;

        for (int x : nums) {
            sum += x;
            minPrefix = min(minPrefix, sum);
        }

        return 1 - minPrefix;
    }
};