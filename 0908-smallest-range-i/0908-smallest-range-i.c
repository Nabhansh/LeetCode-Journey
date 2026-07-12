int smallestRangeI(int* nums, int numsSize, int k) {
    int minimum = nums[0];
    int maximum = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < minimum) {
            minimum = nums[i];
        }

        if (nums[i] > maximum) {
            maximum = nums[i];
        }
    }

    int answer = maximum - minimum - 2 * k;

    return answer > 0 ? answer : 0;
}