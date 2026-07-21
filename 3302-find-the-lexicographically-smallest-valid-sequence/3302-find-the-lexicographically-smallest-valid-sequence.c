#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int* validSequence(char* word1, char* word2, int* returnSize) {
    int n = strlen(word1);
    int m = strlen(word2);

    int *ans = (int *)malloc(sizeof(int) * m);
    int *last = (int *)malloc(sizeof(int) * m);

    for (int i = 0; i < m; i++)
        last[i] = -1;

    int i = n - 1;
    int j = m - 1;

    while (i >= 0 && j >= 0) {
        if (word1[i] == word2[j]) {
            last[j] = i;
            j--;
        }
        i--;
    }

    bool canSkip = true;
    j = 0;

    for (i = 0; i < n && j < m; i++) {
        if (word1[i] == word2[j]) {
            ans[j++] = i;
        } else if (canSkip &&
                  (j == m - 1 || i < last[j + 1])) {
            canSkip = false;
            ans[j++] = i;
        }
    }

    free(last);

    if (j == m) {
        *returnSize = m;
        return ans;
    }

    free(ans);
    *returnSize = 0;
    return NULL;
}