#include <string.h>
#include <stdlib.h>

char** stringMatching(char** words, int wordsSize, int* returnSize) {
    char** ans = (char**)malloc(wordsSize * sizeof(char*));
    *returnSize = 0;

    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < wordsSize; j++) {
            if (i != j && strstr(words[j], words[i]) != NULL) {
                ans[(*returnSize)++] = words[i];
                break;
            }
        }
    }

    return ans;
}