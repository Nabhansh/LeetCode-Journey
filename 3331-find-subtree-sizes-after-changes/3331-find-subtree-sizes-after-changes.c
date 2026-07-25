typedef struct Node {
    int to;
    struct Node *next;
} Node;

Node **graph;
int *ans;
int last[26][100005];
int top[26];

void addEdge(int u, int v) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->to = v;
    node->next = graph[u];
    graph[u] = node;
}

void dfs(int u, int parent, char *s) {
    ans[u] = 1;

    int c = s[u] - 'a';
    last[c][top[c]++] = u;

    Node *cur = graph[u];
    while (cur) {
        dfs(cur->to, u, s);
        cur = cur->next;
    }

    int target;
    if (top[c] > 1)
        target = last[c][top[c] - 2];
    else
        target = parent;

    if (target != -1)
        ans[target] += ans[u];

    top[c]--;
}

int* findSubtreeSizes(int* parent, int parentSize, char* s, int* returnSize) {
    int n = parentSize;
    *returnSize = n;

    graph = (Node **)calloc(n, sizeof(Node *));
    ans = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < 26; i++)
        top[i] = 0;

    for (int i = 1; i < n; i++)
        addEdge(parent[i], i);

    dfs(0, -1, s);

    return ans;
}