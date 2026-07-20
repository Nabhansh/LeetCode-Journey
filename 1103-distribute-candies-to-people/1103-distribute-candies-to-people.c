#include <stdlib.h>

int* distributeCandies(int candies, int num_people, int* returnSize) {
    *returnSize = num_people;
    int *ans = (int *)calloc(num_people, sizeof(int));

    int give = 1;
    int i = 0;

    while (candies > 0) {
        if (candies >= give) {
            ans[i] += give;
            candies -= give;
        } else {
            ans[i] += candies;
            candies = 0;
        }
        give++;
        i = (i + 1) % num_people;
    }

    return ans;
}