#include <stdlib.h>
#include <stdint.h>

typedef struct {
    int x;
    int b;
    int i;
    int used;
} Entry;

unsigned long long hashKey(int x, int b)
{
    unsigned long long k =
        ((unsigned long long)(unsigned int)x << 32) |
        (unsigned int)b;

    k ^= k >> 33;
    k *= 0xff51afd7ed558ccdULL;
    k ^= k >> 33;
    k *= 0xc4ceb9fe1a85ec53ULL;
    k ^= k >> 33;

    return k;
}

int maxBalancedSubarray(int* nums, int numsSize)
{
    int size = 1;

    while (size < numsSize * 4)
        size <<= 1;

    Entry* table = calloc(size, sizeof(Entry));

    int ans = 0;
    int x = 0;
    int b = 0;

    unsigned long long h = hashKey(0, 0);
    int p = h & (size - 1);

    table[p].used = 1;
    table[p].x = 0;
    table[p].b = 0;
    table[p].i = -1;

    for (int i = 0; i < numsSize; i++)
    {
        x ^= nums[i];

        if (nums[i] % 2 == 0)
            b++;
        else
            b--;

        h = hashKey(x, b);
        p = h & (size - 1);

        while (table[p].used)
        {
            if (table[p].x == x && table[p].b == b)
            {
                int len = i - table[p].i;

                if (len > ans)
                    ans = len;

                break;
            }

            p = (p + 1) & (size - 1);
        }

        if (!table[p].used)
        {
            table[p].used = 1;
            table[p].x = x;
            table[p].b = b;
            table[p].i = i;
        }
    }

    free(table);
    return ans;
}