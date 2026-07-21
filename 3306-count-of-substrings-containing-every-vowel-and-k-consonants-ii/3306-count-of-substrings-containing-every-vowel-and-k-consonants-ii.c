#include <string.h>

static inline int isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

static inline int idx(char c) {
    switch (c) {
        case 'a': return 0;
        case 'e': return 1;
        case 'i': return 2;
        case 'o': return 3;
        default: return 4; // 'u'
    }
}

static long long f(char *word, int k) {
    int cnt[5] = {0};
    int kinds = 0;
    int consonants = 0;
    int l = 0;
    long long ans = 0;

    int n = strlen(word);

    for (int r = 0; r < n; r++) {
        char c = word[r];

        if (isVowel(c)) {
            int t = idx(c);
            if (cnt[t]++ == 0)
                kinds++;
        } else {
            consonants++;
        }

        while (consonants >= k && kinds == 5) {
            char d = word[l++];

            if (isVowel(d)) {
                int t = idx(d);
                if (--cnt[t] == 0)
                    kinds--;
            } else {
                consonants--;
            }
        }

        ans += l;
    }

    return ans;
}

long long countOfSubstrings(char* word, int k) {
    return f(word, k) - f(word, k + 1);
}