int maxLengthBetweenEqualCharacters(char* s) {
    int first[26];

    for (int i = 0; i < 26; i++)
        first[i] = -1;

    int ans = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        int c = s[i] - 'a';

        if (first[c] == -1) {
            first[c] = i;
        } else {
            int length = i - first[c] - 1;

            if (length > ans)
                ans = length;
        }
    }

    return ans;
}