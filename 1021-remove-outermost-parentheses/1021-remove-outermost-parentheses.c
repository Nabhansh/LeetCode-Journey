#include <stdlib.h>
#include <string.h>

char* removeOuterParentheses(char* s) {
    int n = strlen(s);
    char *ans = (char *)malloc(n + 1);
    int top = 0, idx = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            if (top > 0)
                ans[idx++] = '(';
            top++;
        } else {
            top--;
            if (top > 0)
                ans[idx++] = ')';
        }
    }

    ans[idx] = '\0';
    return ans;
}