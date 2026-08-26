class Solution {
public:
    int countElements(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        int ans = 0;

        for (int x : nums) {
            if (x > mn && x < mx)
                ans++;
        }

        return ans;
    }
};