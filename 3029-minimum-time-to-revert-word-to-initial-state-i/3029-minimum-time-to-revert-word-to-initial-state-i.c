#include <string.h>

int minimumTimeToInitialState(char* word, int k) {
    int n = strlen(word);

    for (int i = k, t = 1; i < n; i += k, t++) {
        if (strncmp(word, word + i, n - i) == 0) {
            return t;
        }
    }

    return (n + k - 1) / k;
}