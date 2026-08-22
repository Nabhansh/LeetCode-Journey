#include <stdbool.h>

bool checkDivisibility(int n) {
    int sum = 0, product = 1, temp = n;

    while (temp > 0) {
        int digit = temp % 10;
        sum += digit;
        product *= digit;
        temp /= 10;
    }

    int total = sum + product;
    return (n % total == 0);
}