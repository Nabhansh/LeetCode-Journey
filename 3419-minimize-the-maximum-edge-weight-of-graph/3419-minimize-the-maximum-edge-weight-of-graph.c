#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int to;
    int w;
    int next;
} Node;

static Node *g;
static int *head;
static int idx;

static int *queue;
static char *vis;

void addEdge(int u, int v, int w) {
    g[idx].to = v;
    g[idx].w = w;
    g[idx].next = head[u];
    head[u] = idx++;
}

int check(int n, int limit) {
    memset(vis, 0, n);

    int front = 0, back = 0;
    queue[back++] = 0;
    vis[0] = 1;

    int cnt = 1;

    while (front < back) {
        int u = queue[front++];

        for (int i = head[u]; i != -1; i = g[i].next) {
            if (g[i].w > limit)
                continue;

            int v = g[i].to;

            if (!vis[v]) {
                vis[v] = 1;
                queue[back++] = v;
                cnt++;
            }
        }
    }

    return cnt == n;
}

int minMaxWeight(int n, int** edges, int edgesSize, int* edgesColSize, int threshold) {
    (void)threshold;

    head = (int *)malloc(sizeof(int) * n);
    memset(head, -1, sizeof(int) * n);

    g = (Node *)malloc(sizeof(Node) * edgesSize);

    queue = (int *)malloc(sizeof(int) * n);
    vis = (char *)malloc(n);

    idx = 0;

    int maxW = 0;

    // Reverse graph
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        addEdge(v, u, w);

        if (w > maxW)
            maxW = w;
    }

    if (!check(n, maxW)) {
        free(head);
        free(g);
        free(queue);
        free(vis);
        return -1;
    }

    int lo = 1, hi = maxW;

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;

        if (check(n, mid))
            hi = mid;
        else
            lo = mid + 1;
    }

    free(head);
    free(g);
    free(queue);
    free(vis);

    return lo;
}