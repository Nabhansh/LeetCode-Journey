long long minimumSteps(char *s) {
    long long ans = 0;
    long long zeros = 0;

    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] == '0')
            zeros++;
        else
            ans += zeros;
    }

    return ans;
}