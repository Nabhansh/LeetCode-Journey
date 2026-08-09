#include <stdlib.h>
#include <stdint.h>

#define WORDS 10

int maxWeight(
    int n,
    int** edges,
    int edgesSize,
    int* edgesColSize,
    int k,
    int t
)
{
    /*
        dp[v] stores all possible path sums
        for paths ending at node v.

        Since t <= 600:
        600 bits / 64 = 10 uint64_t words.
    */

    uint64_t (*dp)[WORDS] =
        calloc(n, sizeof(uint64_t[WORDS]));

    uint64_t (*next)[WORDS] =
        calloc(n, sizeof(uint64_t[WORDS]));

    /*
        With 0 edges, every node can be
        the starting node with sum = 0.
    */

    for (int v = 0; v < n; v++)
        dp[v][0] = 1ULL;

    /*
        Add exactly one edge at each iteration.
    */

    for (int step = 0; step < k; step++)
    {
        /*
            Clear next.
        */

        for (int v = 0; v < n; v++)
        {
            for (int w = 0; w < WORDS; w++)
                next[v][w] = 0;
        }

        /*
            Process every edge:

                u --weight--> v

            If dp[u] contains sum S,
            then next[v] contains S + weight.
        */

        for (int e = 0; e < edgesSize; e++)
        {
            int u = edges[e][0];
            int v = edges[e][1];
            int weight = edges[e][2];

            int wordShift = weight / 64;
            int bitShift = weight % 64;

            for (int w = 0; w < WORDS; w++)
            {
                uint64_t bits = dp[u][w];

                if (bits == 0)
                    continue;

                int dest = w + wordShift;

                if (dest >= WORDS)
                    continue;

                /*
                    Shift the bitset by 'weight'.
                */

                next[v][dest] |= bits << bitShift;

                /*
                    Bits that overflow into the
                    next 64-bit word.
                */

                if (bitShift != 0 && dest + 1 < WORDS)
                {
                    next[v][dest + 1] |=
                        bits >> (64 - bitShift);
                }
            }
        }

        /*
            We only care about sums < t.

            Remove bits >= t.
        */

        int lastBit = (t - 1) % 64;
        int lastWord = (t - 1) / 64;

        for (int v = 0; v < n; v++)
        {
            for (int w = lastWord + 1; w < WORDS; w++)
                next[v][w] = 0;

            if (lastBit != 63)
            {
                uint64_t mask =
                    (1ULL << (lastBit + 1)) - 1;

                next[v][lastWord] &= mask;
            }
        }

        /*
            Swap dp and next.
        */

        uint64_t (*temp)[WORDS] = dp;
        dp = next;
        next = temp;
    }

    /*
        Find the largest possible sum < t.
    */

    int answer = -1;

    for (int sum = t - 1; sum >= 0; sum--)
    {
        int word = sum / 64;
        int bit = sum % 64;

        uint64_t mask = 1ULL << bit;

        for (int v = 0; v < n; v++)
        {
            if (dp[v][word] & mask)
            {
                answer = sum;
                goto DONE;
            }
        }
    }

DONE:

    free(dp);
    free(next);

    return answer;
}