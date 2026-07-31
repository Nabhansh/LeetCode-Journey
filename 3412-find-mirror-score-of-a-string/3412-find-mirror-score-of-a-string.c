#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100005

// Mirror function
char mirrorChar(char c) {
    return 'z' - (c - 'a');
}

long long calculateScore(char* s) {
    int n = strlen(s);
    long long score = 0;

    // stacks for each character
    int stacks[26][MAXN];
    int top[26] = {0};
    int marked[MAXN] = {0};

    for (int i = 0; i < n; i++) {
        char c = s[i];
        char m = mirrorChar(c);
        int mi = m - 'a';

        // discard already marked indices
        while (top[mi] > 0 && marked[stacks[mi][top[mi]-1]]) {
            top[mi]--;
        }

        if (top[mi] > 0) {
            int j = stacks[mi][--top[mi]];
            marked[i] = marked[j] = 1;
            score += (i - j);
        } else {
            stacks[c - 'a'][top[c - 'a']++] = i;
        }
    }

    return score;
}