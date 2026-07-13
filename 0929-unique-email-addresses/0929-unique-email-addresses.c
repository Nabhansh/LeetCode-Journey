#include <string.h>
#include <stdlib.h>

int numUniqueEmails(char** emails, int emailsSize) {
    char** unique = (char**)malloc(emailsSize * sizeof(char*));
    int uniqueCount = 0;

    for (int i = 0; i < emailsSize; i++) {
        char normalized[101];
        int index = 0;
        int j = 0;

        while (emails[i][j] != '@') {
            if (emails[i][j] == '+') {
                while (emails[i][j] != '@') {
                    j++;
                }
                break;
            }

            if (emails[i][j] != '.') {
                normalized[index++] = emails[i][j];
            }

            j++;
        }

        while (emails[i][j] != '\0') {
            normalized[index++] = emails[i][j++];
        }

        normalized[index] = '\0';

        int found = 0;

        for (int k = 0; k < uniqueCount; k++) {
            if (strcmp(unique[k], normalized) == 0) {
                found = 1;
                break;
            }
        }

        if (!found) {
            unique[uniqueCount] = (char*)malloc((index + 1) * sizeof(char));
            strcpy(unique[uniqueCount], normalized);
            uniqueCount++;
        }
    }

    for (int i = 0; i < uniqueCount; i++) {
        free(unique[i]);
    }

    free(unique);

    return uniqueCount;
}