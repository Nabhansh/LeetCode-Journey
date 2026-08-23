int longestSubsequence(int* nums, int numsSize) {
    int ans = 0;
    int tail[100005];

    for (int bit = 0; bit < 31; bit++) {
        int len = 0;

        for (int i = 0; i < numsSize; i++) {
            if ((nums[i] >> bit) & 1) {
                int x = nums[i];
                int l = 0, r = len;

                while (l < r) {
                    int m = l + (r - l) / 2;
                    if (tail[m] < x)
                        l = m + 1;
                    else
                        r = m;
                }

                tail[l] = x;
                if (l == len)
                    len++;
            }
        }

        if (len > ans)
            ans = len;
    }

    return ans;
}