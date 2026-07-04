#include <string.h>
#include <stdlib.h>

int maximumLength(char* s) {
    int n = strlen(s);
    int *freq[26];

    for (int i = 0; i < 26; i++)
        freq[i] = (int *)calloc(n + 1, sizeof(int));

    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n && s[j] == s[i]) j++;
        freq[s[i] - 'a'][j - i]++;
        i = j;
    }

    int ans = -1;

    for (int c = 0; c < 26; c++) {
        long long cntRuns = 0;
        long long sumLen = 0;

        for (int len = n; len >= 1; len--) {
            cntRuns += freq[c][len];
            sumLen += 1LL * freq[c][len] * len;

            long long occ = sumLen - 1LL * (len - 1) * cntRuns;

            if (occ >= 3) {
                if (len > ans) ans = len;
                break;
            }
        }
    }

    for (int i = 0; i < 26; i++)
        free(freq[i]);

    return ans;
}