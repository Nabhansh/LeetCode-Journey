#include <math.h>
#include <stdbool.h>

int nonSpecialCount(int l, int r) {
    int limit = (int)sqrt(r);
    bool prime[limit + 1];

    for (int i = 0; i <= limit; i++)
        prime[i] = true;

    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= limit; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= limit; j += i)
                prime[j] = false;
        }
    }

    int special = 0;

    for (int i = 2; i <= limit; i++) {
        if (prime[i]) {
            long long sq = 1LL * i * i;
            if (sq >= l && sq <= r)
                special++;
        }
    }

    return (r - l + 1) - special;
}