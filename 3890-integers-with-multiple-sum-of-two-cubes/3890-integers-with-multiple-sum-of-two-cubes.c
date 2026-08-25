#include <stdlib.h>

int compareInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* findGoodIntegers(int n, int* returnSize) {

    /*
       Maximum number of pairs:
       1000 * 1000 / 2 ≈ 500,000
    */

    int* sums = malloc(500000 * sizeof(int));

    int count = 0;

    long long cube[1001];

    for (int i = 0; i <= 1000; i++) {
        cube[i] = 1LL * i * i * i;
    }

    for (int a = 1; a <= 1000; a++) {

        if (cube[a] + cube[a] > n)
            break;

        for (int b = a; b <= 1000; b++) {

            long long sum = cube[a] + cube[b];

            if (sum > n)
                break;

            sums[count++] = (int)sum;
        }
    }

    // Sort all sums
    qsort(sums, count, sizeof(int), compareInt);

    int* answer = malloc(count * sizeof(int));

    *returnSize = 0;

    // Find values occurring at least twice
    for (int i = 0; i < count; ) {

        int j = i + 1;

        while (j < count && sums[j] == sums[i]) {
            j++;
        }

        if (j - i >= 2) {
            answer[(*returnSize)++] = sums[i];
        }

        i = j;
    }

    free(sums);

    return answer;
}