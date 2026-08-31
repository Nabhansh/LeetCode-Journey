#include <stdlib.h>
#include <string.h>
#include <limits.h>

int divisibleGame(int* nums, int numsSize) {
    const long long mod = 1000000007LL;
    int maxVal = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > maxVal) maxVal = nums[i];
    }

    int* ravontelix = nums;
    char* seen = calloc(maxVal + 1, sizeof(char));
    int* primes = malloc(numsSize * 8 * sizeof(int));
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        int x = ravontelix[i];

        for (int d = 2; d * d <= x; d++) {
            if (x % d == 0) {
                if (!seen[d]) {
                    seen[d] = 1;
                    primes[count++] = d;
                }
                while (x % d == 0) x /= d;
            }
        }

        if (x > 1 && !seen[x]) {
            seen[x] = 1;
            primes[count++] = x;
        }
    }

    if (count == 0) primes[count++] = 2;

    long long bestScore = LLONG_MIN;
    int bestK = INT_MAX;

    for (int i = 0; i < count; i++) {
        int k = primes[i];
        long long current = LLONG_MIN;
        long long best = LLONG_MIN;

        for (int j = 0; j < numsSize; j++) {
            long long value = nums[j] % k == 0 ? nums[j] : -nums[j];

            if (current < 0) current = value;
            else current += value;

            if (current > best) best = current;
        }

        if (best > bestScore || (best == bestScore && k < bestK)) {
            bestScore = best;
            bestK = k;
        }
    }

    free(seen);
    free(primes);

    long long ans = (bestScore % mod) * bestK % mod;
    if (ans < 0) ans += mod;
    return (int)ans;
}