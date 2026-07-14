#include <stdlib.h>
#include <string.h>

char* compressedString(char* word) {
    int n = strlen(word);

    // Maximum compressed size is 2 * n
    char* comp = (char*)malloc((2 * n + 1) * sizeof(char));

    int i = 0;
    int index = 0;

    while (i < n) {
        char ch = word[i];
        int count = 0;

        // Maximum group size is 9
        while (i < n && word[i] == ch && count < 9) {
            count++;
            i++;
        }

        comp[index++] = count + '0';
        comp[index++] = ch;
    }

    comp[index] = '\0';

    return comp;
}