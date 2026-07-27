#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int cmp(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

bool isPossibleToRearrange(char* s, char* t, int k) {
    int n = strlen(s);
    int len = n / k;

    char **A = (char **)malloc(sizeof(char *) * k);
    char **B = (char **)malloc(sizeof(char *) * k);

    for (int i = 0; i < k; i++) {
        A[i] = (char *)malloc(len + 1);
        B[i] = (char *)malloc(len + 1);

        memcpy(A[i], s + i * len, len);
        memcpy(B[i], t + i * len, len);

        A[i][len] = '\0';
        B[i][len] = '\0';
    }

    qsort(A, k, sizeof(char *), cmp);
    qsort(B, k, sizeof(char *), cmp);

    bool ans = true;
    for (int i = 0; i < k; i++) {
        if (strcmp(A[i], B[i]) != 0) {
            ans = false;
            break;
        }
    }

    for (int i = 0; i < k; i++) {
        free(A[i]);
        free(B[i]);
    }
    free(A);
    free(B);

    return ans;
}