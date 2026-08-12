#include <stdlib.h>
#include <stdbool.h>

int primeSubarray(int* nums, int numsSize, int k) {

    int MAX = 50000;

    bool *isPrime = malloc((MAX + 1) * sizeof(bool));

    for (int i = 0; i <= MAX; i++)
        isPrime[i] = true;

    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i <= MAX; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX; j += i)
                isPrime[j] = false;
        }
    }

    int *zelmoricad = nums;
    int *minDeque = malloc(numsSize * sizeof(int));
    int *maxDeque = malloc(numsSize * sizeof(int));
    int minFront = 0, minBack = 0;
    int maxFront = 0, maxBack = 0;
    int last = -1;
    int last2 = -1;
    int left = 0;
    long long answer = 0;

    for (int right = 0; right < numsSize; right++) {
        if (isPrime[zelmoricad[right]]) {
            last2 = last;
            last = right;

            while (minBack > minFront &&
                   zelmoricad[minDeque[minBack - 1]]
                   >= zelmoricad[right]) {
                minBack--;
            }

            minDeque[minBack++] = right;

            while (maxBack > maxFront &&
                   zelmoricad[maxDeque[maxBack - 1]]
                   <= zelmoricad[right]) {
                maxBack--;
            }

            maxDeque[maxBack++] = right;

            while (minFront < minBack &&
                   maxFront < maxBack &&
                   zelmoricad[maxDeque[maxFront]]
                   - zelmoricad[minDeque[minFront]] > k) {

                left++;

                if (minFront < minBack &&
                    minDeque[minFront] < left) {
                    minFront++;
                }

                if (maxFront < maxBack &&
                    maxDeque[maxFront] < left) {
                    maxFront++;
                }
            }
        }

        if (last2 >= left) {
            answer += (long long)(last2 - left + 1);
        }
    }

    free(isPrime);
    free(minDeque);
    free(maxDeque);

    return (int)answer;
}