class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long sum = 0;

        for (int i = 0; i < k; i++)
            sum += nums[i];

        long long best = sum;

        for (int i = k; i < nums.size(); i++) {
            sum += nums[i];
            sum -= nums[i - k];
            best = max(best, sum);
        }

        return (double)best / k;
    }
};