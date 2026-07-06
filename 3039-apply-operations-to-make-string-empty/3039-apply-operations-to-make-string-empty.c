#include <string.h>
#include <stdlib.h>

char* lastNonEmptyString(char* s) {
    int freq[26] = {0};
    int mx = 0;

    for (int i = 0; s[i]; i++) {
        freq[s[i] - 'a']++;
        if (freq[s[i] - 'a'] > mx)
            mx = freq[s[i] - 'a'];
    }

    int last[26];
    for (int i = 0; i < 26; i++)
        last[i] = -1;

    for (int i = 0; s[i]; i++)
        last[s[i] - 'a'] = i;

    char *ans = (char *)malloc(27);
    int idx = 0;

    for (int i = 0; s[i]; i++) {
        int c = s[i] - 'a';
        if (freq[c] == mx && last[c] == i)
            ans[idx++] = s[i];
    }

    ans[idx] = '\0';
    return ans;
}