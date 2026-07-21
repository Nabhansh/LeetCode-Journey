#define MOD 1000000007LL

int numPrimeArrangements(int n) {
    int prime = 0;

    for (int i = 2; i <= n; i++) {
        int ok = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                ok = 0;
                break;
            }
        }
        if (ok) prime++;
    }

    long long ans = 1;

    for (int i = 2; i <= prime; i++)
        ans = (ans * i) % MOD;

    for (int i = 2; i <= n - prime; i++)
        ans = (ans * i) % MOD;

    return (int)ans;
}