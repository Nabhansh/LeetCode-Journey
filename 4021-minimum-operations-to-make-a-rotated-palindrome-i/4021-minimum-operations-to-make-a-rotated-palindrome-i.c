#include <string.h>
#include <stdlib.h>

int minOperations(char* s) {
    int n = strlen(s);
    int ans = 1000000000;

    for (int k = 0; k < n; k++) {
        int cur = k;

        for (int i = 0, j = n - 1; i < j; i++, j--) {
            int a = s[(i + k) % n] - 'a';
            int b = s[(j + k) % n] - 'a';
            int d = abs(a - b);

            cur += d < 26 - d ? d : 26 - d;
        }

        if (cur < ans)
            ans = cur;
    }

    return ans;
}