int* decompressRLElist(int* nums, int numsSize, int* returnSize) {

    *returnSize = 0;

    for (int i = 0; i < numsSize; i += 2)
        *returnSize += nums[i];

    int *ans = (int *)malloc((*returnSize) * sizeof(int));

    int idx = 0;

    for (int i = 0; i < numsSize; i += 2) {
        int freq = nums[i];
        int val = nums[i + 1];

        while (freq--)
            ans[idx++] = val;
    }

    return ans;
}