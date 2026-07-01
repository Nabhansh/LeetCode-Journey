int minOperations(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int n = nums1Size;

    int check(int a, int b) {
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums1[i] <= a && nums2[i] <= b)
                continue;
            if (nums2[i] <= a && nums1[i] <= b)
                cnt++;
            else
                return 1000000000;
        }
        return cnt;
    }

    int ans1 = check(nums1[n - 1], nums2[n - 1]);

    int t = nums1[n - 1];
    nums1[n - 1] = nums2[n - 1];
    nums2[n - 1] = t;

    int ans2 = check(nums1[n - 1], nums2[n - 1]);
    if (ans2 != 1000000000)
        ans2++;

    int ans = ans1 < ans2 ? ans1 : ans2;
    return ans >= 1000000000 ? -1 : ans;
}