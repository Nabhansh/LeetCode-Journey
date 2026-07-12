long long countAlternatingSubarrays(int* nums, int numsSize) {
    long long answer = 1;
    long long length = 1;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            length++;
        } else {
            length = 1;
        }

        answer += length;
    }

    return answer;
}