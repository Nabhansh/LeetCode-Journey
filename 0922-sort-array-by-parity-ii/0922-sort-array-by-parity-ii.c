int* sortArrayByParityII(int* nums, int numsSize, int* returnSize) {
    int even = 0;
    int odd = 1;

    while (even < numsSize && odd < numsSize) {
        while (even < numsSize && nums[even] % 2 == 0) {
            even += 2;
        }

        while (odd < numsSize && nums[odd] % 2 != 0) {
            odd += 2;
        }

        if (even < numsSize && odd < numsSize) {
            int temp = nums[even];
            nums[even] = nums[odd];
            nums[odd] = temp;

            even += 2;
            odd += 2;
        }
    }

    *returnSize = numsSize;
    return nums;
}