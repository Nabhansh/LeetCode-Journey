#include <stdlib.h>

char* generateTheString(int n) {
    char *ans = (char *)malloc(n + 1);

    if (n % 2 == 1) {
        for (int i = 0; i < n; i++)
            ans[i] = 'a';
    } else {
        for (int i = 0; i < n - 1; i++)
            ans[i] = 'a';
        ans[n - 1] = 'b';
    }

    ans[n] = '\0';
    return ans;
}