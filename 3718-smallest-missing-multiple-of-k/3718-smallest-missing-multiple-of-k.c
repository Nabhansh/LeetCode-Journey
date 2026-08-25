int missingMultiple(int* nums, int numsSize, int k) {
    int i = 1;
    while (1) {
        if (i % k == 0) {
            int found = 0;
            for (int j = 0; j < numsSize; j++) {
                if (nums[j] == i) {
                    found = 1;
                    break;
                }
            }
            if (!found) return i;
        }
        i++;
    }
}