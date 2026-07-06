#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 131071

typedef struct Node {
    int key;
    int cnt;
    struct Node *next;
} Node;

Node *table[HASH_SIZE];

unsigned int hash(int x) {
    return ((unsigned int)x * 2654435761u) % HASH_SIZE;
}

Node *findNode(int key) {
    unsigned int h = hash(key);
    Node *cur = table[h];

    while (cur) {
        if (cur->key == key)
            return cur;
        cur = cur->next;
    }

    return NULL;
}

void addNumber(int key) {
    unsigned int h = hash(key);

    Node *cur = table[h];

    while (cur) {
        if (cur->key == key) {
            cur->cnt++;
            return;
        }
        cur = cur->next;
    }

    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->cnt = 1;
    node->next = table[h];
    table[h] = node;
}

void clearTable() {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node *cur = table[i];

        while (cur) {
            Node *tmp = cur;
            cur = cur->next;
            free(tmp);
        }

        table[i] = NULL;
    }
}

int isPrime(int x) {
    if (x < 2)
        return 0;

    if (x % 2 == 0)
        return x == 2;

    for (int i = 3; (long long)i * i <= x; i += 2)
        if (x % i == 0)
            return 0;

    return 1;
}

int dr[8] = {-1,-1,-1,0,0,1,1,1};
int dc[8] = {-1,0,1,-1,1,-1,0,1};

int mostFrequentPrime(int** mat, int matSize, int* matColSize) {

    clearTable();

    int m = matSize;
    int n = matColSize[0];

    for (int r = 0; r < m; r++) {

        for (int c = 0; c < n; c++) {

            for (int d = 0; d < 8; d++) {

                int x = r;
                int y = c;

                int val = 0;

                while (x >= 0 && x < m && y >= 0 && y < n) {

                    val = val * 10 + mat[x][y];

                    if (val > 10 && isPrime(val))
                        addNumber(val);

                    x += dr[d];
                    y += dc[d];
                }
            }
        }
    }

    int ans = -1;
    int best = 0;

    for (int i = 0; i < HASH_SIZE; i++) {

        Node *cur = table[i];

        while (cur) {

            if (cur->cnt > best ||
               (cur->cnt == best && cur->key > ans)) {

                best = cur->cnt;
                ans = cur->key;
            }

            cur = cur->next;
        }
    }

    clearTable();

    return ans;
}