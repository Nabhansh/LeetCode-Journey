#include <stdlib.h>
#include <stdbool.h>

int dfs(int u, int p, int **g, int *sz, int *deg, int *ans) {
    sz[u] = 1;
    int childSize = -1;
    bool ok = true;

    for (int i = 0; i < deg[u]; i++) {
        int v = g[u][i];
        if (v == p) continue;

        dfs(v, u, g, sz, deg, ans);

        if (childSize == -1)
            childSize = sz[v];
        else if (childSize != sz[v])
            ok = false;

        sz[u] += sz[v];
    }

    if (ok) (*ans)++;
    return sz[u];
}

int countGoodNodes(int** edges, int edgesSize, int* edgesColSize) {
    int n = edgesSize + 1;

    int *deg = calloc(n, sizeof(int));

    for (int i = 0; i < edgesSize; i++) {
        deg[edges[i][0]]++;
        deg[edges[i][1]]++;
    }

    int **g = malloc(n * sizeof(int *));
    int *idx = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
        g[i] = malloc(deg[i] * sizeof(int));

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        g[u][idx[u]++] = v;
        g[v][idx[v]++] = u;
    }

    int *sz = calloc(n, sizeof(int));
    int ans = 0;

    dfs(0, -1, g, sz, deg, &ans);

    return ans;
}