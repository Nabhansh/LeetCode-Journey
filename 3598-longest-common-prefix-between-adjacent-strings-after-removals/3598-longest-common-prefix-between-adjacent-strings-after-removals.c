#include <stdlib.h>
#include <string.h>

int lcp(char* a, char* b) {
    int i = 0;

    while (a[i] && b[i] && a[i] == b[i])
        i++;

    return i;
}

int* longestCommonPrefix(char** words, int wordsSize, int* returnSize) {
    int n = wordsSize;
    int* ans = calloc(n, sizeof(int));

    *returnSize = n;

    if (n <= 2)
        return ans;

    int m = n - 1;

    int* pair = malloc(m * sizeof(int));
    int* pre = malloc(m * sizeof(int));
    int* suf = malloc(m * sizeof(int));

    for (int i = 0; i < m; i++)
        pair[i] = lcp(words[i], words[i + 1]);

    pre[0] = pair[0];

    for (int i = 1; i < m; i++)
        pre[i] = pre[i - 1] > pair[i] ? pre[i - 1] : pair[i];

    suf[m - 1] = pair[m - 1];

    for (int i = m - 2; i >= 0; i--)
        suf[i] = suf[i + 1] > pair[i] ? suf[i + 1] : pair[i];

    for (int i = 0; i < n; i++) {
        int best = 0;

        if (i >= 2 && pre[i - 2] > best)
            best = pre[i - 2];

        if (i + 1 < m && suf[i + 1] > best)
            best = suf[i + 1];

        if (i > 0 && i + 1 < n) {
            int x = lcp(words[i - 1], words[i + 1]);
            if (x > best)
                best = x;
        }

        ans[i] = best;
    }

    free(pair);
    free(pre);
    free(suf);

    return ans;
}