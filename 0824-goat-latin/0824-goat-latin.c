#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool vowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

char *toGoatLatin(char *sentence) {
    int n = strlen(sentence);
    // Increased allocation to prevent buffer overflow
    char *ans = malloc(10000 * sizeof(char)); 
    int p = 0, word = 1;

    for (int i = 0; i < n; ) {
        int start = i;
        while (i < n && sentence[i] != ' ') i++;
        int end = i;

        if (vowel(sentence[start])) {
            for (int j = start; j < end; j++)
                ans[p++] = sentence[j];
        } else {
            for (int j = start + 1; j < end; j++)
                ans[p++] = sentence[j];
            ans[p++] = sentence[start];
        }

        ans[p++] = 'm';
        ans[p++] = 'a';
        for (int j = 0; j < word; j++)
            ans[p++] = 'a';

        if (i < n)
            ans[p++] = ' ';
            
        word++;
        i++;
    }
    ans[p] = '\0';
    return ans;
}