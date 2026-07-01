#include <stdlib.h>

typedef struct {
    int first;
    int last;
    int count;
    int used;
} Info;

int findShortestSubArray(int* nums, int numsSize) {
    Info arr[50000] = {0};

    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        if (!arr[x].used) {
            arr[x].used = 1;
            arr[x].first = i;
        }
        arr[x].last = i;
        arr[x].count++;
    }

    int degree = 0, ans = numsSize;
    for (int i = 0; i < 50000; i++) {
        if (arr[i].used) {
            if (arr[i].count > degree) {
                degree = arr[i].count;
                ans = arr[i].last - arr[i].first + 1;
            } else if (arr[i].count == degree) {
                int len = arr[i].last - arr[i].first + 1;
                if (len < ans) ans = len;
            }
        }
    }
    return ans;
}