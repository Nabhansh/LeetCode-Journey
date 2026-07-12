#include <stdlib.h>
#include <limits.h>

typedef struct {
    int node;
    int dist;
} HeapNode;

typedef struct {
    HeapNode* data;
    int size;
} MinHeap;

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void push(MinHeap* heap, int node, int dist) {
    int i = heap->size++;

    heap->data[i].node = node;
    heap->data[i].dist = dist;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap->data[parent].dist <= heap->data[i].dist) {
            break;
        }

        swap(&heap->data[parent], &heap->data[i]);
        i = parent;
    }
}

HeapNode pop(MinHeap* heap) {
    HeapNode result = heap->data[0];

    heap->size--;
    heap->data[0] = heap->data[heap->size];

    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < heap->size &&
            heap->data[left].dist < heap->data[smallest].dist) {
            smallest = left;
        }

        if (right < heap->size &&
            heap->data[right].dist < heap->data[smallest].dist) {
            smallest = right;
        }

        if (smallest == i) {
            break;
        }

        swap(&heap->data[i], &heap->data[smallest]);
        i = smallest;
    }

    return result;
}

int* minimumTime(int n, int** edges, int edgesSize,
                 int* edgesColSize, int* disappear,
                 int disappearSize, int* returnSize) {

    int* degree = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < edgesSize; i++) {
        degree[edges[i][0]]++;
        degree[edges[i][1]]++;
    }

    int** adj = (int**)malloc(n * sizeof(int*));
    int** weight = (int**)malloc(n * sizeof(int*));
    int* index = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(degree[i] * sizeof(int));
        weight[i] = (int*)malloc(degree[i] * sizeof(int));
    }

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u][index[u]] = v;
        weight[u][index[u]++] = w;

        adj[v][index[v]] = u;
        weight[v][index[v]++] = w;
    }

    int* dist = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }

    dist[0] = 0;

    MinHeap heap;
    heap.data = (HeapNode*)malloc((edgesSize * 2 + n + 1)
                                  * sizeof(HeapNode));
    heap.size = 0;

    push(&heap, 0, 0);

    while (heap.size > 0) {
        HeapNode current = pop(&heap);

        int u = current.node;
        int currentDist = current.dist;

        if (currentDist != dist[u]) {
            continue;
        }

        for (int i = 0; i < degree[u]; i++) {
            int v = adj[u][i];
            int newDist = currentDist + weight[u][i];

            if (newDist < dist[v] && newDist < disappear[v]) {
                dist[v] = newDist;
                push(&heap, v, newDist);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            dist[i] = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        free(adj[i]);
        free(weight[i]);
    }

    free(adj);
    free(weight);
    free(degree);
    free(index);
    free(heap.data);

    *returnSize = n;
    return dist;
}