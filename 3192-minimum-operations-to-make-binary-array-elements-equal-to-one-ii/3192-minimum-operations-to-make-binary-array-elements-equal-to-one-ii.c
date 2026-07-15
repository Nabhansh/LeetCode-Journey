int minOperations(int* nums, int numsSize) {
    int operations = 0;

    for (int i = 0; i < numsSize; i++) {
        int current = nums[i];

        if (operations % 2 == 1) {
            current ^= 1;
        }

        if (current == 0) {
            operations++;
        }
    }

    return operations;
}