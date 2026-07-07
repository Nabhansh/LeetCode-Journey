long long sumAndMultiply(int n) {
    if (n == 0) {
        return 0;
    }

    int arr[10];
    int size = 0;

    while (n > 0) {
        int d = n % 10;
        if (d > 0) {
            arr[size++] = d;
        }
        n /= 10;
    }

    long long sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    long long value = 0;
    long long tens = 1;

    for (int i = 0; i < size; i++) {
        value += (long long)arr[i] * tens;
        tens *= 10;
    }

    return value * sum;
}