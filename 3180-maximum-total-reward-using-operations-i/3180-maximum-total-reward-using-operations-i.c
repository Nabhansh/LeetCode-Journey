#include <stdlib.h>

int compare(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int maxTotalReward(int* rewardValues, int rewardValuesSize) {

    qsort(rewardValues, rewardValuesSize,
          sizeof(int), compare);

    int maxReward = rewardValues[rewardValuesSize - 1];

    /*
     * Maximum possible answer is less than
     * 2 * maxReward.
     */
    int limit = 2 * maxReward;

    char* dp = (char*)calloc(limit + 1, sizeof(char));

    dp[0] = 1;

    for (int i = 0; i < rewardValuesSize; i++) {

        int reward = rewardValues[i];

        /*
         * Traverse backwards so that the same reward
         * is not reused during this iteration.
         */
        for (int total = reward - 1; total >= 0; total--) {

            if (dp[total]) {
                dp[total + reward] = 1;
            }
        }
    }

    int answer = 0;

    for (int total = limit; total >= 0; total--) {
        if (dp[total]) {
            answer = total;
            break;
        }
    }

    free(dp);

    return answer;
}