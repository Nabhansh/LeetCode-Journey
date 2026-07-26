char* freqAlphabets(char* s) {

    int n = strlen(s);

    char *ans = (char *)malloc((n + 1) * sizeof(char));
    int idx = 0;

    for (int i = n - 1; i >= 0;) {

        if (s[i] == '#') {
            int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            ans[idx++] = 'a' + num - 1;
            i -= 3;
        } else {
            ans[idx++] = 'a' + (s[i] - '0') - 1;
            i--;
        }
    }

    ans[idx] = '\0';

    for (int i = 0; i < idx / 2; i++) {
        char t = ans[i];
        ans[i] = ans[idx - i - 1];
        ans[idx - i - 1] = t;
    }

    return ans;
}