class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> cnt(101, 0);
        vector<int> ans;

        for (int x : nums1)
            cnt[x] |= 1;

        for (int x : nums2)
            cnt[x] |= 2;

        for (int x : nums3)
            cnt[x] |= 4;

        for (int i = 1; i <= 100; i++) {
            int bits = cnt[i];

            if (bits == 3 || bits == 5 || bits == 6 || bits == 7)
                ans.push_back(i);
        }

        return ans;
    }
};