#include <stdlib.h>
#include <string.h>

char** findOcurrences(char* text, char* first, char* second, int* returnSize) {
    char *copy = strdup(text);

    char **words = malloc(1000 * sizeof(char *));
    int n = 0;

    char *token = strtok(copy, " ");
    while (token) {
        words[n++] = token;
        token = strtok(NULL, " ");
    }

    char **ans = malloc(n * sizeof(char *));
    *returnSize = 0;

    for (int i = 0; i + 2 < n; i++) {
        if (strcmp(words[i], first) == 0 &&
            strcmp(words[i + 1], second) == 0) {
            ans[(*returnSize)++] = strdup(words[i + 2]);
        }
    }

    free(words);
    free(copy);
    return ans;
}