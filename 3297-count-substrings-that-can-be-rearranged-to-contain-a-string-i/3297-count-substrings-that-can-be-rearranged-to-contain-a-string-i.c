typedef long long ll;

long long validSubstringCount(char* word1, char* word2) {
    int need[26] = {0};
    int have[26] = {0};

    int required = 0;

    for (int i = 0; word2[i]; i++) {
        if (need[word2[i] - 'a']++ == 0)
            required++;
    }

    int formed = 0;
    ll ans = 0;

    int l = 0;
    int n = strlen(word1);

    for (int r = 0; r < n; r++) {
        int c = word1[r] - 'a';

        have[c]++;
        if (have[c] == need[c] && need[c] > 0)
            formed++;

        while (formed == required) {
            ans += n - r;

            c = word1[l++] - 'a';

            if (have[c] == need[c] && need[c] > 0)
                formed--;

            have[c]--;
        }
    }

    return ans;
}