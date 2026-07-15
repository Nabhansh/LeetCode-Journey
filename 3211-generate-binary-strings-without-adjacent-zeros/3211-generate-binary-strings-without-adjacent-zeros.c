#include <stdlib.h>

void generate(char** result, int* returnSize, char* current,
              int position, int n) {
    if (position == n) {
        current[n] = '\0';

        result[*returnSize] = (char*)malloc((n + 1) * sizeof(char));

        for (int i = 0; i <= n; i++) {
            result[*returnSize][i] = current[i];
        }

        (*returnSize)++;
        return;
    }

    current[position] = '1';
    generate(result, returnSize, current, position + 1, n);

    if (position == 0 || current[position - 1] != '0') {
        current[position] = '0';
        generate(result, returnSize, current, position + 1, n);
    }
}

char** validStrings(int n, int* returnSize) {
    int maxSize = 1 << n;

    char** result = (char**)malloc(maxSize * sizeof(char*));
    char* current = (char*)malloc((n + 1) * sizeof(char));

    *returnSize = 0;

    generate(result, returnSize, current, 0, n);

    free(current);

    return result;
}