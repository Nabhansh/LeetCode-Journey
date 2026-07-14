#include <stdlib.h>

typedef struct {
    int key;
    int value;
    int used;
} HashEntry;

#define HASH_SIZE 262147

int hash(int key) {
    return ((unsigned int)key) % HASH_SIZE;
}

int get(HashEntry* map, int key) {
    int index = hash(key);

    while (map[index].used) {
        if (map[index].key == key) {
            return map[index].value;
        }

        index = (index + 1) % HASH_SIZE;
    }

    return 0;
}

void set(HashEntry* map, int key, int value) {
    int index = hash(key);

    while (map[index].used && map[index].key != key) {
        index = (index + 1) % HASH_SIZE;
    }

    map[index].used = 1;
    map[index].key = key;
    map[index].value = value;
}

int* queryResults(int limit, int** queries, int queriesSize,
                  int* queriesColSize, int* returnSize) {

    int* ballColor = (int*)calloc(limit + 1, sizeof(int));

    HashEntry* colorCount =
        (HashEntry*)calloc(HASH_SIZE, sizeof(HashEntry));

    int* answer = (int*)malloc(queriesSize * sizeof(int));

    int distinct = 0;

    for (int i = 0; i < queriesSize; i++) {

        int ball = queries[i][0];
        int newColor = queries[i][1];

        // Remove the ball's previous color
        if (ballColor[ball] != 0) {

            int oldColor = ballColor[ball];
            int oldCount = get(colorCount, oldColor);

            if (oldCount == 1) {
                distinct--;
            }

            set(colorCount, oldColor, oldCount - 1);
        }

        // Add the new color
        int newCount = get(colorCount, newColor);

        if (newCount == 0) {
            distinct++;
        }

        set(colorCount, newColor, newCount + 1);

        ballColor[ball] = newColor;

        answer[i] = distinct;
    }

    free(ballColor);
    free(colorCount);

    *returnSize = queriesSize;

    return answer;
}