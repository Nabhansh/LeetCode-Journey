int minimumDeletions(int* nums, int numsSize) {

    int minIdx = 0;
    int maxIdx = 0;

    for(int i = 1; i < numsSize; i++) {

        if(nums[i] < nums[minIdx])
            minIdx = i;

        if(nums[i] > nums[maxIdx])
            maxIdx = i;
    }

    if(minIdx > maxIdx) {

        int temp = minIdx;
        minIdx = maxIdx;
        maxIdx = temp;
    }

    int option1 = maxIdx + 1;

    int option2 = numsSize - minIdx;

    int option3 =
        (minIdx + 1) + (numsSize - maxIdx);

    int ans = option1;

    if(option2 < ans)
        ans = option2;

    if(option3 < ans)
        ans = option3;

    return ans;
}