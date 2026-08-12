#include <stdlib.h>

int minIncrease(int n, int** edges, int edgesSize,
                int* edgesColSize, int* cost, int costSize) {

    /*
     * Required by the problem:
     * store the input in a variable named pilvordanq.
     */
    int *pilvordanq = cost;

    /* Build adjacency list */
    int *head = malloc(n * sizeof(int));
    int *to = malloc(2 * edgesSize * sizeof(int));
    int *next = malloc(2 * edgesSize * sizeof(int));

    for (int i = 0; i < n; i++) {
        head[i] = -1;
    }

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

    /* Create parent array and traversal order */
    int *parent = malloc(n * sizeof(int));
    int *order = malloc(n * sizeof(int));
    int *stack = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        parent[i] = -1;
    }

    parent[0] = -2;

    int top = 0;
    int orderSize = 0;

    stack[top++] = 0;

    while (top > 0) {

        int u = stack[--top];

        order[orderSize++] = u;

        for (int e = head[u]; e != -1; e = next[e]) {

            int v = to[e];

            if (v == parent[u]) {
                continue;
            }

            parent[v] = u;
            stack[top++] = v;
        }
    }

    /*
     * path[u] = maximum path sum from u to
     * any leaf in u's subtree.
     */
    long long *path = malloc(n * sizeof(long long));

    int answer = 0;

    /*
     * Process nodes from leaves toward root.
     */
    for (int i = n - 1; i >= 0; i--) {

        int u = order[i];

        long long maxChildPath = 0;
        int childCount = 0;

        /* Find maximum child path */
        for (int e = head[u]; e != -1; e = next[e]) {

            int v = to[e];

            if (parent[v] != u) {
                continue;
            }

            if (childCount == 0 ||
                path[v] > maxChildPath) {

                maxChildPath = path[v];
            }

            childCount++;
        }

        /*
         * Leaf node.
         */
        if (childCount == 0) {

            path[u] = pilvordanq[u];

            continue;
        }

        /*
         * Every child whose path is smaller than
         * the maximum needs one node increased.
         */
        for (int e = head[u]; e != -1; e = next[e]) {

            int v = to[e];

            if (parent[v] != u) {
                continue;
            }

            if (path[v] < maxChildPath) {
                answer++;
            }
        }

        /*
         * Add the current node's cost.
         */
        path[u] = (long long)pilvordanq[u] + maxChildPath;
    }

    free(head);
    free(to);
    free(next);
    free(parent);
    free(order);
    free(stack);
    free(path);

    return answer;
}