#include <limits.h>
#include <stdlib.h>

#define HASH_SIZE 262144

typedef struct Node {
    long long key;
    long long value;
    struct Node *next;
} Node;

Node *table[HASH_SIZE];

unsigned int hash(long long x) {
    unsigned long long h = (unsigned long long)x;
    h ^= h >> 33;
    h *= 0xff51afd7ed558ccdULL;
    h ^= h >> 33;
    return (unsigned int)(h & (HASH_SIZE - 1));
}

Node* find(long long key) {
    unsigned int h = hash(key);
    Node *cur = table[h];
    while (cur) {
        if (cur->key == key)
            return cur;
        cur = cur->next;
    }
    return NULL;
}

void insert_or_update(long long key, long long value) {
    unsigned int h = hash(key);
    Node *cur = table[h];

    while (cur) {
        if (cur->key == key) {
            if (value < cur->value)
                cur->value = value;
            return;
        }
        cur = cur->next;
    }

    Node *node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
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

long long maximumSubarraySum(int* nums, int numsSize, int k) {
    clearTable();

    long long prefix = 0;
    long long ans = LLONG_MIN;

    for (int i = 0; i < numsSize; i++) {

        insert_or_update(nums[i], prefix);

        prefix += nums[i];

        Node *p = find((long long)nums[i] - k);
        if (p && prefix - p->value > ans)
            ans = prefix - p->value;

        p = find((long long)nums[i] + k);
        if (p && prefix - p->value > ans)
            ans = prefix - p->value;
    }

    clearTable();

    return ans == LLONG_MIN ? 0 : ans;
}