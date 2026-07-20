#include <stdlib.h>
#include <string.h>

char* defangIPaddr(char* address) {
    int n = strlen(address);
    char *ans = (char *)malloc(n + 7);   // each '.' adds 2 chars

    int j = 0;

    for (int i = 0; i < n; i++) {
        if (address[i] == '.') {
            ans[j++] = '[';
            ans[j++] = '.';
            ans[j++] = ']';
        } else {
            ans[j++] = address[i];
        }
    }

    ans[j] = '\0';
    return ans;
}