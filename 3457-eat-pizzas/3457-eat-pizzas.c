#include <stdlib.h>

static int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

long long maxWeight(int* pizzas, int pizzasSize) {
    qsort(pizzas, pizzasSize, sizeof(int), cmp);

    int days = pizzasSize / 4;
    int odd = (days + 1) / 2;
    int even = days - odd;

    long long ans = 0;

    /* Gain from odd-numbered days (largest pizza). */
    for (int i = pizzasSize - odd; i < pizzasSize; i++) {
        ans += pizzas[i];
    }

    /* Gain from even-numbered days (second largest pizza). */
    int idx = pizzasSize - odd - 2;
    while (even--) {
        ans += pizzas[idx];
        idx -= 2;
    }

    return ans;
}