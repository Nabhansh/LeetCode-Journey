char** largestString(int* nums, int numsSize, int* returnSize) {
    char **ans = malloc(numsSize * sizeof(char*));
    *returnSize = numsSize;

    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        int temp = x;
        int len = 0;

        while (temp) {
            len++;
            temp >>= 1;
        }

        ans[i] = malloc((len + 1) * sizeof(char));

        int k = 0;

        for (int b = 25; b >= 0; b--) {
            int p = 1 << b;

            while (x >= p) {
                ans[i][k++] = 'a' + b;
                x -= p;
            }
        }

        ans[i][k] = '\0';
    }

    return ans;
}