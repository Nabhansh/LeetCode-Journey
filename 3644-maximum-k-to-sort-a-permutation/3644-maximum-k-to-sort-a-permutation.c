int sortPermutation(int* nums, int numsSize) {
    int answer = 0;
    int foundMisplaced = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != i) {
            if (!foundMisplaced) {
                answer = nums[i];
                foundMisplaced = 1;
            } else {
                answer &= nums[i];
            }
        }
    }

    return foundMisplaced ? answer : 0;
}