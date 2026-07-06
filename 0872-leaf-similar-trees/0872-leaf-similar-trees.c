void dfs(struct TreeNode* root, int *arr, int *size) {
    if (!root) return;

    if (!root->left && !root->right) {
        arr[(*size)++] = root->val;
        return;
    }

    dfs(root->left, arr, size);
    dfs(root->right, arr, size);
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int a[200], b[200];
    int sa = 0, sb = 0;

    dfs(root1, a, &sa);
    dfs(root2, b, &sb);

    if (sa != sb) return false;

    for (int i = 0; i < sa; i++)
        if (a[i] != b[i])
            return false;

    return true;
}