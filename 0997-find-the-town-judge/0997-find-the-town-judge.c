#include <stdlib.h>

int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    int* score = (int*)calloc(n + 1, sizeof(int));

    for (int i = 0; i < trustSize; i++) {
        int a = trust[i][0];
        int b = trust[i][1];

        score[a]--;
        score[b]++;
    }

    for (int person = 1; person <= n; person++) {
        if (score[person] == n - 1) {
            free(score);
            return person;
        }
    }

    free(score);
    return -1;
}