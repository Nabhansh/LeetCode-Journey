long long count(long long n, int x) {
    long long res = 0;

    for (int i = x - 1; i < 60; i += x) {
        long long len = 1LL << i;
        long long cycle = len << 1;

        res += ((n + 1) / cycle) * len;

        long long rem = (n + 1) % cycle;
        if (rem > len)
            res += rem - len;
    }

    return res;
}

long long findMaximumNumber(long long k, int x) {
    long long lo = 0;
    long long hi = 1000000000000000LL;

    while (lo < hi) {
        long long mid = lo + (hi - lo + 1) / 2;

        if (count(mid, x) <= k)
            lo = mid;
        else
            hi = mid - 1;
    }

    return lo;
}