#include <stdlib.h>
#include <string.h>

typedef struct {
    char word[25];
    int cnt;
} Node;

char** uncommonFromSentences(char* s1, char* s2, int* returnSize) {
    Node arr[400];
    int sz = 0;

    char *copy1 = strdup(s1);
    char *copy2 = strdup(s2);

    char *tok = strtok(copy1, " ");
    while (tok) {
        int i;
        for (i = 0; i < sz; i++) {
            if (strcmp(arr[i].word, tok) == 0) {
                arr[i].cnt++;
                break;
            }
        }
        if (i == sz) {
            strcpy(arr[sz].word, tok);
            arr[sz].cnt = 1;
            sz++;
        }
        tok = strtok(NULL, " ");
    }

    tok = strtok(copy2, " ");
    while (tok) {
        int i;
        for (i = 0; i < sz; i++) {
            if (strcmp(arr[i].word, tok) == 0) {
                arr[i].cnt++;
                break;
            }
        }
        if (i == sz) {
            strcpy(arr[sz].word, tok);
            arr[sz].cnt = 1;
            sz++;
        }
        tok = strtok(NULL, " ");
    }

    char **ans = (char **)malloc(sz * sizeof(char *));
    *returnSize = 0;

    for (int i = 0; i < sz; i++) {
        if (arr[i].cnt == 1) {
            ans[*returnSize] = (char *)malloc(strlen(arr[i].word) + 1);
            strcpy(ans[*returnSize], arr[i].word);
            (*returnSize)++;
        }
    }

    free(copy1);
    free(copy2);

    return ans;
}