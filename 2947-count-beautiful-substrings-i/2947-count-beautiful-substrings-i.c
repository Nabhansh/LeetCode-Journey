bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int beautifulSubstrings(char* s, int k) {
    int n = strlen(s);
    int ans = 0;

    for (int i = 1;; i++) {
        if ((i * i) % k == 0) {
            k = i;
            break;
        }
    }

    int *cnt = (int *)calloc((2 * n + 1) * k, sizeof(int));

    int bal = 0;
    int vowels = 0;
    cnt[n * k] = 1;

    for (int i = 0; i < n; i++) {
        if (isVowel(s[i])) {
            bal++;
            vowels = (vowels + 1) % k;
        } else {
            bal--;
        }

        ans += cnt[(bal + n) * k + vowels];
        cnt[(bal + n) * k + vowels]++;
    }

    free(cnt);
    return ans;
}