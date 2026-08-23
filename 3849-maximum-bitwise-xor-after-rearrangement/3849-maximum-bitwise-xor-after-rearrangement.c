char* maximumXor(char* s, char* t) {
    int cnt[2] = {0, 0};
    int n = strlen(s);

    for (int i = 0; i < n; i++)
        cnt[t[i] - '0']++;

    char* ans = (char*)malloc((n + 1) * sizeof(char));

    for (int i = 0; i < n; i++) {
        int x = s[i] - '0';

        if (cnt[x ^ 1] > 0) {
            cnt[x ^ 1]--;
            ans[i] = '1';
        } else {
            cnt[x]--;
            ans[i] = '0';
        }
    }

    ans[n] = '\0';
    return ans;
}