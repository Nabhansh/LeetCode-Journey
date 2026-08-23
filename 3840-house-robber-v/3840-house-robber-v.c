long long rob(int* nums, int numsSize, int* colors, int colorsSize) {
    if (numsSize == 0)
        return 0;

    long long f0 = 0;
    long long f1 = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (colors[i] != colors[i - 1]) {
            f0 = f1;
            f1 += nums[i];
        } else {
            long long temp = f1;
            long long take = f0 + nums[i];
            f1 = take > f1 ? take : f1;
            f0 = temp;
        }
    }

    return f1;
}