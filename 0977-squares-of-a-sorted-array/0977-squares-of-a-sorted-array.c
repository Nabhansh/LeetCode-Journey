#include <stdlib.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* answer = (int*)malloc(numsSize * sizeof(int));

    int left = 0;
    int right = numsSize - 1;
    int index = numsSize - 1;

    while (left <= right) {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];

        if (leftSquare > rightSquare) {
            answer[index--] = leftSquare;
            left++;
        } else {
            answer[index--] = rightSquare;
            right--;
        }
    }

    *returnSize = numsSize;
    return answer;
}