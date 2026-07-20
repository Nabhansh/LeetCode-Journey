#include <limits.h>

typedef long long ll;

long long maxScore(int* a, int aSize, int* b, int bSize) {
    ll dp[5];

    for (int i = 0; i <= 4; i++)
        dp[i] = LLONG_MIN;

    dp[0] = 0;

    for (int i = 0; i < bSize; i++) {
        for (int j = 4; j >= 1; j--) {
            if (dp[j - 1] != LLONG_MIN) {
                ll val = dp[j - 1] + 1LL * a[j - 1] * b[i];
                if (val > dp[j])
                    dp[j] = val;
            }
        }
    }

    return dp[4];
}