class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;

        for (int x : nums) {
            int digits = 0;

            do {
                digits++;
                x /= 10;
            } while (x > 0);

            if (digits % 2 == 0)
                ans++;
        }

        return ans;
    }
};