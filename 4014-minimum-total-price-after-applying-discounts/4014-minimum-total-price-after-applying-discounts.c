#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

double minPrice(int* prices, int pricesSize, int* discounts, int discountsSize) {
    qsort(prices, pricesSize, sizeof(int), cmp);
    qsort(discounts, discountsSize, sizeof(int), cmp);

    int i = pricesSize - 1;
    int j = discountsSize - 1;
    double ans = 0.0;

    while (i >= 0 && j >= 0) {
        ans += prices[i] * (100 - discounts[j]) / 100.0;
        i--;
        j--;
    }

    while (i >= 0) {
        ans += prices[i];
        i--;
    }

    return ans;
}