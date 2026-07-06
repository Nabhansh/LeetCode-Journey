#include <string.h>

bool backspaceCompare(char* s, char* t) {
    int i = strlen(s) - 1;
    int j = strlen(t) - 1;

    while (1) {
        int skip = 0;
        while (i >= 0) {
            if (s[i] == '#') {
                skip++;
                i--;
            } else if (skip) {
                skip--;
                i--;
            } else break;
        }

        skip = 0;
        while (j >= 0) {
            if (t[j] == '#') {
                skip++;
                j--;
            } else if (skip) {
                skip--;
                j--;
            } else break;
        }

        if (i < 0 || j < 0)
            return i == j;

        if (s[i] != t[j])
            return false;

        i--;
        j--;
    }
}