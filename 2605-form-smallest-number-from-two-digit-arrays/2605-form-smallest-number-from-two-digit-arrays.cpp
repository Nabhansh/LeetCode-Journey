class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int common = 10;

        for (int a : nums1) {
            for (int b : nums2) {
                if (a == b)
                    common = min(common, a);
            }
        }

        if (common != 10)
            return common;

        int a = *min_element(nums1.begin(), nums1.end());
        int b = *min_element(nums2.begin(), nums2.end());

        return min(a, b) * 10 + max(a, b);
    }
};