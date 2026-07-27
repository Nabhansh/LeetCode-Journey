#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int v;
    struct Node *next;
} Node;

static void addEdge(Node **graph, int u, int v) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->v = v;
    p->next = graph[u];
    graph[u] = p;
}

static int bfs(Node **graph, int n, int start, int limit) {
    if (limit < 0)
        return 0;

    int *queue = (int *)malloc(sizeof(int) * n);
    int *dist = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        dist[i] = -1;

    int front = 0, rear = 0;

    queue[rear++] = start;
    dist[start] = 0;

    int count = 0;

    while (front < rear) {
        int u = queue[front++];

        if (dist[u] > limit)
            continue;

        count++;

        for (Node *p = graph[u]; p; p = p->next) {
            if (dist[p->v] == -1) {
                dist[p->v] = dist[u] + 1;
                queue[rear++] = p->v;
            }
        }
    }

    free(queue);
    free(dist);

    return count;
}

int* maxTargetNodes(int** edges1, int edges1Size, int* edges1ColSize,
                    int** edges2, int edges2Size, int* edges2ColSize,
                    int k, int* returnSize) {

    int n = edges1Size + 1;
    int m = edges2Size + 1;

    Node **g1 = (Node **)calloc(n, sizeof(Node *));
    Node **g2 = (Node **)calloc(m, sizeof(Node *));

    for (int i = 0; i < edges1Size; i++) {
        int u = edges1[i][0];
        int v = edges1[i][1];
        addEdge(g1, u, v);
        addEdge(g1, v, u);
    }

    for (int i = 0; i < edges2Size; i++) {
        int u = edges2[i][0];
        int v = edges2[i][1];
        addEdge(g2, u, v);
        addEdge(g2, v, u);
    }

    int *cnt1 = (int *)malloc(sizeof(int) * n);
    int best = 0;

    for (int i = 0; i < m; i++) {
        int x = bfs(g2, m, i, k - 1);
        if (x > best)
            best = x;
    }

    for (int i = 0; i < n; i++)
        cnt1[i] = bfs(g1, n, i, k);

    int *ans = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        ans[i] = cnt1[i] + best;

    *returnSize = n;

    return ans;
}