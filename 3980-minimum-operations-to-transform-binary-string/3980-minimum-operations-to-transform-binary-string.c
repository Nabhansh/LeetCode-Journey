#include <limits.h>
#include <string.h>

int minOperations(char* s1, char* s2) {
    int n = strlen(s1);
    int inf = INT_MAX / 4;
    int dp[2] = {inf, inf};

    dp[s1[0] - '0'] = 0;

    for (int i = 0; i < n; i++) {
        int next[2] = {inf, inf};

        for (int bit = 0; bit <= 1; bit++) {
            if (dp[bit] == inf) continue;

            int target = s2[i] - '0';

            if (bit == 0 || target == 1) {
                int cost = dp[bit] + (bit == 0 && target == 1);
                if (i + 1 < n) {
                    int nextBit = s1[i + 1] - '0';
                    if (cost < next[nextBit]) next[nextBit] = cost;
                } else if (cost < next[0]) {
                    next[0] = cost;
                }
            }

            if (i + 1 < n) {
                int cost = dp[bit] + 1 + (bit == 0) + (s1[i + 1] == '0') + (target == 1);
                if (cost < next[0]) next[0] = cost;
            }
        }

        dp[0] = next[0];
        dp[1] = next[1];
    }

    int ans = dp[0] < dp[1] ? dp[0] : dp[1];
    return ans == inf ? -1 : ans;
}