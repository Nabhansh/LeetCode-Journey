#include <stdlib.h>

long long numberOfPairs(int* nums1, int nums1Size,
                        int* nums2, int nums2Size, int k) {
    
    int maxVal = 0;

    // Find maximum value in nums1
    for (int i = 0; i < nums1Size; i++) {
        if (nums1[i] > maxVal) {
            maxVal = nums1[i];
        }
    }

    // Frequency array for nums1
    int* freq1 = (int*)calloc(maxVal + 1, sizeof(int));

    for (int i = 0; i < nums1Size; i++) {
        freq1[nums1[i]]++;
    }

    /*
     * After nums2[j] is multiplied by k,
     * only values <= maxVal can contribute.
     *
     * So nums2[j] only needs to be <= maxVal / k.
     */
    int maxNum2 = maxVal / k;

    int* freq2 = (int*)calloc(maxNum2 + 1, sizeof(int));

    for (int i = 0; i < nums2Size; i++) {
        if (nums2[i] <= maxNum2) {
            freq2[nums2[i]]++;
        }
    }

    long long answer = 0;

    // Process each unique nums2 value only once
    for (int value = 1; value <= maxNum2; value++) {

        if (freq2[value] == 0) {
            continue;
        }

        long long divisor = (long long)value * k;
        long long validNums1 = 0;

        // Check all multiples of divisor
        for (long long multiple = divisor;
             multiple <= maxVal;
             multiple += divisor) {

            validNums1 += freq1[multiple];
        }

        answer += validNums1 * freq2[value];
    }

    free(freq1);
    free(freq2);

    return answer;
}