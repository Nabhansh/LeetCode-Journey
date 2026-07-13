long long sumDigitDifferences(int* nums, int numsSize) {
    long long answer = 0;

    int temp = nums[0];
    int digits = 0;

    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    for (int pos = 0; pos < digits; pos++) {
        int count[10] = {0};

        for (int i = 0; i < numsSize; i++) {
            int digit = nums[i] % 10;

            answer += i - count[digit];

            count[digit]++;
            nums[i] /= 10;
        }
    }

    return answer;
}