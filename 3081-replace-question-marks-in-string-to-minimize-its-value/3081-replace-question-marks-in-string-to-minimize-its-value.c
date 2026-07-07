#include <stdlib.h>
#include <string.h>

int cmpChar(const void *a, const void *b) {
    return (*(char *)a) - (*(char *)b);
}

char* minimizeStringValue(char* s) {
    int freq[26] = {0};
    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        if (s[i] != '?')
            freq[s[i] - 'a']++;
    }

    char rep[100005];
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            int best = 0;
            for (int j = 1; j < 26; j++) {
                if (freq[j] < freq[best])
                    best = j;
            }
            rep[cnt++] = (char)(best + 'a');
            freq[best]++;
        }
    }

    qsort(rep, cnt, sizeof(char), cmpChar);

    int p = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?')
            s[i] = rep[p++];
    }

    return s;
}