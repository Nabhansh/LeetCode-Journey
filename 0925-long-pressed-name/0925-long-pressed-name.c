#include <stdbool.h>
#include <string.h>

bool isLongPressedName(char* name, char* typed) {
    int i = 0;
    int j = 0;
    int n = strlen(name);
    int m = strlen(typed);

    while (j < m) {
        if (i < n && name[i] == typed[j]) {
            i++;
            j++;
        }
        else if (j > 0 && typed[j] == typed[j - 1]) {
            j++;
        }
        else {
            return false;
        }
    }

    return i == n;
}