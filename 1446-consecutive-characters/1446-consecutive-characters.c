#include <string.h>

int maxPower(char* s) {
    int max = 1;
    int count = 1;
    int n = strlen(s);

    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1])
            count++;
        else
            count = 1;

        if (count > max)
            max = count;
    }

    return max;
}