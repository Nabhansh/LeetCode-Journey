#include <stdlib.h>

typedef struct {
    int factor;
    int price;
    int gain;
} Item;

int compareItems(const void* a, const void* b) {
    Item* x = (Item*)a;
    Item* y = (Item*)b;

    if (x->price < y->price)
        return -1;
    if (x->price > y->price)
        return 1;

    return 0;
}

int maximumSaleItems(int** items, int itemsSize, int* itemsColSize, int budget) {
    int n = itemsSize;
    int minPrice = 1000000000;
    int maxFactor = 0;

    for (int i = 0; i < n; i++) {
        if (items[i][1] < minPrice)
            minPrice = items[i][1];

        if (items[i][0] > maxFactor)
            maxFactor = items[i][0];
    }

    int* freq = calloc(maxFactor + 1, sizeof(int));

    for (int i = 0; i < n; i++)
        freq[items[i][0]]++;

    for (int i = 1; i <= maxFactor; i++) {
        if (freq[i] == 0)
            continue;

        for (int j = i * 2; j <= maxFactor; j += i)
            freq[i] += freq[j];
    }

    Item* arr = malloc(n * sizeof(Item));

    for (int i = 0; i < n; i++) {
        arr[i].factor = items[i][0];
        arr[i].price = items[i][1];
        arr[i].gain = freq[items[i][0]] - 1;
    }

    qsort(arr, n, sizeof(Item), compareItems);

    long long total = 0;
    long long money = budget;

    for (int i = 0; i < n; i++) {
        int price = arr[i].price;
        int gain = arr[i].gain;

        if (gain <= 0)
            continue;

        if ((long long)price > 2LL * minPrice)
            continue;

        long long canBuy = money / price;

        if (canBuy > gain)
            canBuy = gain;

        total += 2LL * canBuy;
        money -= canBuy * price;
    }

    total += money / minPrice;

    free(freq);
    free(arr);

    return (int)total;
}