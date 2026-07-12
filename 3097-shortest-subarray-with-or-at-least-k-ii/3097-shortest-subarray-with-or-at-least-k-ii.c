int minimumSubarrayLength(int* nums, int numsSize, int k) {
    int count[32] = {0};
    int left = 0;
    int currentOR = 0;
    int answer = numsSize + 1;

    for (int right = 0; right < numsSize; right++) {
        currentOR |= nums[right];

        for (int bit = 0; bit < 32; bit++) {
            if ((nums[right] >> bit) & 1) {
                count[bit]++;
            }
        }

        while (left <= right && currentOR >= k) {
            int length = right - left + 1;

            if (length < answer) {
                answer = length;
            }

            for (int bit = 0; bit < 32; bit++) {
                if ((nums[left] >> bit) & 1) {
                    count[bit]--;

                    if (count[bit] == 0) {
                        currentOR &= ~(1 << bit);
                    }
                }
            }

            left++;
        }
    }

    return answer == numsSize + 1 ? -1 : answer;
}