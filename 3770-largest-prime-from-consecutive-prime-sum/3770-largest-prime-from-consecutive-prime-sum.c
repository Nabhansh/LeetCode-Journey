#include <stdlib.h>

int largestPrime(int n) {
    if (n < 2)
        return 0;

    char *prime = (char *)malloc((n + 1) * sizeof(char));

    for (int i = 0; i <= n; i++)
        prime[i] = 1;

    prime[0] = prime[1] = 0;

    for (int i = 2; (long long)i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i)
                prime[j] = 0;
        }
    }

    int sum = 0;
    int ans = 0;

    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            sum += i;
            if (sum > n)
                break;
            if (prime[sum])
                ans = sum;
        }
    }

    free(prime);
    return ans;
}