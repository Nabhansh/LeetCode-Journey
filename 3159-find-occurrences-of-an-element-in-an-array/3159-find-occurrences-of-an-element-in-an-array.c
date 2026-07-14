int* occurrencesOfElement(int* nums, int numsSize, int* queries,
                          int queriesSize, int x, int* returnSize) {
    
    // Store indices where x occurs
    int* positions = (int*)malloc(numsSize * sizeof(int));
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == x) {
            positions[count++] = i;
        }
    }

    // Create answer array
    int* answer = (int*)malloc(queriesSize * sizeof(int));

    for (int i = 0; i < queriesSize; i++) {
        int k = queries[i];

        if (k <= count) {
            answer[i] = positions[k - 1];
        } else {
            answer[i] = -1;
        }
    }

    free(positions);

    *returnSize = queriesSize;
    return answer;
}