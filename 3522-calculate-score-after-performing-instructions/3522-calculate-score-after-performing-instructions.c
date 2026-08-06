#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

long long calculateScore(char** instructions, int instructionsSize, int* values, int valuesSize) {
    long long score = 0;
    int i = 0;
    
    bool* seen = (bool*)calloc(instructionsSize, sizeof(bool));
    if (seen == NULL) return 0; // Memory allocation failed

    while (i >= 0 && i < instructionsSize && !seen[i]) {
        seen[i] = true;
        if (strcmp(instructions[i], "add") == 0) {
            score += values[i];
            i += 1;
        } else if (strcmp(instructions[i], "jump") == 0) {
            i += values[i];
        }
    }
    
    free(seen);
    return score;
}
