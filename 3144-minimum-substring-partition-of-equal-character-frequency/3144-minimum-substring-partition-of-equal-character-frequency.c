#include <string.h>
#include <limits.h>

int minimumSubstringsInPartition(char* s) {
    int n = strlen(s);
    int dp[n + 1];

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = INT_MAX;

        int freq[26] = {0};

        for (int j = i - 1; j >= 0; j--) {
            freq[s[j] - 'a']++;

            int commonFreq = 0;
            int balanced = 1;

            for (int k = 0; k < 26; k++) {
                if (freq[k] > 0) {
                    if (commonFreq == 0) {
                        commonFreq = freq[k];
                    } else if (freq[k] != commonFreq) {
                        balanced = 0;
                        break;
                    }
                }
            }

            if (balanced && dp[j] != INT_MAX) {
                int candidate = dp[j] + 1;

                if (candidate < dp[i]) {
                    dp[i] = candidate;
                }
            }
        }
    }

    return dp[n];
}