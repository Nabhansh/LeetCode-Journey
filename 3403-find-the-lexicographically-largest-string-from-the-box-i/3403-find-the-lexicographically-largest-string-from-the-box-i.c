#include <stdlib.h>
#include <string.h>

char* answerString(char* word, int numFriends) {
    if (numFriends == 1) {
        char *ans = (char *)malloc(strlen(word) + 1);
        strcpy(ans, word);
        return ans;
    }

    int n = strlen(word);
    int maxLen = n - numFriends + 1;

    char *ans = (char *)malloc(n + 1);
    ans[0] = '\0';

    for (int i = 0; i < n; i++) {
        int len = n - i;
        if (len > maxLen)
            len = maxLen;

        char *cur = (char *)malloc(len + 1);
        memcpy(cur, word + i, len);
        cur[len] = '\0';

        if (strcmp(cur, ans) > 0) {
            strcpy(ans, cur);
        }

        free(cur);
    }

    return ans;
}