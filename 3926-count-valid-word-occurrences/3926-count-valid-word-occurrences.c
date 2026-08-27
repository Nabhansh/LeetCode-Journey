#include <stdlib.h>
#include <string.h>
#include <stdint.h>

static uint64_t getHash(const char *s, int len) {
    uint64_t h = 1469598103934665603ULL;
    for (int i = 0; i < len; i++) {
        h ^= (unsigned char)s[i];
        h *= 1099511628211ULL;
    }
    return h;
}

static int isLetter(char c) {
    return c >= 'a' && c <= 'z';
}

int* countWordOccurrences(char** chunks, int chunksSize, char** queries, int queriesSize, int* returnSize) {
    int total = 0;

    for (int i = 0; i < chunksSize; i++)
        total += (int)strlen(chunks[i]);

    char *s = malloc((total + 1) * sizeof(char));
    int p = 0;

    for (int i = 0; i < chunksSize; i++) {
        int len = (int)strlen(chunks[i]);
        memcpy(s + p, chunks[i], len);
        p += len;
    }

    s[total] = '\0';

    int size = 1;
    while (size < queriesSize * 2)
        size <<= 1;

    if (size < 4)
        size = 4;

    int *table = calloc(size, sizeof(int));
    int *freq = calloc(queriesSize, sizeof(int));

    for (int i = 0; i < queriesSize; i++) {
        int len = (int)strlen(queries[i]);
        uint64_t h = getHash(queries[i], len);
        int pos = (int)(h & (size - 1));

        while (table[pos] != 0) {
            int idx = table[pos] - 1;

            if ((int)strlen(queries[idx]) == len &&
                getHash(queries[idx], len) == h &&
                strcmp(queries[idx], queries[i]) == 0)
                break;

            pos = (pos + 1) & (size - 1);
        }

        if (table[pos] == 0)
            table[pos] = i + 1;
    }

    int i = 0;

    while (i < total) {
        if (!isLetter(s[i])) {
            i++;
            continue;
        }

        int start = i;
        uint64_t h = 1469598103934665603ULL;

        while (i < total) {
            if (isLetter(s[i])) {
                h ^= (unsigned char)s[i];
                h *= 1099511628211ULL;
                i++;
            } else if (
                s[i] == '-' &&
                i > start &&
                i + 1 < total &&
                isLetter(s[i - 1]) &&
                isLetter(s[i + 1])
            ) {
                h ^= (unsigned char)s[i];
                h *= 1099511628211ULL;
                i++;
            } else {
                break;
            }
        }

        int len = i - start;
        int pos = (int)(h & (size - 1));

        while (table[pos] != 0) {
            int idx = table[pos] - 1;

            if ((int)strlen(queries[idx]) == len &&
                getHash(queries[idx], len) == h &&
                strncmp(queries[idx], s + start, len) == 0) {
                freq[idx]++;
                break;
            }

            pos = (pos + 1) & (size - 1);
        }

        while (i < total && !isLetter(s[i]))
            i++;
    }

    int *ans = malloc(queriesSize * sizeof(int));

    for (int q = 0; q < queriesSize; q++) {
        int len = (int)strlen(queries[q]);
        uint64_t h = getHash(queries[q], len);
        int pos = (int)(h & (size - 1));

        while (table[pos] != 0) {
            int idx = table[pos] - 1;

            if ((int)strlen(queries[idx]) == len &&
                getHash(queries[idx], len) == h &&
                strcmp(queries[idx], queries[q]) == 0) {
                ans[q] = freq[idx];
                break;
            }

            pos = (pos + 1) & (size - 1);
        }

        if (table[pos] == 0)
            ans[q] = 0;
    }

    free(s);
    free(table);
    free(freq);

    *returnSize = queriesSize;
    return ans;
}