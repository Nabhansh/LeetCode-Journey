int subtractProductAndSum(int n) {

    int product = 1;
    int sum = 0;

    while (n) {
        int d = n % 10;
        product *= d;
        sum += d;
        n /= 10;
    }

    return product - sum;
}