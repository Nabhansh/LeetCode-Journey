#include <stdint.h>

int countPermutations(int* complexity, int complexitySize)
{
    const long long MOD = 1000000007LL;

    // Every other computer must have
    // greater complexity than computer 0
    for (int i = 1; i < complexitySize; i++)
    {
        if (complexity[i] <= complexity[0])
            return 0;
    }

    // Answer = (n - 1)!
    long long ans = 1;

    for (int i = 1; i < complexitySize; i++)
    {
        ans = (ans * i) % MOD;
    }

    return (int)ans;
}