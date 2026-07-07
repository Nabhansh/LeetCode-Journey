#include <string.h>
#include <limits.h>

int minimumDeletions(char* word, int k) {
    int cnt[26] = {0};

    for (int i = 0; word[i]; i++)
        cnt[word[i] - 'a']++;

    int ans = INT_MAX;

    for (int i = 0; i < 26; i++) {
        int minFreq = cnt[i];
        int del = 0;

        for (int j = 0; j < 26; j++) {
            if (cnt[j] == 0)
                continue;

            if (cnt[j] < minFreq)
                del += cnt[j];
            else if (cnt[j] > minFreq + k)
                del += cnt[j] - (minFreq + k);
        }

        if (del < ans)
            ans = del;
    }

    return ans;
}