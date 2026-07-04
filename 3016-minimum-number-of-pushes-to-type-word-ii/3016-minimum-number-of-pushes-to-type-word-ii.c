#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int minimumPushes(char *word) {
    int cnt[26] = {0};

    for (int i = 0; word[i]; i++)
        cnt[word[i] - 'a']++;

    qsort(cnt, 26, sizeof(int), cmp);

    int ans = 0;

    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 0) break;
        ans += cnt[i] * (i / 8 + 1);
    }

    return ans;
}