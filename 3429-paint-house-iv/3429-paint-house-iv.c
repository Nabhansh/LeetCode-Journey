#include <stdlib.h>
#include <limits.h>

typedef long long ll;

long long minCost(int n, int** cost, int costSize, int* costColSize) {
    const ll INF = (1LL << 60);

    ll dp[3][3], ndp[3][3];

    for (int a = 0; a < 3; a++)
        for (int b = 0; b < 3; b++)
            dp[a][b] = 0;

    for (int l = 0, r = n - 1; l < r; l++, r--) {

        for (int a = 0; a < 3; a++)
            for (int b = 0; b < 3; b++)
                ndp[a][b] = INF;

        for (int lc = 0; lc < 3; lc++) {
            for (int rc = 0; rc < 3; rc++) {

                if (lc == rc)
                    continue;

                ll add = (ll)cost[l][lc] + cost[r][rc];

                if (l == 0) {
                    if (add < ndp[lc][rc])
                        ndp[lc][rc] = add;
                    continue;
                }

                for (int pl = 0; pl < 3; pl++) {
                    if (pl == lc)
                        continue;

                    for (int pr = 0; pr < 3; pr++) {
                        if (pr == rc)
                            continue;

                        if (dp[pl][pr] == INF)
                            continue;

                        ll cur = dp[pl][pr] + add;

                        if (cur < ndp[lc][rc])
                            ndp[lc][rc] = cur;
                    }
                }
            }
        }

        for (int a = 0; a < 3; a++)
            for (int b = 0; b < 3; b++)
                dp[a][b] = ndp[a][b];
    }

    ll ans = INF;

    for (int a = 0; a < 3; a++)
        for (int b = 0; b < 3; b++)
            if (dp[a][b] < ans)
                ans = dp[a][b];

    return ans;
}