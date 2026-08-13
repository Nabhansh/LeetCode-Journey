#include <stdlib.h>
#include <stdbool.h>

static int *parent;
static int *componentSize;

static int findRoot(int x) {
    if (parent[x] != x)
        parent[x] = findRoot(parent[x]);

    return parent[x];
}

/*
 * When adjacent components of lengths a and b merge, the number
 * of substrings without '*' increases by a * b.
 */
static long long mergeComponents(int a, int b) {
    int rootA = findRoot(a);
    int rootB = findRoot(b);

    if (rootA == rootB)
        return 0;

    if (componentSize[rootA] < componentSize[rootB]) {
        int temporary = rootA;
        rootA = rootB;
        rootB = temporary;
    }

    long long increase =
        (long long)componentSize[rootA] * componentSize[rootB];

    parent[rootB] = rootA;
    componentSize[rootA] += componentSize[rootB];

    return increase;
}

int minTime(char *s, int *order, int orderSize, int k) {
    (void)s;

    int n = orderSize;
    long long totalSubstrings = (long long)n * (n + 1) / 2;

    if ((long long)k > totalSubstrings)
        return -1;

    parent = malloc(n * sizeof(int));
    componentSize = malloc(n * sizeof(int));
    bool *restored = calloc(n, sizeof(bool));

    long long invalidSubstrings = 0;
    int answer = -1;

    for (int t = n - 1; t >= 0; --t) {
        long long validSubstrings =
            totalSubstrings - invalidSubstrings;

        if (validSubstrings >= k)
            answer = t;
        else
            break;

        int position = order[t];

        restored[position] = true;
        parent[position] = position;
        componentSize[position] = 1;

        /* The one-character substring is now invalid. */
        ++invalidSubstrings;

        if (position > 0 && restored[position - 1]) {
            invalidSubstrings +=
                mergeComponents(position, position - 1);
        }

        if (position + 1 < n && restored[position + 1]) {
            invalidSubstrings +=
                mergeComponents(position, position + 1);
        }
    }

    free(parent);
    free(componentSize);
    free(restored);

    return answer;
}