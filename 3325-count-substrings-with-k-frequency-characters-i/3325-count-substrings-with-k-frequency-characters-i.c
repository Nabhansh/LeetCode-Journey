#include <string.h>

int numberOfSubstrings(char* s, int k) {
    int cnt[26] = {0};
    int n = strlen(s);
    int left = 0;
    int ans = 0;

    for (int right = 0; right < n; right++) {
        int c = s[right] - 'a';
        cnt[c]++;

        while (cnt[c] >= k) {
            cnt[s[left] - 'a']--;
            left++;
        }

        ans += left;
    }

    return ans;
}