int reverseNum(int n) {
    int r = 0;
    while (n > 0) {
        r = r * 10 + n % 10;
        n /= 10;
    }
    return r;
}

int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int sumOfPrimesInRange(int n) {
    int r = reverseNum(n);
    int low = n < r ? n : r;
    int high = n > r ? n : r;
    int sum = 0;

    for (int i = low; i <= high; i++) {
        if (isPrime(i))
            sum += i;
    }

    return sum;
}