#include <limits.h>

int minOperations(int k) {
    int ans = INT_MAX;

    for (int val = 1; val <= k; val++) {
        int inc = val - 1;
        int dup = (k + val - 1) / val - 1; // ceil(k / val) - 1
        if (inc + dup < ans)
            ans = inc + dup;
    }

    return ans;
}