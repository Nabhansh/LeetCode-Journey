class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            long long multiplier = 1;
            int x = nums[right];

            while (x > 0) {
                multiplier *= 10;
                x /= 10;
            }

            ans += 1LL * nums[left] * multiplier + nums[right];

            left++;
            right--;
        }

        if (left == right)
            ans += nums[left];

        return ans;
    }
};