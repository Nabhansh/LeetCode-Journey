long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b;
}

int possible(long long t,
             long long d1, long long d2,
             long long r1, long long r2,
             long long L)
{
    long long available1 = t - t / r1;
    long long available2 = t - t / r2;
    long long totalAvailable = t - t / L;

    return available1 >= d1 &&
           available2 >= d2 &&
           totalAvailable >= d1 + d2;
}

long long minimumTime(int* d, int dSize, int* r, int rSize)
{
    long long d1 = d[0];
    long long d2 = d[1];

    long long r1 = r[0];
    long long r2 = r[1];

    long long L = lcm(r1, r2);

    long long low = 1;
    long long high = 2LL * (d1 + d2);

    while (low < high)
    {
        long long mid = low + (high - low) / 2;

        if (possible(mid, d1, d2, r1, r2, L))
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}