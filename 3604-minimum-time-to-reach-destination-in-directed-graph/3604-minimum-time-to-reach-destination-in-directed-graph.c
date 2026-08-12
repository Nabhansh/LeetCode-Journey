#include <stdlib.h>
#include <limits.h>

typedef struct {
    int to;
    int start;
    int end;
    int next;
} Edge;

typedef struct {
    int node;
    long long time;
} HeapNode;

void swapHeap(HeapNode* a, HeapNode* b) {
    HeapNode t = *a;
    *a = *b;
    *b = t;
}

void pushHeap(HeapNode* heap, int* size, HeapNode x) {
    int i = (*size)++;
    heap[i] = x;

    while (i > 0) {
        int p = (i - 1) / 2;

        if (heap[p].time <= heap[i].time)
            break;

        swapHeap(&heap[p], &heap[i]);
        i = p;
    }
}

HeapNode popHeap(HeapNode* heap, int* size) {
    HeapNode result = heap[0];
    heap[0] = heap[--(*size)];

    int i = 0;

    while (1) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int smallest = i;

        if (l < *size && heap[l].time < heap[smallest].time)
            smallest = l;

        if (r < *size && heap[r].time < heap[smallest].time)
            smallest = r;

        if (smallest == i)
            break;

        swapHeap(&heap[i], &heap[smallest]);
        i = smallest;
    }

    return result;
}

int minTime(int n, int** edges, int edgesSize, int* edgesColSize) {
    if (n == 1)
        return 0;

    int* head = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        head[i] = -1;

    Edge* graph = malloc(edgesSize * sizeof(Edge));

    for (int i = 0; i < edgesSize; i++) {
        graph[i].to = edges[i][1];
        graph[i].start = edges[i][2];
        graph[i].end = edges[i][3];
        graph[i].next = head[edges[i][0]];
        head[edges[i][0]] = i;
    }

    long long* dist = malloc(n * sizeof(long long));

    for (int i = 0; i < n; i++)
        dist[i] = LLONG_MAX;

    HeapNode* heap = malloc((edgesSize + n + 5) * sizeof(HeapNode));

    int heapSize = 0;

    dist[0] = 0;
    pushHeap(heap, &heapSize, (HeapNode){0, 0});

    while (heapSize > 0) {
        HeapNode cur = popHeap(heap, &heapSize);

        int u = cur.node;
        long long time = cur.time;

        if (time != dist[u])
            continue;

        if (u == n - 1) {
            free(head);
            free(graph);
            free(dist);
            free(heap);
            return (int)time;
        }

        for (int e = head[u]; e != -1; e = graph[e].next) {
            long long start = graph[e].start;
            long long end = graph[e].end;

            long long depart = time > start ? time : start;

            if (depart > end)
                continue;

            long long arrive = depart + 1;
            int v = graph[e].to;

            if (arrive < dist[v]) {
                dist[v] = arrive;
                pushHeap(heap, &heapSize, (HeapNode){v, arrive});
            }
        }
    }

    free(head);
    free(graph);
    free(dist);
    free(heap);

    return -1;
}