long long maximumTotalCost(int* nums, int numsSize) {
    long long plus = nums[0];
    long long minus = -1000000000000000000LL;

    for (int i = 1; i < numsSize; i++) {
        long long newPlus = (plus > minus ? plus : minus) + nums[i];
        long long newMinus = plus - nums[i];

        plus = newPlus;
        minus = newMinus;
    }

    return plus > minus ? plus : minus;
}