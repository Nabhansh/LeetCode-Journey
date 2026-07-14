#include <stdlib.h>

int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
    int capacity = numSize + 12;
    int* temp = (int*)malloc(capacity * sizeof(int));

    int index = 0;
    int i = numSize - 1;

    while (i >= 0 || k > 0) {
        if (i >= 0) {
            k += num[i];
            i--;
        }

        temp[index++] = k % 10;
        k /= 10;
    }

    /*
     * If k becomes 0 while digits of num still remain,
     * copy those remaining digits.
     */
    while (i >= 0) {
        temp[index++] = num[i--];
    }

    int* answer = (int*)malloc(index * sizeof(int));

    for (int j = 0; j < index; j++) {
        answer[j] = temp[index - 1 - j];
    }

    free(temp);

    *returnSize = index;
    return answer;
}