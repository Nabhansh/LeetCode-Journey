#include <stdbool.h>

bool stoneGameIX(int* stones, int stonesSize) {
    
    int cnt[3] = {0};

    for (int i = 0; i < stonesSize; i++) {
        cnt[stones[i] % 3]++;
    }

    // If count of remainder 0 is even
    if (cnt[0] % 2 == 0) {
        return (cnt[1] > 0 && cnt[2] > 0);
    }

    // If count of remainder 0 is odd
    return (cnt[1] - cnt[2] > 2 || cnt[2] - cnt[1] > 2);
}