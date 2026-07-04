#include <stdlib.h>
#include <stdbool.h>

#define MAXV 100000

int minimumOperationsToMakeEqual(int x, int y) {
    if (x <= y)
        return y - x;

    int limit = x * 2 + 20;
    if (limit < MAXV) limit = MAXV;

    bool *vis = calloc(limit + 1, sizeof(bool));
    int *q = malloc((limit + 5) * sizeof(int));

    int front = 0, rear = 0;
    q[rear++] = x;
    vis[x] = true;

    int steps = 0;

    while (front < rear) {
        int sz = rear - front;

        while (sz--) {
            int cur = q[front++];

            if (cur == y) {
                free(vis);
                free(q);
                return steps;
            }

            int nxt[4];
            int cnt = 0;

            nxt[cnt++] = cur - 1;
            nxt[cnt++] = cur + 1;

            if (cur % 5 == 0)
                nxt[cnt++] = cur / 5;
            if (cur % 11 == 0)
                nxt[cnt++] = cur / 11;

            for (int i = 0; i < cnt; i++) {
                int v = nxt[i];
                if (v >= 0 && v <= limit && !vis[v]) {
                    vis[v] = true;
                    q[rear++] = v;
                }
            }
        }
        steps++;
    }

    free(vis);
    free(q);
    return -1;
}