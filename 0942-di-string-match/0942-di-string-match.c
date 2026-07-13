#include <stdlib.h>
#include <string.h>

int* diStringMatch(char* s, int* returnSize) {
    int n = strlen(s);
    int* answer = (int*)malloc((n + 1) * sizeof(int));

    int low = 0;
    int high = n;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'I') {
            answer[i] = low++;
        } else {
            answer[i] = high--;
        }
    }

    answer[n] = low;
    *returnSize = n + 1;

    return answer;
}