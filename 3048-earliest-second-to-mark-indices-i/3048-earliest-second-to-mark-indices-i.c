#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static bool canMark(int* nums, int n,
                    int* changeIndices, int second) {
    int* last = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        last[i] = -1;

    for (int i = 0; i < second; i++)
        last[changeIndices[i] - 1] = i;

    int marked = 0;
    long long dec = 0;

    for (int i = 0; i < second; i++) {
        int idx = changeIndices[i] - 1;

        if (last[idx] == i) {
            if (nums[idx] > dec) {
                free(last);
                return false;
            }
            dec -= nums[idx];
            marked++;
        } else {
            dec++;
        }
    }

    free(last);
    return marked == n;
}

int earliestSecondToMarkIndices(int* nums, int numsSize,
                                int* changeIndices,
                                int changeIndicesSize) {
    int l = 1;
    int r = changeIndicesSize;
    int ans = -1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (canMark(nums, numsSize, changeIndices, mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return ans;
}