#include <stdlib.h>
#include <string.h>

char* getSmallestString(char* s, int k) {
    int n = strlen(s);
    char* answer = (char*)malloc((n + 1) * sizeof(char));

    strcpy(answer, s);

    for (int i = 0; i < n && k > 0; i++) {
        int direct = answer[i] - 'a';
        int circular = 26 - direct;
        int cost = direct < circular ? direct : circular;

        if (cost <= k) {
            answer[i] = 'a';
            k -= cost;
        } else {
            answer[i] -= k;
            k = 0;
        }
    }

    return answer;
}