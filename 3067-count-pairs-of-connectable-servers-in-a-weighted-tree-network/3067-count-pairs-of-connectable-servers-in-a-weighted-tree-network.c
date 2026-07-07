#include <stdlib.h>

typedef struct Edge {
    int to;
    int w;
    struct Edge *next;
} Edge;

static void dfs(Edge **graph, int u, int parent, long long dist,
                int signalSpeed, int *cnt) {
    if (dist % signalSpeed == 0)
        (*cnt)++;

    for (Edge *e = graph[u]; e; e = e->next) {
        if (e->to == parent) continue;
        dfs(graph, e->to, u, dist + e->w, signalSpeed, cnt);
    }
}

int* countPairsOfConnectableServers(int** edges, int edgesSize,
                                    int* edgesColSize,
                                    int signalSpeed,
                                    int* returnSize) {
    int n = edgesSize + 1;
    *returnSize = n;

    Edge **graph = (Edge **)calloc(n, sizeof(Edge*));

    // Build graph
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        Edge *a = (Edge *)malloc(sizeof(Edge));
        a->to = v;
        a->w = w;
        a->next = graph[u];
        graph[u] = a;

        Edge *b = (Edge *)malloc(sizeof(Edge));
        b->to = u;
        b->w = w;
        b->next = graph[v];
        graph[v] = b;
    }

    int *ans = (int *)calloc(n, sizeof(int));

    for (int c = 0; c < n; c++) {
        long long prefix = 0;

        for (Edge *e = graph[c]; e; e = e->next) {
            int cnt = 0;
            dfs(graph, e->to, c, e->w, signalSpeed, &cnt);

            ans[c] += prefix * cnt;
            prefix += cnt;
        }
    }

    // Free graph
    for (int i = 0; i < n; i++) {
        Edge *cur = graph[i];
        while (cur) {
            Edge *tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }
    free(graph);

    return ans;
}