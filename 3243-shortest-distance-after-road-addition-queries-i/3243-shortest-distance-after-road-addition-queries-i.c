#include <stdlib.h>

int* shortestDistanceAfterQueries(int n, int** queries, int queriesSize,
                                  int* queriesColSize, int* returnSize) {
    int **adj = (int **)malloc(n * sizeof(int *));
    int *deg = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        adj[i] = (int *)malloc((n + queriesSize) * sizeof(int));
        adj[i][deg[i]++] = i + 1;
    }
    deg[n - 1] = 0;

    int *ans = (int *)malloc(queriesSize * sizeof(int));
    int *dist = (int *)malloc(n * sizeof(int));
    int *q = (int *)malloc(n * sizeof(int));

    for (int k = 0; k < queriesSize; k++) {
        int u = queries[k][0];
        int v = queries[k][1];
        adj[u][deg[u]++] = v;

        for (int i = 0; i < n; i++) dist[i] = -1;

        int front = 0, back = 0;
        q[back++] = 0;
        dist[0] = 0;

        while (front < back) {
            int cur = q[front++];
            if (cur == n - 1) break;

            for (int i = 0; i < deg[cur]; i++) {
                int nxt = adj[cur][i];
                if (dist[nxt] == -1) {
                    dist[nxt] = dist[cur] + 1;
                    q[back++] = nxt;
                }
            }
        }
        ans[k] = dist[n - 1];
    }

    *returnSize = queriesSize;
    return ans;
}