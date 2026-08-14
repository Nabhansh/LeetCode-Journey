#include <stdlib.h>

long long maxProfit(int* prices, int pricesSize,
                    int* strategy, int strategySize,
                    int k)
{
    int n = pricesSize;

    long long *profitPrefix =
        malloc((n + 1) * sizeof(long long));

    long long *pricePrefix =
        malloc((n + 1) * sizeof(long long));

    profitPrefix[0] = 0;
    pricePrefix[0] = 0;

    for (int i = 0; i < n; i++)
    {
        profitPrefix[i + 1] =
            profitPrefix[i] +
            (long long)prices[i] * strategy[i];

        pricePrefix[i + 1] =
            pricePrefix[i] + prices[i];
    }

    long long answer = profitPrefix[n];
    int half = k / 2;

    for (int right = k; right <= n; right++)
    {
        int left = right - k;

        long long oldProfit =
            profitPrefix[right] -
            profitPrefix[left];

        long long newProfit =
            pricePrefix[right] -
            pricePrefix[left + half];

        long long total =
            profitPrefix[n] -
            oldProfit +
            newProfit;

        if (total > answer)
            answer = total;
    }

    free(profitPrefix);
    free(pricePrefix);

    return answer;
}