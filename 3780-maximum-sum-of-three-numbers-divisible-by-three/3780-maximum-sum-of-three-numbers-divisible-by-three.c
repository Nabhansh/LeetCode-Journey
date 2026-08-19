int maximumSum(int* nums, int numsSize) {
    int top[3][3] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};
    
    for (int i = 0; i < numsSize; i++) {
        int r = nums[i] % 3;
        
        if (nums[i] > top[r][0]) {
            top[r][2] = top[r][1];
            top[r][1] = top[r][0];
            top[r][0] = nums[i];
        } else if (nums[i] > top[r][1]) {
            top[r][2] = top[r][1];
            top[r][1] = nums[i];
        } else if (nums[i] > top[r][2]) {
            top[r][2] = nums[i];
        }
    }

    int ans = 0;

    if (top[0][2] != -1)
        ans = top[0][0] + top[0][1] + top[0][2];

    if (top[1][2] != -1) {
        int sum = top[1][0] + top[1][1] + top[1][2];
        if (sum > ans) ans = sum;
    }

    if (top[2][2] != -1) {
        int sum = top[2][0] + top[2][1] + top[2][2];
        if (sum > ans) ans = sum;
    }

    if (top[0][0] != -1 && top[1][0] != -1 && top[2][0] != -1) {
        int sum = top[0][0] + top[1][0] + top[2][0];
        if (sum > ans) ans = sum;
    }

    return ans;
}