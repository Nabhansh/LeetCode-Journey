int countMatchingSubarrays(int* nums, int numsSize, int* pattern, int patternSize) {
    int ans = 0;

    for (int i = 0; i + patternSize < numsSize; i++) {
        int ok = 1;

        for (int j = 0; j < patternSize; j++) {
            if (pattern[j] == 1) {
                if (!(nums[i + j + 1] > nums[i + j])) {
                    ok = 0;
                    break;
                }
            } else if (pattern[j] == 0) {
                if (!(nums[i + j + 1] == nums[i + j])) {
                    ok = 0;
                    break;
                }
            } else { // pattern[j] == -1
                if (!(nums[i + j + 1] < nums[i + j])) {
                    ok = 0;
                    break;
                }
            }
        }

        if (ok)
            ans++;
    }

    return ans;
}