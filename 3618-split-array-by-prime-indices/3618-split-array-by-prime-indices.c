#include <stdlib.h>
#include <stdbool.h>

long long splitArray(int *nums, int numsSize) {
    bool *isPrime = malloc(numsSize * sizeof(bool));

    for (int i = 0; i < numsSize; ++i)
        isPrime[i] = true;

    if (numsSize > 0)
        isPrime[0] = false;
    if (numsSize > 1)
        isPrime[1] = false;

    for (int i = 2; (long long)i * i < numsSize; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j < numsSize; j += i)
                isPrime[j] = false;
        }
    }

    long long difference = 0;

    for (int i = 0; i < numsSize; ++i) {
        if (isPrime[i])
            difference += nums[i];
        else
            difference -= nums[i];
    }

    free(isPrime);

    return difference < 0 ? -difference : difference;
}