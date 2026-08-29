#include <stdlib.h>

int maxDistance(char* moves) {
    int x = 0;
    int y = 0;
    int unknown = 0;

    for (int i = 0; moves[i] != '\0'; i++) {
        if (moves[i] == 'U') {
            y++;
        }
        else if (moves[i] == 'D') {
            y--;
        }
        else if (moves[i] == 'L') {
            x--;
        }
        else if (moves[i] == 'R') {
            x++;
        }
        else {
            unknown++;
        }
    }

    return abs(x) + abs(y) + unknown;
}