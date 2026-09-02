#include <stdlib.h>

long long minInitialStrength(
    int* monsters,
    int monstersSize,
    int** boosts,
    int boostsSize,
    int* boostsColSize
) {
    long long* diff = calloc(monstersSize + 1, sizeof(long long));

    for (int i = 0; i < boostsSize; i++) {
        int l = boosts[i][0];
        int r = boosts[i][1];
        int v = boosts[i][2];

        diff[l] += v;
        diff[r + 1] -= v;
    }

    long long bonus = 0;
    long long defeated = 0;
    long long answer = 0;

    for (int i = 0; i < monstersSize; i++) {
        bonus += diff[i];

        if (bonus < monsters[i]) {
            long long required = defeated + monsters[i] - bonus;

            if (required > answer)
                answer = required;
        }

        defeated += monsters[i];
    }

    free(diff);

    return answer;
}