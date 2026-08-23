int almostPalindromic(char* s) {
    int n = strlen(s);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int l = i, r = i;

        while (l >= 0 && r < n && s[l] == s[r]) {
            l--;
            r++;
        }

        int l1 = l - 1, r1 = r;
        int l2 = l, r2 = r + 1;

        while (l1 >= 0 && r1 < n && s[l1] == s[r1]) {
            l1--;
            r1++;
        }

        while (l2 >= 0 && r2 < n && s[l2] == s[r2]) {
            l2--;
            r2++;
        }

        int cur = r1 - l1 - 1;
        int cur2 = r2 - l2 - 1;

        if (cur2 > cur)
            cur = cur2;
        if (cur > n)
            cur = n;

        if (cur > ans)
            ans = cur;

        l = i;
        r = i + 1;

        while (l >= 0 && r < n && s[l] == s[r]) {
            l--;
            r++;
        }

        l1 = l - 1;
        r1 = r;
        l2 = l;
        r2 = r + 1;

        while (l1 >= 0 && r1 < n && s[l1] == s[r1]) {
            l1--;
            r1++;
        }

        while (l2 >= 0 && r2 < n && s[l2] == s[r2]) {
            l2--;
            r2++;
        }

        cur = r1 - l1 - 1;
        cur2 = r2 - l2 - 1;

        if (cur2 > cur)
            cur = cur2;
        if (cur > n)
            cur = n;

        if (cur > ans)
            ans = cur;
    }

    return ans;
}