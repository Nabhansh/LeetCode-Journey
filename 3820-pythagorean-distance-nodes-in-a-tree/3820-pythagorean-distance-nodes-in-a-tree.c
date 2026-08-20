#include <stdlib.h>

void bfs(int start, int n, int* head, int* to, int* next, int* dist) {
    int *queue = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        dist[i] = -1;

    int front = 0, rear = 0;

    queue[rear++] = start;
    dist[start] = 0;

    while (front < rear) {
        int u = queue[front++];

        for (int e = head[u]; e != -1; e = next[e]) {
            int v = to[e];

            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                queue[rear++] = v;
            }
        }
    }

    free(queue);
}

int specialNodes(int n, int** edges, int edgesSize, int* edgesColSize,
                 int x, int y, int z) {
    int *head = malloc(n * sizeof(int));
    int *to = malloc(2 * edgesSize * sizeof(int));
    int *next = malloc(2 * edgesSize * sizeof(int));

    for (int i = 0; i < n; i++)
        head[i] = -1;

    int idx = 0;

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        to[idx] = v;
        next[idx] = head[u];
        head[u] = idx++;

        to[idx] = u;
        next[idx] = head[v];
        head[v] = idx++;
    }

    int *dx = malloc(n * sizeof(int));
    int *dy = malloc(n * sizeof(int));
    int *dz = malloc(n * sizeof(int));

    bfs(x, n, head, to, next, dx);
    bfs(y, n, head, to, next, dy);
    bfs(z, n, head, to, next, dz);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        long long a = dx[i];
        long long b = dy[i];
        long long c = dz[i];

        long long temp;

        if (a > b) {
            temp = a;
            a = b;
            b = temp;
        }

        if (b > c) {
            temp = b;
            b = c;
            c = temp;
        }

        if (a > b) {
            temp = a;
            a = b;
            b = temp;
        }

        if (a * a + b * b == c * c)
            ans++;
    }

    free(head);
    free(to);
    free(next);
    free(dx);
    free(dy);
    free(dz);

    return ans;
}