#include <stdlib.h>
#include <string.h>

typedef struct {
    int len;        // Length of this segment
    int prefix;     // Longest equal-character prefix
    int suffix;     // Longest equal-character suffix
    int best;       // Longest repeating substring
    char leftChar;
    char rightChar;
} Node;

static Node mergeNodes(Node left, Node right) {
    Node result;

    result.len = left.len + right.len;
    result.leftChar = left.leftChar;
    result.rightChar = right.rightChar;

    result.prefix = left.prefix;
    if (left.prefix == left.len &&
        left.rightChar == right.leftChar) {
        result.prefix = left.len + right.prefix;
    }

    result.suffix = right.suffix;
    if (right.suffix == right.len &&
        left.rightChar == right.leftChar) {
        result.suffix = right.len + left.suffix;
    }

    result.best = left.best > right.best
                    ? left.best
                    : right.best;

    if (left.rightChar == right.leftChar) {
        int crossing = left.suffix + right.prefix;

        if (crossing > result.best) {
            result.best = crossing;
        }
    }

    return result;
}

static void buildTree(Node *tree, const char *s,
                      int node, int start, int end) {
    if (start == end) {
        tree[node].len = 1;
        tree[node].prefix = 1;
        tree[node].suffix = 1;
        tree[node].best = 1;
        tree[node].leftChar = s[start];
        tree[node].rightChar = s[start];
        return;
    }

    int mid = start + (end - start) / 2;

    buildTree(tree, s, node * 2, start, mid);
    buildTree(tree, s, node * 2 + 1, mid + 1, end);

    tree[node] = mergeNodes(tree[node * 2],
                            tree[node * 2 + 1]);
}

static void updateTree(Node *tree, int node,
                       int start, int end,
                       int index, char newChar) {
    if (start == end) {
        tree[node].leftChar = newChar;
        tree[node].rightChar = newChar;
        return;
    }

    int mid = start + (end - start) / 2;

    if (index <= mid) {
        updateTree(tree, node * 2, start, mid,
                   index, newChar);
    } else {
        updateTree(tree, node * 2 + 1, mid + 1, end,
                   index, newChar);
    }

    tree[node] = mergeNodes(tree[node * 2],
                            tree[node * 2 + 1]);
}

/**
 * Note: The returned array must be malloced; assume caller calls free().
 */
int *longestRepeating(char *s,
                      char *queryCharacters,
                      int *queryIndices,
                      int queryIndicesSize,
                      int *returnSize) {
    int n = (int)strlen(s);
    int *answer = malloc(sizeof(int) * queryIndicesSize);

    *returnSize = queryIndicesSize;

    if (n == 0) {
        return answer;
    }

    Node *tree = malloc(sizeof(Node) * (4 * n));

    buildTree(tree, s, 1, 0, n - 1);

    for (int i = 0; i < queryIndicesSize; ++i) {
        updateTree(tree, 1, 0, n - 1,
                   queryIndices[i],
                   queryCharacters[i]);

        answer[i] = tree[1].best;
    }

    free(tree);
    return answer;
}