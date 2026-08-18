#include <stdbool.h>

bool isPrime(int n)
{
    if (n < 2)
        return false;

    if (n == 2)
        return true;

    if (n % 2 == 0)
        return false;

    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

bool completePrime(int num)
{
    int digits[10];
    int len = 0;
    int x = num;

    while (x)
    {
        digits[len++] = x % 10;
        x /= 10;
    }

    int prefix = 0;

    for (int i = len - 1; i >= 0; i--)
    {
        prefix = prefix * 10 + digits[i];

        if (!isPrime(prefix))
            return false;
    }

    int suffix = 0;
    int power = 1;

    for (int i = 0; i < len; i++)
    {
        suffix += digits[i] * power;

        if (!isPrime(suffix))
            return false;

        power *= 10;
    }

    return true;
}