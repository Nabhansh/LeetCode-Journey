#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    int to;
    int w;
    int next;
} Edge;

static int cmpEdge(const void *a, const void *b) {
    long long x = *(const long long *)a;
    long long y = *(const long long *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

static bool check(int **edges, int edgesSize, bool *online, int n, long long k, int limit) {
    int *head = (int *)malloc(sizeof(int) * n);
    int *indeg = (int *)calloc(n, sizeof(int));
    Edge *g = (Edge *)malloc(sizeof(Edge) * (edgesSize + 1));

    for (int i = 0; i < n; i++) head[i] = -1;

    int idx = 0;
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        if (w < limit) continue;
        if (u != 0 && !online[u]) continue;
        if (v != n - 1 && !online[v]) continue;

        g[idx].to = v;
        g[idx].w = w;
        g[idx].next = head[u];
        head[u] = idx++;
        indeg[v]++;
    }

    int *q = (int *)malloc(sizeof(int) * n);
    int front = 0, back = 0;

    for (int i = 0; i < n; i++)
        if (indeg[i] == 0)
            q[back++] = i;

    int *topo = (int *)malloc(sizeof(int) * n);
    int t = 0;

    while (front < back) {
        int u = q[front++];
        topo[t++] = u;
        for (int e = head[u]; e != -1; e = g[e].next) {
            int v = g[e].to;
            indeg[v]--;
            if (indeg[v] == 0)
                q[back++] = v;
        }
    }

    long long INF = LLONG_MAX / 4;
    long long *dist = (long long *)malloc(sizeof(long long) * n);

    for (int i = 0; i < n; i++)
        dist[i] = INF;
    dist[0] = 0;

    for (int i = 0; i < t; i++) {
        int u = topo[i];
        if (dist[u] == INF) continue;

        for (int e = head[u]; e != -1; e = g[e].next) {
            int v = g[e].to;
            long long nd = dist[u] + (long long)g[e].w;
            if (nd < dist[v])
                dist[v] = nd;
        }
    }

    bool ok = (dist[n - 1] <= k);

    free(head);
    free(indeg);
    free(g);
    free(q);
    free(topo);
    free(dist);

    return ok;
}

int findMaxPathScore(int **edges, int edgesSize, int *edgesColSize,
                     bool *online, int onlineSize, long long k) {
    if (edgesSize == 0) return -1;

    long long *vals = (long long *)malloc(sizeof(long long) * edgesSize);
    for (int i = 0; i < edgesSize; i++)
        vals[i] = edges[i][2];

    qsort(vals, edgesSize, sizeof(long long), cmpEdge);

    int m = 0;
    for (int i = 0; i < edgesSize; i++) {
        if (i == 0 || vals[i] != vals[i - 1])
            vals[m++] = vals[i];
    }

    int lo = 0, hi = m - 1;
    int ans = -1;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int limit = (int)vals[mid];

        if (check(edges, edgesSize, online, onlineSize, k, limit)) {
            ans = limit;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    free(vals);
    return ans;
}