long long MOD = 1000000007LL;

long long modPow(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

int stringCount(int n) {
    long long all = modPow(26, n);

    long long a = modPow(25, n);                       // no 'l'
    long long b = modPow(25, n);                       // no 't'
    long long c = (modPow(25, n) + (long long)n * modPow(25, n - 1)) % MOD; // <2 'e'

    long long ab = modPow(24, n);                      // no 'l', no 't'
    long long ac = (modPow(24, n) + (long long)n * modPow(24, n - 1)) % MOD; // no 'l', <2 'e'
    long long bc = (modPow(24, n) + (long long)n * modPow(24, n - 1)) % MOD; // no 't', <2 'e'

    long long abc = (modPow(23, n) + (long long)n * modPow(23, n - 1)) % MOD; // no 'l', no 't', <2 'e'

    long long ans = (all - a - b - c + ab + ac + bc - abc) % MOD;
    if (ans < 0) ans += MOD;
    return (int)ans;
}