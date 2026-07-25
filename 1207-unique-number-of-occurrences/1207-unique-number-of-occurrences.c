#include <stdbool.h>
#include <string.h>

bool uniqueOccurrences(int* arr, int arrSize) {
    int freq[2001] = {0};

    for (int i = 0; i < arrSize; i++)
        freq[arr[i] + 1000]++;

    bool used[1001] = {0};

    for (int i = 0; i < 2001; i++) {
        if (freq[i]) {
            if (used[freq[i]])
                return false;
            used[freq[i]] = true;
        }
    }

    return true;
}