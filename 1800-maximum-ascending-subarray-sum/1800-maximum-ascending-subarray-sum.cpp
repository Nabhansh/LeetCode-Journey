class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int current = nums[0];
        int answer = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                current += nums[i];
            }
            else {
                current = nums[i];
            }

            answer = max(answer, current);
        }

        return answer;
    }
};