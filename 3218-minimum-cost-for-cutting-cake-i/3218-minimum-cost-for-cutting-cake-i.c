#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)b - *(int *)a); // Descending order
}

long long minimumCost(int m, int n, int* horizontalCut, int horizontalCutSize,
                      int* verticalCut, int verticalCutSize) {

    qsort(horizontalCut, horizontalCutSize, sizeof(int), cmp);
    qsort(verticalCut, verticalCutSize, sizeof(int), cmp);

    long long ans = 0;
    int i = 0, j = 0;
    int hPieces = 1, vPieces = 1;

    while (i < horizontalCutSize && j < verticalCutSize) {
        if (horizontalCut[i] > verticalCut[j]) {
            ans += 1LL * horizontalCut[i] * vPieces;
            hPieces++;
            i++;
        } else {
            ans += 1LL * verticalCut[j] * hPieces;
            vPieces++;
            j++;
        }
    }

    while (i < horizontalCutSize) {
        ans += 1LL * horizontalCut[i] * vPieces;
        i++;
    }

    while (j < verticalCutSize) {
        ans += 1LL * verticalCut[j] * hPieces;
        j++;
    }

    return ans;
}