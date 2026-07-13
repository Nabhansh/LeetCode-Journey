#include <stdlib.h>

bool* isArraySpecial(
    int* nums,
    int numsSize,
    int** queries,
    int queriesSize,
    int* queriesColSize,
    int* returnSize
) {
    int* prefix = (int*)malloc(numsSize * sizeof(int));

    prefix[0] = 0;

    for (int i = 1; i < numsSize; i++) {
        prefix[i] = prefix[i - 1];

        if ((nums[i] % 2) == (nums[i - 1] % 2)) {
            prefix[i]++;
        }
    }

    bool* answer = (bool*)malloc(queriesSize * sizeof(bool));

    for (int i = 0; i < queriesSize; i++) {
        int left = queries[i][0];
        int right = queries[i][1];

        answer[i] = (prefix[right] - prefix[left] == 0);
    }

    free(prefix);

    *returnSize = queriesSize;
    return answer;
}