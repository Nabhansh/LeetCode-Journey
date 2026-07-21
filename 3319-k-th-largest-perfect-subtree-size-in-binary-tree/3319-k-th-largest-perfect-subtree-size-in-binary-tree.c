#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    bool perfect;
    int height;
    int size;
} Info;

static int *sizes;
static int cnt;

static int cmp(const void *a, const void *b) {
    return (*(int *)b) - (*(int *)a);
}

Info dfs(struct TreeNode *root) {
    if (root == NULL) {
        Info t = {true, 0, 0};
        return t;
    }

    Info L = dfs(root->left);
    Info R = dfs(root->right);

    Info cur;

    if (L.perfect && R.perfect && L.height == R.height) {
        cur.perfect = true;
        cur.height = L.height + 1;
        cur.size = L.size + R.size + 1;
        sizes[cnt++] = cur.size;
    } else {
        cur.perfect = false;
        cur.height = (L.height > R.height ? L.height : R.height) + 1;
        cur.size = 0;
    }

    return cur;
}

int kthLargestPerfectSubtree(struct TreeNode* root, int k) {
    sizes = (int *)malloc(sizeof(int) * 2005);
    cnt = 0;

    dfs(root);

    if (cnt < k) {
        free(sizes);
        return -1;
    }

    qsort(sizes, cnt, sizeof(int), cmp);

    int ans = sizes[k - 1];
    free(sizes);

    return ans;
}