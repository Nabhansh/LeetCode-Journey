class Solution {
public:
    int numPrimeArrangements(int n) {
        const long long MOD = 1000000007;
        int primes = 0;

        for (int i = 2; i <= n; i++) {
            bool isPrime = true;

            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }

            if (isPrime)
                primes++;
        }

        long long ans = 1;

        for (int i = 1; i <= primes; i++)
            ans = ans * i % MOD;

        for (int i = 1; i <= n - primes; i++)
            ans = ans * i % MOD;

        return ans;
    }
};