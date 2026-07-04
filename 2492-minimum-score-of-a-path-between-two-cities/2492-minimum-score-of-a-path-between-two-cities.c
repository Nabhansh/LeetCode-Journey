int minScore(int n, int** roads, int roadsSize, int* roadsColSize) {
    int *vis = calloc(n + 1, sizeof(int));

    int **g = malloc((n + 1) * sizeof(int *));
    int *deg = calloc(n + 1, sizeof(int));

    for (int i = 0; i < roadsSize; i++) {
        deg[roads[i][0]]++;
        deg[roads[i][1]]++;
    }

    for (int i = 1; i <= n; i++) {
        g[i] = malloc(deg[i] * 2 * sizeof(int));
        deg[i] = 0;
    }

    for (int i = 0; i < roadsSize; i++) {
        int u = roads[i][0], v = roads[i][1], d = roads[i][2];
        g[u][deg[u]++] = v;
        g[u][deg[u]++] = d;
        g[v][deg[v]++] = u;
        g[v][deg[v]++] = d;
    }

    int *q = malloc((n + 1) * sizeof(int));
    int front = 0, rear = 0;
    q[rear++] = 1;
    vis[1] = 1;

    int ans = INT_MAX;

    while (front < rear) {
        int u = q[front++];

        for (int i = 0; i < deg[u]; i += 2) {
            int v = g[u][i];
            int d = g[u][i + 1];

            if (d < ans) ans = d;

            if (!vis[v]) {
                vis[v] = 1;
                q[rear++] = v;
            }
        }
    }

    return ans;
}