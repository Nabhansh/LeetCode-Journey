#include <string.h>

int maxScore(char* s) {
    int n = strlen(s);
    int ones = 0;

    for (int i = 0; i < n; i++)
        if (s[i] == '1')
            ones++;

    int zeros = 0;
    int maxScore = 0;

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '0')
            zeros++;
        else
            ones--;

        if (zeros + ones > maxScore)
            maxScore = zeros + ones;
    }

    return maxScore;
}