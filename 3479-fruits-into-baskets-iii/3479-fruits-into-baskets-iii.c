#include <stdlib.h>

int *tree;
int N;

int max(int a, int b)
{
    return a > b ? a : b;
}

void build(int node, int l, int r, int *basket)
{
    if (l == r)
    {
        tree[node] = basket[l];
        return;
    }

    int mid = (l + r) / 2;

    build(node * 2, l, mid, basket);
    build(node * 2 + 1, mid + 1, r, basket);

    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

void update(int node, int l, int r, int idx)
{
    if (l == r)
    {
        tree[node] = -1;
        return;
    }

    int mid = (l + r) / 2;

    if (idx <= mid)
        update(node * 2, l, mid, idx);
    else
        update(node * 2 + 1, mid + 1, r, idx);

    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int query(int node, int l, int r, int need)
{
    if (tree[node] < need)
        return -1;

    if (l == r)
        return l;

    int mid = (l + r) / 2;

    if (tree[node * 2] >= need)
        return query(node * 2, l, mid, need);

    return query(node * 2 + 1, mid + 1, r, need);
}

int numOfUnplacedFruits(int* fruits, int fruitsSize,
                        int* baskets, int basketsSize)
{
    N = basketsSize;

    tree = (int *)malloc(sizeof(int) * (4 * N + 5));

    build(1, 0, N - 1, baskets);

    int unplaced = 0;

    for (int i = 0; i < fruitsSize; i++)
    {
        int idx = query(1, 0, N - 1, fruits[i]);

        if (idx == -1)
        {
            unplaced++;
        }
        else
        {
            update(1, 0, N - 1, idx);
        }
    }

    free(tree);

    return unplaced;
}