int longestSubarray(int* nums, int numsSize, int k) {
    int maxVal = 100000;

    int *spf = malloc(sizeof(int) * (maxVal + 1));

    for (int i = 0; i <= maxVal; i++)
        spf[i] = i;

    for (int i = 2; i * i <= maxVal; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= maxVal; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }

    int *cnt = calloc(maxVal + 1, sizeof(int));
    int left = 0;
    int distinct = 0;
    int ans = 0;

    for (int right = 0; right < numsSize; right++) {
        int x = nums[right];

        while (x > 1) {
            int p = spf[x];

            if (cnt[p] == 0)
                distinct++;

            cnt[p]++;

            while (x % p == 0)
                x /= p;
        }

        while (distinct > k) {
            x = nums[left];

            while (x > 1) {
                int p = spf[x];

                cnt[p]--;

                if (cnt[p] == 0)
                    distinct--;

                while (x % p == 0)
                    x /= p;
            }

            left++;
        }

        int len = right - left + 1;

        if (len > ans)
            ans = len;
    }

    free(spf);
    free(cnt);

    return ans;
}