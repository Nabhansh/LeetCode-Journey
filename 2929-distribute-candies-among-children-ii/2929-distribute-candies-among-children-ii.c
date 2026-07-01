long long C2(long long x) {
    if (x < 2)
        return 0;
    return x * (x - 1) / 2;
}

long long distributeCandies(int n, int limit) {
    long long ans = C2((long long)n + 2);

    for (int i = 1; i <= 3; i++) {
        long long rem = (long long)n - (long long)i * (limit + 1);
        long long ways = C2(rem + 2);

        if (i == 1)
            ans -= 3 * ways;
        else if (i == 2)
            ans += 3 * ways;
        else
            ans -= ways;
    }

    return ans;
}