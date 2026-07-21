#include <string.h>

int countCharacters(char** words, int wordsSize, char* chars) {
    int base[26] = {0};

    for (int i = 0; chars[i]; i++)
        base[chars[i] - 'a']++;

    int ans = 0;

    for (int i = 0; i < wordsSize; i++) {
        int cnt[26];
        memcpy(cnt, base, sizeof(base));

        int ok = 1;

        for (int j = 0; words[i][j]; j++) {
            if (--cnt[words[i][j] - 'a'] < 0) {
                ok = 0;
                break;
            }
        }

        if (ok)
            ans += strlen(words[i]);
    }

    return ans;
}