#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int cmp(const void *a, const void *b) {
    return strcmp(*(char * const *)a, *(char * const *)b);
}

bool reportSpam(char** message, int messageSize,
                char** bannedWords, int bannedWordsSize) {

    qsort(bannedWords, bannedWordsSize, sizeof(char *), cmp);

    int cnt = 0;

    for (int i = 0; i < messageSize; i++) {
        char **res = (char **)bsearch(
            &message[i],
            bannedWords,
            bannedWordsSize,
            sizeof(char *),
            cmp
        );

        if (res != NULL) {
            cnt++;
            if (cnt >= 2)
                return true;
        }
    }

    return false;
}