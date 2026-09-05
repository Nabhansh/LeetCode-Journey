#include <stdlib.h>

long long weightedSum(int* parent, int parentSize, int* nums, int numsSize) {
    int n = parentSize;

    int* head = malloc(n * sizeof(int));
    int* next = malloc(n * sizeof(int));
    int* depth = malloc(n * sizeof(int));
    int* queue = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        head[i] = -1;

    for (int i = 1; i < n; i++) {
        next[i] = head[parent[i]];
        head[parent[i]] = i;
    }

    int front = 0, back = 0;
    queue[back++] = 0;
    depth[0] = 1;

    int h = 1;

    while (front < back) {
        int u = queue[front++];

        for (int v = head[u]; v != -1; v = next[v]) {
            depth[v] = depth[u] + 1;
            if (depth[v] > h)
                h = depth[v];
            queue[back++] = v;
        }
    }

    long long ans = 0;

    for (int i = 0; i < n; i++)
        ans += (long long)nums[i] * (h - depth[i] + 1);

    free(head);
    free(next);
    free(depth);
    free(queue);

    return ans;
}