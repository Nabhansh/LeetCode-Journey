#define MOD 1000000007LL

int maximumXorProduct(long long a, long long b, int n) {
    if (n == 0)
        return (int)((a % MOD) * (b % MOD) % MOD);

    for (long long bit = 1LL << (n - 1); bit; bit >>= 1) {
        if (((a < b ? a : b) & bit) == 0) {
            a ^= bit;
            b ^= bit;
        }
    }

    return (int)((a % MOD) * (b % MOD) % MOD);
}