#include <string.h>

char* destCity(char*** paths, int pathsSize, int* pathsColSize) {
    for (int i = 0; i < pathsSize; i++) {
        char* destination = paths[i][1];
        int found = 0;

        for (int j = 0; j < pathsSize; j++) {
            if (strcmp(destination, paths[j][0]) == 0) {
                found = 1;
                break;
            }
        }

        if (!found)
            return destination;
    }

    return "";
}