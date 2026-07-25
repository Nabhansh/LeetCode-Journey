#define MOD 1000000007

int lengthAfterTransformations(char* s, int t) {
    long long cnt[26] = {0};

    for (int i = 0; s[i]; i++)
        cnt[s[i] - 'a']++;

    while (t--) {
        long long next[26] = {0};

        for (int i = 0; i < 25; i++)
            next[i + 1] = (next[i + 1] + cnt[i]) % MOD;

        next[0] = (next[0] + cnt[25]) % MOD;
        next[1] = (next[1] + cnt[25]) % MOD;

        for (int i = 0; i < 26; i++)
            cnt[i] = next[i];
    }

    long long ans = 0;
    for (int i = 0; i < 26; i++)
        ans = (ans + cnt[i]) % MOD;

    return (int)ans;
}