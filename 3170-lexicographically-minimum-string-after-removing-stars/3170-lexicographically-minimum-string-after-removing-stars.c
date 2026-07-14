#include <stdlib.h>
#include <string.h>

char* clearStars(char* s) {

    int n = strlen(s);

    int** positions = (int**)malloc(26 * sizeof(int*));
    int* sizes = (int*)calloc(26, sizeof(int));

    for (int i = 0; i < 26; i++) {
        positions[i] = (int*)malloc(n * sizeof(int));
    }

    int* removed = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {

        if (s[i] != '*') {
            int c = s[i] - 'a';

            positions[c][sizes[c]++] = i;
        } else {

            removed[i] = 1;

            for (int c = 0; c < 26; c++) {

                if (sizes[c] > 0) {

                    int index = positions[c][--sizes[c]];

                    removed[index] = 1;

                    break;
                }
            }
        }
    }

    char* answer = (char*)malloc((n + 1) * sizeof(char));
    int index = 0;

    for (int i = 0; i < n; i++) {
        if (!removed[i]) {
            answer[index++] = s[i];
        }
    }

    answer[index] = '\0';

    for (int i = 0; i < 26; i++) {
        free(positions[i]);
    }

    free(positions);
    free(sizes);
    free(removed);

    return answer;
}