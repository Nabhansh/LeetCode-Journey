#include <stdlib.h>
#include <string.h>

char* shortestBeautifulSubstring(char* s, int k) {
    int n = strlen(s);
    int left = 0, ones = 0;
    int bestLeft = -1;
    int minLen = n + 1;

    for (int right = 0; right < n; right++) {
        if (s[right] == '1')
            ones++;

        while (ones == k) {
            int len = right - left + 1;

            if (len < minLen) {
                minLen = len;
                bestLeft = left;
            } else if (len == minLen && bestLeft != -1 &&
                       strncmp(s + left, s + bestLeft, minLen) < 0) {
                bestLeft = left;
            }

            if (s[left] == '1')
                ones--;
            left++;
        }
    }

    if (bestLeft == -1) {
        char *ans = (char *)malloc(1);
        ans[0] = '\0';
        return ans;
    }

    char *ans = (char *)malloc(minLen + 1);
    strncpy(ans, s + bestLeft, minLen);
    ans[minLen] = '\0';

    return ans;
}