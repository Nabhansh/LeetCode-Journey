#include <stdlib.h>
#include <limits.h>

int compare(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    return (x > y) - (x < y);
}

int minimumAddedInteger(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);

    int answer = INT_MAX;

    // Try matching nums2[0] with nums1[0], nums1[1], or nums1[2].
    // Since exactly two elements are removed, one of these must remain.
    for (int start = 0; start < 3; start++) {
        int x = nums2[0] - nums1[start];

        int i = 0;
        int j = 0;
        int removed = 0;

        while (i < nums1Size && j < nums2Size) {
            if (nums1[i] + x == nums2[j]) {
                i++;
                j++;
            } else {
                i++;
                removed++;
            }

            if (removed > 2) {
                break;
            }
        }

        removed += nums1Size - i;

        if (j == nums2Size && removed == 2) {
            if (x < answer) {
                answer = x;
            }
        }
    }

    return answer;
}