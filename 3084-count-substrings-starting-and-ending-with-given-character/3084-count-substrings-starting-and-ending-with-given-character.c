long long countSubstrings(char* s, char c) {
    long long cnt = 0;
    for (int i = 0; s[i]; i++)
        if (s[i] == c)
            cnt++;
    return cnt * (cnt + 1) / 2;
}