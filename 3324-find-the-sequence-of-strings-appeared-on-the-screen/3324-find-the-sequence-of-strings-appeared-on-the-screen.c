#include <stdlib.h>
#include <string.h>

char** stringSequence(char* target, int* returnSize) {
    int n = strlen(target);

    int total = 0;
    for (int i = 0; i < n; i++)
        total += target[i] - 'a' + 1;

    char **ans = (char **)malloc(sizeof(char *) * total);

    char cur[405];
    int len = 0;
    int idx = 0;

    for (int i = 0; i < n; i++) {
        cur[len++] = 'a';
        cur[len] = '\0';

        ans[idx] = (char *)malloc(len + 1);
        strcpy(ans[idx++], cur);

        while (cur[len - 1] < target[i]) {
            cur[len - 1]++;
            ans[idx] = (char *)malloc(len + 1);
            strcpy(ans[idx++], cur);
        }
    }

    *returnSize = idx;
    return ans;
}