#include <stdlib.h>

int bitLength(int x) {
    int len = 0;
    while (x) {
        len++;
        x >>= 1;
    }
    return len;
}

int concat3(int a, int b, int c) {
    int res = a;
    res = (res << bitLength(b)) | b;
    res = (res << bitLength(c)) | c;
    return res;
}

int maxGoodNumber(int* nums, int numsSize) {
    int p[6][3] = {
        {0,1,2},
        {0,2,1},
        {1,0,2},
        {1,2,0},
        {2,0,1},
        {2,1,0}
    };

    int ans = 0;

    for (int i = 0; i < 6; i++) {
        int val = concat3(
            nums[p[i][0]],
            nums[p[i][1]],
            nums[p[i][2]]
        );
        if (val > ans)
            ans = val;
    }

    return ans;
}