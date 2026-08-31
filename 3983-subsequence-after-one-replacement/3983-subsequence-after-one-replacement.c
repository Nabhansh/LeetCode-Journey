#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool canMakeSubsequence(char* s, char* t) {
    int m = strlen(s);
    int n = strlen(t);
    int* left = malloc((m + 1) * sizeof(int));
    int* right = malloc((m + 1) * sizeof(int));
    int p = 0;

    left[0] = -1;
    for (int i = 0; i < m; i++) {
        while (p < n && t[p] != s[i]) p++;
        if (p == n) {
            left[i + 1] = n;
        } else {
            left[i + 1] = p++;
        }
    }

    if (left[m] != n) {
        free(left);
        free(right);
        return true;
    }

    p = n - 1;
    right[m] = n;
    for (int i = m - 1; i >= 0; i--) {
        while (p >= 0 && t[p] != s[i]) p--;
        if (p < 0) {
            right[i] = -1;
        } else {
            right[i] = p--;
        }
    }

    for (int i = 0; i < m; i++) {
        if (left[i] != n && right[i + 1] != -1 && left[i] + 1 < right[i + 1]) {
            free(left);
            free(right);
            return true;
        }
    }

    free(left);
    free(right);
    return false;
}