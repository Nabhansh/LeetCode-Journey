#include <stdlib.h>
#include <string.h>

char* stringHash(char* s, int k) {
    int n = strlen(s);
    int m = n / k;

    char *ans = (char *)malloc((m + 1) * sizeof(char));
    int idx = 0;

    for (int i = 0; i < n; i += k) {
        int sum = 0;
        for (int j = i; j < i + k; j++) {
            sum += s[j] - 'a';
        }
        ans[idx++] = 'a' + (sum % 26);
    }

    ans[idx] = '\0';
    return ans;
}