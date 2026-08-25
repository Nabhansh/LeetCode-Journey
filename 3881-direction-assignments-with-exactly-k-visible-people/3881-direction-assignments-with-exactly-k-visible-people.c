#define MOD 1000000007LL

long long power(long long a, long long b) {
    long long result = 1;

    while (b > 0) {
        if (b & 1)
            result = result * a % MOD;

        a = a * a % MOD;
        b >>= 1;
    }

    return result;
}

int countVisiblePeople(int n, int pos, int k) {

    if (k > n - 1)
        return 0;

    long long fact[100001];
    long long invFact[100001];

    fact[0] = 1;

    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    invFact[n] = power(fact[n], MOD - 2);

    for (int i = n; i >= 1; i--) {
        invFact[i - 1] = invFact[i] * i % MOD;
    }

    long long combinations =
        fact[n - 1] *
        invFact[k] % MOD *
        invFact[n - 1 - k] % MOD;

    return (int)(2 * combinations % MOD);
}