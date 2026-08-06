#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

typedef struct Edge {
    int target;
    long long factor;
    struct Edge* next;
} Edge;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* baseUnitConversions(int** conversions, int conversionsSize, int* conversionsColSize, int* returnSize) {
    // Total units = conversionsSize + 1
    int n = conversionsSize + 1;
    *returnSize = n;

    // Allocate memory for graph adjacency head pointers and edge pool
    Edge** head = (Edge**)calloc(n, sizeof(Edge*));
    Edge* edgePool = (Edge*)malloc(conversionsSize * sizeof(Edge));

    // Build Adjacency List Graph using contiguous edge pool
    for (int i = 0; i < conversionsSize; ++i) {
        int u = conversions[i][0];
        int v = conversions[i][1];
        long long factor = (long long)conversions[i][2];

        edgePool[i].target = v;
        edgePool[i].factor = factor;
        edgePool[i].next = head[u];
        head[u] = &edgePool[i];
    }

    // Allocate result array and initialize base unit 0 to 1
    int* ans = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        ans[i] = 0;
    }
    ans[0] = 1;

    // Fast linear queue for BFS traversal
    int* queue = (int*)malloc(n * sizeof(int));
    int front = 0, rear = 0;

    queue[rear++] = 0; // Push root unit 0

    while (front < rear) {
        int u = queue[front++];

        for (Edge* e = head[u]; e != NULL; e = e->next) {
            int v = e->target;
            ans[v] = (int)(((long long)ans[u] * e->factor) % MOD);
            queue[rear++] = v;
        }
    }

    // Clean up temporary memory
    free(head);
    free(edgePool);
    free(queue);

    return ans;
}