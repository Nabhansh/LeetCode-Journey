#include <stdbool.h>
#include <stdlib.h>

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    *returnSize = candiesSize;

    bool* ans = (bool*)malloc(candiesSize * sizeof(bool));

    int max = candies[0];
    for (int i = 1; i < candiesSize; i++) {
        if (candies[i] > max)
            max = candies[i];
    }

    for (int i = 0; i < candiesSize; i++) {
        ans[i] = (candies[i] + extraCandies >= max);
    }

    return ans;
}