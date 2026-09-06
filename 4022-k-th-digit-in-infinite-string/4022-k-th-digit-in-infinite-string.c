long long power10(int n) {
    long long p = 1;
    while (n--) p *= 10;
    return p;
}

int kthDigit(long long k) {
    if (k <= 9) return (int)k;

    k -= 9;
    int d = 2;
    long long start = 10;

    while (1) {
        long long blocks = 9 * power10(d - 2);
        long long size = 10LL * d;
        long long total = blocks * size;

        if (k <= total) break;

        k -= total;
        d++;
        start *= 10;
    }

    long long block = start / 10 + (k - 1) / (10LL * d);
    long long pos = (k - 1) % (10LL * d);
    long long index = pos / d;

    long long num;

    if (block % 2 == 0)
        num = block * 10 + index;
    else
        num = block * 10 + 9 - index;

    char s[25];
    sprintf(s, "%lld", num);

    return s[pos % d] - '0';
}