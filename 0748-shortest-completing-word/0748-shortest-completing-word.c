#include <ctype.h>
#include <string.h>

void countLetters(char *s, int *cnt) {
    while (*s) {
        if (isalpha(*s))
            cnt[tolower(*s) - 'a']++;
        s++;
    }
}

char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {
    int need[26] = {0};
    countLetters(licensePlate, need);

    char *ans = NULL;
    int bestLen = 1000;

    for (int i = 0; i < wordsSize; i++) {
        int have[26] = {0};
        countLetters(words[i], have);

        int ok = 1;
        for (int j = 0; j < 26; j++) {
            if (have[j] < need[j]) {
                ok = 0;
                break;
            }
        }

        if (ok) {
            int len = strlen(words[i]);
            if (len < bestLen) {
                bestLen = len;
                ans = words[i];
            }
        }
    }

    return ans;
}