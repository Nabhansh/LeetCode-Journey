int isPrime(int x) {
    if (x < 2) return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return 0;
    }
    return 1;
}

int countPrimeSetBits(int left, int right) {
    int ans = 0;

    for (int num = left; num <= right; num++) {
        int x = num;
        int bits = 0;

        while (x) {
            bits += x & 1;
            x >>= 1;
        }

        if (isPrime(bits))
            ans++;
    }

    return ans;
}