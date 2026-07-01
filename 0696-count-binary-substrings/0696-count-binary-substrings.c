int countBinarySubstrings(char *s) {
    int prev = 0;
    int curr = 1;
    int ans = 0;

    for (int i = 1; s[i] != '\0'; i++) {
        if (s[i] == s[i - 1]) {
            curr++;
        } else {
            ans += (prev < curr) ? prev : curr;
            prev = curr;
            curr = 1;
        }
    }

    ans += (prev < curr) ? prev : curr;

    return ans;
}