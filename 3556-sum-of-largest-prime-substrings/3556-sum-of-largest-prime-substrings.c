#include <stdlib.h>

int isPrime(long long x)
{
    if (x < 2)
        return 0;

    if (x == 2)
        return 1;

    if (x % 2 == 0)
        return 0;

    for (long long i = 3; i * i <= x; i += 2)
    {
        if (x % i == 0)
            return 0;
    }

    return 1;
}

long long sumOfLargestPrimes(char *s)
{
    int n = 0;

    while (s[n] != '\0')
        n++;

    long long best1 = -1;
    long long best2 = -1;
    long long best3 = -1;

    for (int i = 0; i < n; i++)
    {
        long long num = 0;

        for (int j = i; j < n; j++)
        {
            num = num * 10 + (s[j] - '0');

            if (!isPrime(num))
                continue;

            if (num == best1 ||
                num == best2 ||
                num == best3)
            {
                continue;
            }

            if (num > best1)
            {
                best3 = best2;
                best2 = best1;
                best1 = num;
            }
            else if (num > best2)
            {
                best3 = best2;
                best2 = num;
            }
            else if (num > best3)
            {
                best3 = num;
            }
        }
    }

    long long answer = 0;

    if (best1 != -1)
        answer += best1;

    if (best2 != -1)
        answer += best2;

    if (best3 != -1)
        answer += best3;

    return answer;
}