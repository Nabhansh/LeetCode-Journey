#include <string.h>
#include <stdbool.h>

bool buddyStrings(char* s, char* goal) {
    if (strlen(s) != strlen(goal))
        return false;

    if (strcmp(s, goal) == 0) {
        int cnt[26] = {0};
        for (int i = 0; s[i]; i++) {
            cnt[s[i] - 'a']++;
            if (cnt[s[i] - 'a'] > 1)
                return true;
        }
        return false;
    }

    int first = -1, second = -1;

    for (int i = 0; s[i]; i++) {
        if (s[i] != goal[i]) {
            if (first == -1)
                first = i;
            else if (second == -1)
                second = i;
            else
                return false;
        }
    }

    return second != -1 &&
           s[first] == goal[second] &&
           s[second] == goal[first];
}