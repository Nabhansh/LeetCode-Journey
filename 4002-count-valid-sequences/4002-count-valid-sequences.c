#include <stdint.h>

#define MOD 1000000007LL
#define MAXN 500001

long long fact[MAXN];
long long invFact[MAXN];

long long power(long long a, long long b) {
    long long res = 1;

    while (b) {
        if (b & 1)
            res = res * a % MOD;

        a = a * a % MOD;
        b >>= 1;
    }

    return res;
}

long long comb(int n, int r) {
    if (r < 0 || r > n)
        return 0;

    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

int countValidSequences(int n, int k) {
    static int initialized = 0;

    if (!initialized) {
        fact[0] = 1;

        for (int i = 1; i < MAXN; i++)
            fact[i] = fact[i - 1] * i % MOD;

        invFact[MAXN - 1] = power(fact[MAXN - 1], MOD - 2);

        for (int i = MAXN - 1; i > 0; i--)
            invFact[i - 1] = invFact[i] * i % MOD;

        initialized = 1;
    }

    long long ans = comb(n - 1, k - 1);

    if ((n + k) % 2 == 0) {
        ans -= comb((n + k) / 2 - 1, k - 1);
        ans = (ans + MOD) % MOD;
    }

    return (int)ans;
}