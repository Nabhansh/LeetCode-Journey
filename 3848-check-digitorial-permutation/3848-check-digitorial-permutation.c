bool isDigitorialPermutation(int n) {
    int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    int a[10] = {0};
    int b[10] = {0};
    int sum = 0;
    int x = n;

    while (x > 0) {
        sum += fact[x % 10];
        x /= 10;
    }

    x = n;
    while (x > 0) {
        a[x % 10]++;
        x /= 10;
    }

    while (sum > 0) {
        b[sum % 10]++;
        sum /= 10;
    }

    for (int i = 0; i < 10; i++)
        if (a[i] != b[i])
            return false;

    return true;
}