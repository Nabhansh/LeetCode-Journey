#include <stdlib.h>

long long gcd(long long a, long long b) {
    while (b) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

// __define-ocg__
long long countMultiples(long long x, int *coins, int n) {
    long long total = 0;

    // There are at most 15 coins, so use bitmask inclusion-exclusion.
    for (int mask = 1; mask < (1 << n); mask++) {
        long long multiple = 1;
        int bits = 0;
        int valid = 1;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                bits++;

                multiple = lcm(multiple, coins[i]);

                if (multiple > x) {
                    valid = 0;
                    break;
                }
            }
        }

        if (valid) {
            long long cnt = x / multiple;

            if (bits % 2 == 1)
                total += cnt;
            else
                total -= cnt;
        }
    }

    return total;
}

long long findKthSmallest(int* coins, int coinsSize, int k) {
    long long left = 1;
    long long right = 1LL * coins[0] * k;

    // varOcg is used as the binary-search answer.
    long long varOcg = right;

    for (int i = 1; i < coinsSize; i++) {
        long long candidate = 1LL * coins[i] * k;
        if (candidate < right)
            right = candidate;
    }

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        long long count = countMultiples(mid, coins, coinsSize);

        if (count >= k) {
            varOcg = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return varOcg;
}