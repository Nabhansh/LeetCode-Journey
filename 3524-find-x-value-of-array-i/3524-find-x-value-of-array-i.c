#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* resultArray(int* nums, int numsSize, int k, int* returnSize) {
    long long* ans = (long long*)calloc(k, sizeof(long long));
    long long* dp = (long long*)calloc(k, sizeof(long long));
    long long* next_dp = (long long*)calloc(k, sizeof(long long));
    
    *returnSize = k;

    for (int i = 0; i < numsSize; ++i) {
        memset(next_dp, 0, k * sizeof(long long));
        int val = nums[i] % k;
        
        // Single-element subarray starting at index i
        next_dp[val]++;
        
        // Extend existing subarrays
        for (int r = 0; r < k; ++r) {
            if (dp[r] > 0) {
                int next_rem = (r * val) % k;
                next_dp[next_rem] += dp[r];
            }
        }
        
        // Add current counts to final result
        for (int r = 0; r < k; ++r) {
            ans[r] += next_dp[r];
            dp[r] = next_dp[r];
        }
    }

    free(dp);
    free(next_dp);
    return ans;
}