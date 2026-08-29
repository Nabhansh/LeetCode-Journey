int passwordStrength(char* password) {
    int seen[128] = {0};
    int ans = 0;

    for (int i = 0; password[i]; i++) {
        unsigned char c = password[i];

        if (seen[c])
            continue;

        seen[c] = 1;

        if (c >= 'a' && c <= 'z')
            ans += 1;
        else if (c >= 'A' && c <= 'Z')
            ans += 2;
        else if (c >= '0' && c <= '9')
            ans += 3;
        else
            ans += 5;
    }

    return ans;
}