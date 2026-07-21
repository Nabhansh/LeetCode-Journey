#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int v;
    struct Node* next;
} Node;

void dfs(int u, Node** graph, bool* vis) {
    vis[u] = true;
    for (Node* p = graph[u]; p; p = p->next) {
        if (!vis[p->v])
            dfs(p->v, graph, vis);
    }
}

int* remainingMethods(int n, int k, int** invocations, int invocationsSize,
                      int* invocationsColSize, int* returnSize) {
    Node** graph = (Node**)calloc(n, sizeof(Node*));

    for (int i = 0; i < invocationsSize; i++) {
        int u = invocations[i][0];
        int v = invocations[i][1];

        Node* node = (Node*)malloc(sizeof(Node));
        node->v = v;
        node->next = graph[u];
        graph[u] = node;
    }

    bool* suspicious = (bool*)calloc(n, sizeof(bool));
    dfs(k, graph, suspicious);

    // If any outside node points into suspicious set,
    // removal is impossible.
    for (int u = 0; u < n; u++) {
        if (suspicious[u])
            continue;

        for (Node* p = graph[u]; p; p = p->next) {
            if (suspicious[p->v]) {
                int* ans = (int*)malloc(sizeof(int) * n);
                for (int i = 0; i < n; i++)
                    ans[i] = i;
                *returnSize = n;

                for (int i = 0; i < n; i++) {
                    Node* cur = graph[i];
                    while (cur) {
                        Node* t = cur;
                        cur = cur->next;
                        free(t);
                    }
                }
                free(graph);
                free(suspicious);

                return ans;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (!suspicious[i])
            cnt++;

    int* ans = (int*)malloc(sizeof(int) * cnt);
    int idx = 0;

    for (int i = 0; i < n; i++)
        if (!suspicious[i])
            ans[idx++] = i;

    *returnSize = cnt;

    for (int i = 0; i < n; i++) {
        Node* cur = graph[i];
        while (cur) {
            Node* t = cur;
            cur = cur->next;
            free(t);
        }
    }

    free(graph);
    free(suspicious);

    return ans;
}