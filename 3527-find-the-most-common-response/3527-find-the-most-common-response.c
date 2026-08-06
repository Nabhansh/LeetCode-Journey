#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpstr(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

char* findCommonResponse(char*** responses, int n, int* responsesColSize) {
    char* allWords[1000000];
    int tot = 0;

    for (int i = 0; i < n; i++) {
        int n = responsesColSize[i];
        char* temp[1000];
        int ts = 0;

        for (int j = 0; j < n; j++) {
            temp[ts++] = responses[i][j];
        }
        qsort(temp, ts, sizeof(char*), cmpstr);

        char* last = NULL;
        for (int j = 0; j < ts; j++) {
            if (last != NULL && strcmp(last, temp[j]) == 0)
                continue;
            last = temp[j];
            allWords[tot++] = temp[j];
        }
    }

    qsort(allWords, tot, sizeof(char*), cmpstr);

    char* bestWord = allWords[0];
    int bestCount = 1;
    int currCount = 1;

    for (int i = 1; i < tot; i++) {
        if (strcmp(allWords[i], allWords[i - 1]) == 0) {
            currCount++;
        } else {
            currCount = 1;
        }
        if (currCount > bestCount ||
            (currCount == bestCount && strcmp(allWords[i], bestWord) < 0)) {
            bestCount = currCount;
            bestWord = allWords[i];
        }
    }

    char* res = (char*)malloc(11 * sizeof(char));
    strcpy(res, bestWord);
    return res;
}