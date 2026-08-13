#include <stdlib.h>

static int *parent;
static int *dsuSize;

static int findRoot(int x) {
    if (parent[x] != x)
        parent[x] = findRoot(parent[x]);
    return parent[x];
}

static int unite(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);

    if (a == b)
        return 0;

    if (dsuSize[a] < dsuSize[b]) {
        int temp = a;
        a = b;
        b = temp;
    }

    parent[b] = a;
    dsuSize[a] += dsuSize[b];
    return 1;
}

static int compareEdges(const void *p1, const void *p2) {
    int *a = *(int **)p1;
    int *b = *(int **)p2;

    return (a[2] > b[2]) - (a[2] < b[2]);
}

int minCost(int n, int **edges, int edgesSize,
            int *edgesColSize, int k) {
    (void)edgesColSize;

    if (k >= n)
        return 0;

    qsort(edges, edgesSize, sizeof(int *), compareEdges);

    parent = malloc(n * sizeof(int));
    dsuSize = malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        dsuSize[i] = 1;
    }

    int components = n;
    int answer = 0;

    for (int i = 0; i < edgesSize && components > k; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        if (unite(u, v)) {
            answer = weight;
            --components;
        }
    }

    free(parent);
    free(dsuSize);

    return answer;
}