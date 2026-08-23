int scoreDifference(int* nums, int numsSize) {
    int score = 0;
    int sign = 1;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] & 1)
            sign = -sign;

        if (i % 6 == 5)
            sign = -sign;

        score += sign * nums[i];
    }

    return score;
}