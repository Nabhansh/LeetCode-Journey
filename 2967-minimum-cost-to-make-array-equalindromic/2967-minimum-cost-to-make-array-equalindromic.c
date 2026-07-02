#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}

int isPal(int x) {
    char s[20];
    sprintf(s, "%d", x);
    int l = 0, r = strlen(s) - 1;
    while (l < r) {
        if (s[l++] != s[r--])
            return 0;
    }
    return 1;
}

long long cost(int *nums, int n, int p) {
    long long ans = 0;
    for (int i = 0; i < n; i++)
        ans += llabs((long long)nums[i] - p);
    return ans;
}

long long minimumCost(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int med = nums[numsSize / 2];

    int down = med;
    while (!isPal(down))
        down--;

    int up = med;
    while (!isPal(up))
        up++;

    long long c1 = cost(nums, numsSize, down);
    long long c2 = cost(nums, numsSize, up);

    return c1 < c2 ? c1 : c2;
}