#include <stdlib.h>

long long minOperations(int* nums1, int nums1Size,
                        int* nums2, int nums2Size)
{
    long long ans = 1;
    int target = nums2[nums1Size];

    int possible = 0;
    int minDist = 2147483647;

    for (int i = 0; i < nums1Size; i++)
    {
        int x = nums1[i];
        int y = nums2[i];

        if (x > y)
        {
            int temp = x;
            x = y;
            y = temp;
        }

        ans += y - x;

        int d1 = abs(x - target);
        int d2 = abs(y - target);

        if (d1 < minDist)
            minDist = d1;

        if (d2 < minDist)
            minDist = d2;

        if (target >= x && target <= y)
            possible = 1;
    }

    if (!possible)
        ans += minDist;

    return ans;
}