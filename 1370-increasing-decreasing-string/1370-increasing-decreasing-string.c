#include <stdlib.h>
#include <string.h>

char* sortString(char* s) {
    int cnt[26] = {0};
    int n = strlen(s);

    for (int i = 0; i < n; i++)
        cnt[s[i] - 'a']++;

    char *ans = (char *)malloc(n + 1);
    int idx = 0;

    while (idx < n) {
        for (int i = 0; i < 26; i++)
            if (cnt[i]) {
                ans[idx++] = 'a' + i;
                cnt[i]--;
            }

        for (int i = 25; i >= 0; i--)
            if (cnt[i]) {
                ans[idx++] = 'a' + i;
                cnt[i]--;
            }
    }

    ans[n] = '\0';
    return ans;
}