#include <stdlib.h>
#include <string.h>

int* fairCandySwap(int* aliceSizes, int aliceSizesSize, int* bobSizes, int bobSizesSize, int* returnSize) {
    int sumA = 0, sumB = 0;
    for (int i = 0; i < aliceSizesSize; i++) sumA += aliceSizes[i];
    for (int i = 0; i < bobSizesSize; i++) sumB += bobSizes[i];
    
    int delta = (sumB - sumA) / 2;
    
    bool* bobSet = (bool*)calloc(100001, sizeof(bool));
    for (int i = 0; i < bobSizesSize; i++) {
        bobSet[bobSizes[i]] = true;
    }
    
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    for (int i = 0; i < aliceSizesSize; i++) {
        int x = aliceSizes[i];
        int y = x + delta;
        if (y >= 1 && y <= 100000 && bobSet[y]) {
            result[0] = x;
            result[1] = y;
            break;
        }
    }
    
    free(bobSet);
    return result;
}