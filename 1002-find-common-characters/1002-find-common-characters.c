#include <stdlib.h>
#include <string.h>
#include <limits.h>

char** commonChars(char** words, int wordsSize, int* returnSize) {
    int minFreq[26];

    for (int i = 0; i < 26; i++) {
        minFreq[i] = INT_MAX;
    }

    for (int i = 0; i < wordsSize; i++) {
        int freq[26] = {0};

        for (int j = 0; words[i][j] != '\0'; j++) {
            freq[words[i][j] - 'a']++;
        }

        for (int j = 0; j < 26; j++) {
            if (freq[j] < minFreq[j]) {
                minFreq[j] = freq[j];
            }
        }
    }

    int total = 0;

    for (int i = 0; i < 26; i++) {
        total += minFreq[i];
    }

    char** answer = (char**)malloc(total * sizeof(char*));
    int index = 0;

    for (int i = 0; i < 26; i++) {
        for (int count = 0; count < minFreq[i]; count++) {
            answer[index] = (char*)malloc(2 * sizeof(char));
            answer[index][0] = 'a' + i;
            answer[index][1] = '\0';
            index++;
        }
    }

    *returnSize = total;
    return answer;
}